#include <stdio.h>
#include <string.h>

int main() {
    char kalimat[100];
    char karakter;
    int angka;
    int i;

    // Memasukkan input dari pengguna
    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    printf("Masukkan karakter yang ingin diganti: ");
    scanf(" %c", &karakter);

    printf("Masukkan angka pengganti: ");
    scanf("%d", &angka);

    // Mengganti karakter dalam kalimat
    int panjang = strlen(kalimat);
    for (i = 0; i < panjang; i++) {
        if (kalimat[i] == karakter) {
            kalimat[i] = angka + '0';  // Mengubah angka menjadi karakter
        }
    }

    // Menampilkan hasil setelah penggantian
    printf("Hasil setelah penggantian: %s\n", kalimat);

    return 0;
}
