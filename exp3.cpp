#include <stdio.h>

int main() {
    int a, b, c;
    int t1, t2, result;

    // Input values for a, b, and c
    printf("Enter values for a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);

    // Three Address Code representation
    t1 = b * c;  // t1 = b * c
    result = a + t1;  // result = a + t1

    // Output the result
    printf("Result of a + b * c: %d\n", result);
    
    return 0;
}

