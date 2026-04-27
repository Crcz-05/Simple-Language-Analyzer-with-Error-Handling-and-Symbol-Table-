%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "symbol_table.h"

void yyerror(const char *s);
int yylex(void);

extern int line_no;   /* ✅ from lexer */

ASTNode* root;
char currentType[20];

int syntaxError = 0;   /* ✅ track syntax errors */
%}

%code requires {
#include "ast.h"
}

/* ================= UNION ================= */
%union {
    int num;
    char* str;
    ASTNode* node;
}

/* ================= TOKENS ================= */
%token <num> NUMBER FLOAT_NUMBER
%token <str> ID STRING
%token STRING_TYPE

%token INT FLOAT CHAR BOOL VOID 
%token IF ELSE WHILE FOR RETURN

%token EQ NE LE GE ASSIGN 
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token OR AND NOT LSHIFT RSHIFT INC DEC

/* ================= TYPES ================= */
%type <node> program external_list external function parameter_list parameter
%type <node> declaration init_list init statement statement_list
%type <node> compound_statement expression assignment_expression
%type <node> additive_expression multiplicative_expression unary_expression
%type <node> primary_expression argument_list
%type <node> expression_statement selection_statement iteration_statement jump_statement

/* ================= PRECEDENCE ================= */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left OR
%left AND
%left '|'
%left '^'
%left '&'
%left EQ NE
%left '<' '>' LE GE
%left LSHIFT RSHIFT
%left '+' '-'
%left '*' '/' '%'
%right NOT
%right UMINUS
%right INC DEC

%%

/* ================= PROGRAM ================= */
program
    : external_list { root = $1; }
    ;

/* ================= LIST ================= */
external_list
    : external_list external {
        $$ = createStatementList($1, $2);
    }
    | external { $$ = $1; }
    ;

external
    : function
    | declaration ';'
    ;

/* ================= FUNCTION ================= */
function
    : type ID '(' parameter_list ')' compound_statement {
        insertSymbol($2, "function");
        $$ = $6;
    }
    | type ID '(' ')' compound_statement {
        insertSymbol($2, "function");
        $$ = $5;
    }
    ;

/* ================= PARAMETERS ================= */
parameter_list
    : parameter_list ',' parameter {
        $$ = createStatementList($1, $3);
    }
    | parameter { $$ = $1; }
    ;

parameter
    : type ID {
        insertSymbol($2, currentType);
        $$ = createDeclaration($2, NULL);
    }
    ;

/* ================= TYPE ================= */
type
    : INT   { strcpy(currentType, "int"); }
    | FLOAT { strcpy(currentType, "float"); }
    | CHAR  { strcpy(currentType, "char"); }
    | BOOL  { strcpy(currentType, "bool"); }
    | VOID  { strcpy(currentType, "void"); }
    | STRING_TYPE { strcpy(currentType, "string"); }
    ;

/* ================= DECLARATION ================= */
declaration
    : type init_list { $$ = $2; }
    ;

init_list
    : init_list ',' init {
        $$ = createStatementList($1, $3);
    }
    | init { $$ = $1; }
    ;

init
    : ID {
        if (searchSymbol($1) != -1)
            printf("Semantic Warning: Redeclaration of %s\n", $1);

        insertSymbol($1, currentType);
        $$ = createDeclaration($1, NULL);
    }
    | ID ASSIGN expression {
        if (searchSymbol($1) != -1)
            printf("Semantic Warning: Redeclaration of %s\n", $1);

        insertSymbol($1, currentType);
        $$ = createDeclaration($1, $3);
    }
    ;

/* ================= STATEMENTS ================= */
statement
    : expression_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement { $$ = $1; }
    | declaration ';' { $$ = $1; }
    ;

compound_statement
    : '{' statement_list '}' { $$ = $2; }
    | '{' '}' { $$ = NULL; }
    ;

statement_list
    : statement_list statement { $$ = createStatementList($1, $2); }
    | statement { $$ = $1; }
    ;

/* ================= EXPRESSIONS ================= */
expression_statement
    : expression ';' { $$ = $1; }
    | ';' { $$ = NULL; }
    ;

