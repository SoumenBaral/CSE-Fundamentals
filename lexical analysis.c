#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isDelimiter(char ch) {
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>'
        || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == ';') {
        return true;
    }
    return false;
}

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=' || ch == '%' || ch == '^') {
        return true;
    }
    return false;
}

bool validIdentifier(char* str) {
    if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z') || str[0] == '_') {
        return true;
    }
    return false;
}

bool isKeyword(char* str) {
    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "void") || !strcmp(str, "int")) {
        return true;
    }
    return false;
}

bool isInteger(char* str) {
    int i = 0, len = strlen(str);
    if (len == 0) {
        return false;
    }
    if (str[0] == '-') {
        i = 1;
    }
    for (; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

bool isRealNumber(char* str) {
    int i = 0, len = strlen(str);
    bool hasDecimal = false;
    if (len == 0) {
        return false;
    }
    if (str[0] == '-') {
        i = 1;
    }
    for (; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            if (str[i] != '.') {
                return false;
            }
            if (hasDecimal) {
                return false;  // More than one decimal point is not allowed.
            }
            hasDecimal = true;
        }
    }
    return hasDecimal;  // Return true only if there was one decimal point
}

char* subString(char* str, int left, int right) {
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++) {
        subStr[i - left] = str[i];
    }
    subStr[right - left + 1] = '\0';
    return subStr;
}

void parse(char* str) {
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right) {
        if (isDelimiter(str[right]) == false) {
            right++;
        }
        if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true) {
                printf("%c is an Operator\n", str[right]);
            }
            right++;
            left = right;
        } else if ((isDelimiter(str[right]) == true && left != right) || right == len && left != right) {
            char* substr = subString(str, left, right - 1);

            if (isKeyword(substr)) {
                printf("%s is a Keyword\n", substr);
            } else if (isInteger(substr)) {
                printf("%s is an Integer\n", substr);
            } else if (isRealNumber(substr)) {
                printf("%s is a Real Number\n", substr);
            } else if (validIdentifier(substr)) {
                printf("%s is a valid Identifier\n", substr);
            } else {
                printf("%s is not a valid Identifier\n", substr);
            }

            free(substr);
            left = right;
        }
    }
}

int main() {
    char str[100];

    printf("Enter a line of code:\n");
    scanf("%[^\n]", str);

    parse(str);

    return 0;
}
