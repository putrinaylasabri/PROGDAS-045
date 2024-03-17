#include <stdio.h>

int main() {
    int i, j, k, l;

    printf("Masukkan nilai: ");
    scanf("%d", &k);
    printf("Masukkan batas operasi perkalian atau pangkat: ");
    scanf("%d", &j);

    printf("=== Perkalian ===\n");
    for (i = 1; i <= j; i++) {
        printf("%d x %d = %d\n", k, i, k * i);
    }

    printf("\n=== Perpangkatan ===\n");
    for (i = 1; i <= j; i++) {
        int hasilPangkat = 1;
        for (l = 1; l <= i; l++) {
            hasilPangkat *= k;
        }
        printf("%d pangkat %d = %d\n", k, i, hasilPangkat);
    }

    return 0;
}