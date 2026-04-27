#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SYMBOLS 1000

typedef struct {
    char name[50];
    char type[20];
    int scope;
} Symbol;

void insertSymbol(char *name, char *type);
int searchSymbol(char *name);
void displaySymbolTable();

#endif