selection_statement
    : IF '(' expression ')' statement %prec LOWER_THAN_ELSE { $$ = $3; }
    | IF '(' expression ')' statement ELSE statement { $$ = $3; }
    ;

iteration_statement
    : WHILE '(' expression ')' statement { $$ = $3; }
    | FOR '(' expression_statement expression_statement expression ')' statement { $$ = $3; }
    ;

jump_statement
    : RETURN expression ';' { $$ = $2; }
    | RETURN ';' { $$ = NULL; }
    ;

expression
    : assignment_expression
    ;

/* ================= ASSIGNMENT ================= */
assignment_expression
    : ID ASSIGN assignment_expression {
        if (searchSymbol($1) == -1)
            printf("Semantic Error at line %d: Undeclared variable %s\n", line_no, $1);

        $$ = createBinary('=', createIdentifier($1), $3);
    }

    | ID '(' argument_list ')' {
        if (searchSymbol($1) == -1) {
            if (strcmp($1, "printf") == 0 || strcmp($1, "scanf") == 0)
                insertSymbol($1, "function");
            else
                printf("Semantic Error at line %d: Function %s not declared\n", line_no, $1);
        }
        $$ = createFunctionCall($1, $3);
    }

    | additive_expression { $$ = $1; }
    ;

/* ================= ARITHMETIC ================= */
additive_expression
    : additive_expression '+' multiplicative_expression {
        $$ = createBinary('+', $1, $3);
    }
    | additive_expression '-' multiplicative_expression {
        $$ = createBinary('-', $1, $3);
    }
    | multiplicative_expression { $$ = $1; }
    ;

multiplicative_expression
    : multiplicative_expression '*' unary_expression {
        $$ = createBinary('*', $1, $3);
    }
    | multiplicative_expression '/' unary_expression {
        $$ = createBinary('/', $1, $3);
    }
    | multiplicative_expression '%' unary_expression {
        $$ = createBinary('%', $1, $3);
    }
    | unary_expression { $$ = $1; }
    ;

unary_expression
    : '-' unary_expression %prec UMINUS {
        $$ = createBinary('~', $2, NULL);
    }
    | primary_expression { $$ = $1; }
    ;

/* ================= PRIMARY ================= */
primary_expression
    : NUMBER { $$ = createNumber($1); }
    | FLOAT_NUMBER { $$ = createNumber($1); }
    | STRING { $$ = createString($1); }

    | ID {
        if (searchSymbol($1) == -1)
            printf("Semantic Error at line %d: Undeclared variable %s\n", line_no, $1);

        $$ = createIdentifier($1);
    }

    | '&' ID {
        if (searchSymbol($2) == -1)
            printf("Semantic Error at line %d: Undeclared variable %s\n", line_no, $2);

        $$ = createBinary('&', createIdentifier($2), NULL);
    }

    | '(' expression ')' { $$ = $2; }
;

/* ================= ARGUMENTS ================= */
argument_list
    : argument_list ',' expression {
        $$ = createArgumentList($1, $3);
    }
    | expression { $$ = $1; }
    ;

%%

/* ================= ERROR ================= */
void yyerror(const char *s)
{
    syntaxError = 1;
    printf("Syntax Error at line %d: %s\n", line_no, s);
}

/* ================= MAIN ================= */
int main()
{
    printf("\n========== COMPILATION STARTED ==========\n");

    printf("\n--- LEXICAL ANALYSIS ---\n\n");

    int result = yyparse();

    if (result == 0 && syntaxError == 0) {

        printf("\n✔ Lexical Analysis Completed\n");

        printf("\n--- SYNTAX ANALYSIS ---\n");
        printf("✔ No Syntax Errors\n");

        printf("\n--- SEMANTIC ANALYSIS ---\n");
        printf("✔ Completed Successfully\n");

        printf("\n--- PARSE TREE ---\n\n");
        if (root)
            printAST(root);

        printf("\n--- SYMBOL TABLE ---\n");
        displaySymbolTable();

        printf("\n========== COMPILATION SUCCESSFUL ==========\n");
    }
    else {
        printf("\n--- SYNTAX ANALYSIS ---\n");
        printf("✖ Compilation Failed due to Syntax Errors\n");

        printf("\n========== COMPILATION FAILED ==========\n");
    }

    return 0;
}