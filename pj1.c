#include <stdio.h>

unsigned long long factorial(int n) {
    if (n < 0) return 0; 
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Factorial of %d is %llu\n", num, factorial(num));
    return 0;
}