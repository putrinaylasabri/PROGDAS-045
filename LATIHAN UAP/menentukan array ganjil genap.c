#include <stdio.h>
int main() {
    int panjang;
    int i;
    printf("Masukkan panjang array: ");
    scanf("%d", &panjang);
    int angka[panjang];

    printf("Masukkan angka-angka:\n");
    for (i = 0; i < panjang; i++) {
        printf("Angka ke-%d: ", i + 1);
        scanf("%d", &angka[i]);
    }

    printf("Hasil:\n");
    for (i = 0; i < panjang; i++) {
        if (angka[i] % 2 == 0) {
            printf("%d adalah angka genap.\n", angka[i]);
        } else {
            printf("%d adalah angka ganjil.\n", angka[i]);
        }
    }
    return 0;
}
