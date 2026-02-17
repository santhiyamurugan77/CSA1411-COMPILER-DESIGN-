#include <stdio.h>
#include <conio.h>

int main() {
    char s[5];
    printf("\n Enter any operator:");
    gets(s);
    switch(s[0]) {
        case '>':
            if(s[1] == '=') 
                printf("\n Greater than or equal");
            else 
                printf("\n Greater than");
            break;
        case '<':
            if(s[1] == '=') 
                printf("\n Less than or equal");
            else 
                printf("\n Less than");
            break;
        case '=':
            if(s[1] == '=') 
                printf("\n Equal to");
            else 
                printf("\n Assignment");
            break;
        case '!':
            if(s[1] == '=') 
                printf("\n Not Equal");
            else 
                printf("\n Bit Not");
            break;
        case '&':
            if(s[1] == '&') 
                printf("\n Logical AND");
            else 
                printf("\n Bitwise AND");
            break;
        case '|':
            if(s[1] == '|') 
                printf("\n Logical OR");
            else 
                printf("\n Bitwise OR");
            break;
        case '+':
            printf("\n Addition");
            break;
        case '-':
            printf("\n Subtraction");
            break;
        case '*':
            printf("\n Multiplication");
            break;
        case '/':
            printf("\n Division");
            break;
        case '%':
            printf("\n Modulus");
            break;
        default:
            printf("\n Not an operator");
    }
}

