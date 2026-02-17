#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidIdentifier(char str[]) {
    if (!(isalpha(str[0]) || str[0] == '_')) {
        return 0;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char identifier[50];
    printf("Enter the identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier))
        printf("Valid Identifier\n");
    else
        printf("Invalid Identifier\n");

    return 0;
}

