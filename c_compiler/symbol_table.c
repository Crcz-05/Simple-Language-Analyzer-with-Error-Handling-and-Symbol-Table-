#include <stdio.h>
#include <string.h>
#include "symbol_table.h"

Symbol table[MAX_SYMBOLS];
int count = 0;

int searchSymbol(char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0)
            return i;
    }
    return -1;
}

void insertSymbol(char *name, char *type) {
    if (searchSymbol(name) != -1) {
        printf("Semantic Error: Duplicate declaration of %s\n", name);
        return;
    }

    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    count++;
}

void displaySymbolTable() {
    printf("\nIndex\tName\tType\n");
    printf("-----------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\n",
            i + 1,
            table[i].name,
            table[i].type);
    }
}