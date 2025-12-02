#include <stdio.h>

long long p(int n) {
    if (n <= 1)        
        return 1;

    long long matrix = 0;
    for (int k = 1; k <= n - 1; k++) {   // split between k and k+1
        matrix += p(k) * p(n - k);
    }
    return matrix;
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Number of ways: %lld\n", p(n));
    return 0;
}