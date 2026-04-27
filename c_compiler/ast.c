#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ================= CREATE NODES ================= */

ASTNode* createBinary(int op, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = 2;
    node->op = op;
    node->left = left;
    node->right = right;
    node->next = NULL;
    node->name = NULL;
    node->value = 0;
    return node;
}

ASTNode* createNumber(int value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = 0;
    node->value = value;
    node->left = node->right = node->next = NULL;
    node->op = 0;
    node->name = NULL;
    return node;
}

ASTNode* createIdentifier(char* name) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = 1;
    node->name = strdup(name);
    node->left = node->right = node->next = NULL;
    node->op = 0;
    node->value = 0;
    return node;
}

ASTNode* createDeclaration(char* name, ASTNode* init) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = 4;
    node->name = strdup(name);
    node->left = init;
    node->right = NULL;
    node->next = NULL;
    node->op = 0;
    node->value = 0;
    return node;
}

ASTNode* createFunctionCall(char* name, ASTNode* args) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = 3;
    node->name = strdup(name);
    node->left = args;
    node->right = NULL;
    node->next = NULL;
    node->op = 0;
    node->value = 0;
    return node;
}

ASTNode* createString(char* value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = 5;
    node->name = strdup(value);
    node->left = node->right = node->next = NULL;
    node->op = 0;
    node->value = 0;
    return node;
}

/* ================= LIST HANDLING ================= */

ASTNode* createStatementList(ASTNode* first, ASTNode* second) {
    if (!first) return second;

    ASTNode* temp = first;
    while (temp->next)
        temp = temp->next;

    temp->next = second;
    return first;
}

ASTNode* createArgumentList(ASTNode* first, ASTNode* second) {
    return createStatementList(first, second);
}

/* ================= TREE PRINTING ================= */

/* Get height of tree */
int getHeight(ASTNode* node) {
    if (!node) return 0;
    int l = getHeight(node->left);
    int r = getHeight(node->right);
    return (l > r ? l : r) + 1;
}

/* Print spaces */
void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

/* Print node value */
void printNode(ASTNode* node) {
    if (!node) {
        printf(" ");
        return;
    }

    switch (node->type) {
        case 0: printf("%d", node->value); break;
        case 1: printf("%s", node->name); break;

        case 2:
            if (node->op == '~') printf("-");
            else printf("%c", node->op);
            break;

        case 3: printf("%s()", node->name); break;
        case 4: printf("%s", node->name); break;
        case 5: printf("%s", node->name); break;
    }
}

/* Print a given level */
void printLevel(ASTNode* root, int level, int space) {
    if (!root) return;

    if (level == 1) {
        printSpaces(space);
        printNode(root);
        printSpaces(space);
    } else {
        printLevel(root->left, level - 1, space);
        printLevel(root->right, level - 1, space);
    }
}

/* Pretty tree with branches */
void printTree(ASTNode* node, int level) {
    if (!node) return;

    for (int i = 0; i < level; i++) {
        if (i == level - 1)
            printf("├── ");
        else
            printf("│   ");
    }

    /* Print node */
    switch (node->type) {
        case 0: printf("%d\n", node->value); break;
        case 1: printf("%s\n", node->name); break;

        case 2:
            if (node->op == '~') printf("-\n");
            else printf("%c\n", node->op);
            break;

        case 3: printf("%s()\n", node->name); break;
        case 4: printf("decl(%s)\n", node->name); break;
        case 5: printf("%s\n", node->name); break;
    }

    /* Recurse */
    if (node->left)
        printTree(node->left, level + 1);

    if (node->right)
        printTree(node->right, level + 1);
}

/* ================= WRAPPER ================= */

void printAST(ASTNode* root) {
    while (root) {
        printTree(root, 0);
        printf("\n----------------\n");
        root = root->next;
    }
}