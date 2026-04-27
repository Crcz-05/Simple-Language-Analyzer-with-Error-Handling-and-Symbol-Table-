#ifndef AST_H
#define AST_H

/* ================= AST NODE ================= */
typedef struct ASTNode {
    int type;
    int value;
    char* name;
    int op;

    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* next;
} ASTNode;

/* ================= CREATE FUNCTIONS ================= */
ASTNode* createBinary(int op, ASTNode* left, ASTNode* right);
ASTNode* createNumber(int value);
ASTNode* createIdentifier(char* name);
ASTNode* createDeclaration(char* name, ASTNode* init);
ASTNode* createFunctionCall(char* name, ASTNode* args);
ASTNode* createStatementList(ASTNode* first, ASTNode* second);
ASTNode* createArgumentList(ASTNode* first, ASTNode* second);
ASTNode* createString(char* value);

/* ================= PRINT FUNCTIONS ================= */
void printAST(ASTNode* root);

/* (Optional but good practice) */
int getHeight(ASTNode* node);

#endif