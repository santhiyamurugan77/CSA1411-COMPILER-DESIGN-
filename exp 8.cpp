#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char lhs[20];
    char rhs[50];
} TAC;

// Global TAC array
TAC tac[MAX];
int tac_count = 0;

// Function to add TAC
void add_TAC(char* lhs, char* rhs) {
    strcpy(tac[tac_count].lhs, lhs);
    strcpy(tac[tac_count].rhs, rhs);
    tac_count++;
}

// Function to generate TAC for simple expressions
void generate_TAC(char statements[][50], int n) {
    int temp_count = 1;
    for(int i=0;i<n;i++) {
        char *stmt = statements[i];
        char lhs[20], rhs[50];
        char op1[20], op2[20], operator;
        if(sscanf(stmt, "%[^=]=%s", lhs, rhs) == 2) {
            // Check for binary operation
            if(sscanf(rhs, "%[^+-*/]%c%s", op1, &operator, op2) == 3) {
                char temp[20];
                sprintf(temp, "t%d", temp_count++);
                char expr[50];
                sprintf(expr, "%s %c %s", op1, operator, op2);
                add_TAC(temp, expr);
                add_TAC(lhs, temp);
            } else {
                add_TAC(lhs, rhs);
            }
        }
    }
}

// Common Subexpression Elimination
void common_subexpr_elim() {
    for(int i=0;i<tac_count;i++) {
        if(strchr(tac[i].rhs, '+') || strchr(tac[i].rhs, '-') ||
           strchr(tac[i].rhs, '*') || strchr(tac[i].rhs, '/')) {
            for(int j=0;j<i;j++) {
                if(strcmp(tac[i].rhs, tac[j].rhs) == 0) {
                    strcpy(tac[i].rhs, tac[j].lhs); // Replace with previous temp
                    break;
                }
            }
        }
    }
}

// Constant Propagation
void constant_propagation() {
    char constants[MAX][2][20]; // lhs, value
    int const_count = 0;

    for(int i=0;i<tac_count;i++) {
        int is_digit = 1;
        for(int k=0;k<strlen(tac[i].rhs);k++){
            if(tac[i].rhs[k] < '0' || tac[i].rhs[k] > '9'){
                is_digit = 0;
                break;
            }
        }
        if(is_digit) {
            strcpy(constants[const_count][0], tac[i].lhs);
            strcpy(constants[const_count][1], tac[i].rhs);
            const_count++;
        } else {
            for(int j=0;j<const_count;j++){
                char *pos = strstr(tac[i].rhs, constants[j][0]);
                if(pos) {
                    char new_rhs[50];
                    strcpy(new_rhs, tac[i].rhs);
                    int idx = pos - tac[i].rhs;
                    new_rhs[idx] = '\0';
                    strcat(new_rhs, constants[j][1]);
                    strcat(new_rhs, pos + strlen(constants[j][0]));
                    strcpy(tac[i].rhs, new_rhs);
                }
            }
        }
    }
}

// Dead Code Elimination (remove unused temps)
void dead_code_elim() {
    int used[MAX] = {0};
    // Mark used variables
    for(int i=0;i<tac_count;i++) {
        for(int j=i+1;j<tac_count;j++){
            if(strstr(tac[j].rhs, tac[i].lhs)) {
                used[i] = 1;
                break;
            }
        }
    }
    // Print optimized TAC
    printf("\n--- OPTIMIZED CODE ---\n");
    for(int i=0;i<tac_count;i++){
        if(used[i] || tac[i].lhs[0] != 't') {
            printf("%s = %s\n", tac[i].lhs, tac[i].rhs);
        }
    }
}

int main() {
    char statements[MAX][50];
    int n = 0;

    printf("Enter statements (type 'end' to stop):\n");
    while(1) {
        char line[50];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = 0;
        if(strcmp(line, "end") == 0) break;
        strcpy(statements[n++], line);
    }

    // Generate TAC
    generate_TAC(statements, n);

    printf("\n--- THREE ADDRESS CODE ---\n");
    for(int i=0;i<tac_count;i++){
        printf("%s = %s\n", tac[i].lhs, tac[i].rhs);
    }

    // Optimize
    common_subexpr_elim();
    constant_propagation();
    dead_code_elim();

    return 0;
}

