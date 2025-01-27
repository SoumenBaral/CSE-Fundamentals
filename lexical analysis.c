#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>


bool isDelimiter(char ch) {
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
        ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' ||
        ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}') {
        return true;
    }
    return false;
}


bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=' || ch == '^') {
        return true;
    }
    return false;
}

bool validIdentifier(char* str) {
    if (str[0] >= '0' && str[0] <= '9' || isDelimiter(str[0])) {
        return false;
    }
    return true;
}


bool isKeyword(char* str) {
    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") ||
        !strcmp(str, "do") || !strcmp(str, "break") || !strcmp(str, "continue") ||
        !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") ||
        !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") ||
        !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") ||
        !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") ||
        !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") ||
        !strcmp(str, "goto")) {
        return true;
    }
    return false;
}
bool isInteger(char* str) {
    int i = 0, len = strlen(str);
    if (len == 0)
        return false;

    if (str[0] == '-')
        i = 1;

    for (; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' &&
            str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' &&
            str[i] != '8' && str[i] != '9') {
            return false;
        }
    }
    return true;
}

bool isDecimal(char* str) {
    int i = 0, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return false;

    if (str[0] == '-')
        i = 1;

    for (; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' &&
            str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' &&
            str[i] != '8' && str[i] != '9' && str[i] != '.') {
            return false;
        }

        if (str[i] == '.')
            hasDecimal = true;
    }
    return hasDecimal;
}

int main() {
    char str[100];
    printf("Type the line of code \n");
    scanf("%[^\n]", str);
    return 0;
}
