#include <stdio.h>

int main() {
    int i, j, n;
    printf("Masukkan tinggi huruf A (angka ganjil): ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Tinggi huruf harus ganjil.\n");
        return 1;
    }

    int middle = n / 2;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            if (j == middle || (i == 0 && j >= 0 && j < n) || (i == middle && (j == 0 || j == n - 1)) || (i > 0 && i < middle && j == 0) || (i > 0 && i < middle && j == n - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
