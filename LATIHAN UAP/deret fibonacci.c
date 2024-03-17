#include <stdio.h>
int main() {
    int n, i;
    unsigned long long fib[100];

    printf("Masukkan jumlah elemen deret Fibonacci yang diinginkan: ");
    scanf("%d", &n);

    fib[0] = 0;
    fib[1] = 1;

    printf("Deret Fibonacci: %llu, %llu", fib[0], fib[1]);
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf(", %llu", fib[i]);
    }
    printf("\n");

    return 0;
}
