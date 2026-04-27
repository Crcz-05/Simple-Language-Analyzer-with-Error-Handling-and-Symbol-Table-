%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_no = 1;

void print_token(char *type, char *value) {
    printf("  %-15s : %s\n", type, value);
}
%}

%option noyywrap

DIGIT   [0-9]
LETTER  [a-zA-Z]

%%

"#".*                        ;

"=="                         { print_token("OPERATOR", yytext); return EQ; }
"!="                         { print_token("OPERATOR", yytext); return NE; }
"<="                         { print_token("OPERATOR", yytext); return LE; }
">="                         { print_token("OPERATOR", yytext); return GE; }
"="                          { print_token("OPERATOR", yytext); return ASSIGN; }

"+"                          { print_token("OPERATOR", yytext); return '+'; }
"-"                          { print_token("OPERATOR", yytext); return '-'; }
"*"                          { print_token("OPERATOR", yytext); return '*'; }
"/"                          { print_token("OPERATOR", yytext); return '/'; }
"%"                          { print_token("OPERATOR", yytext); return '%'; }
"&"                          { print_token("OPERATOR", yytext); return '&'; }

"("                          { print_token("SEPARATOR", yytext); return '('; }
")"                          { print_token("SEPARATOR", yytext); return ')'; }
"{"                          { print_token("SEPARATOR", yytext); return '{'; }
"}"                          { print_token("SEPARATOR", yytext); return '}'; }
";"                          { print_token("SEPARATOR", yytext); return ';'; }
","                          { print_token("SEPARATOR", yytext); return ','; }

"int"                        { print_token("KEYWORD", yytext); return INT; }
"float"                      { print_token("KEYWORD", yytext); return FLOAT; }
"char"                       { print_token("KEYWORD", yytext); return CHAR; }
"void"                       { print_token("KEYWORD", yytext); return VOID; }
"string"                     { print_token("KEYWORD", yytext); return STRING_TYPE; }

"if"                         { print_token("KEYWORD", yytext); return IF; }
"else"                       { print_token("KEYWORD", yytext); return ELSE; }
"while"                      { print_token("KEYWORD", yytext); return WHILE; }
"return"                     { print_token("KEYWORD", yytext); return RETURN; }

\"[^\"]*\"                   {
                                yylval.str = strdup(yytext);
                                print_token("STRING", yytext);
                                return STRING;
                             }

{DIGIT}+"."{DIGIT}+          {
                                yylval.num = atof(yytext);
                                print_token("FLOAT", yytext);
                                return FLOAT_NUMBER;
                             }

{DIGIT}+                     {
                                yylval.num = atoi(yytext);
                                print_token("NUMBER", yytext);
                                return NUMBER;
                             }

{LETTER}({LETTER}|{DIGIT})*  {
                                yylval.str = strdup(yytext);
                                print_token("IDENTIFIER", yytext);
                                return ID;
                             }

\n                           { line_no++; }
[ \t]+                       ;

.                            {
                                printf("Lexical Error at line %d: Invalid token '%s'\n", line_no, yytext);
                             }

%%