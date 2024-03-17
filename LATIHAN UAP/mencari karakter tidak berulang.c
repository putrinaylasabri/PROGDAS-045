#include <stdio.h>
#include <string.h>

int main() {
    char kalimat[100];

    // Memasukkan input dari pengguna
    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghapus karakter newline dari input
    kalimat[strcspn(kalimat, "\n")] = '\0';

    int panjang = strlen(kalimat);
    int karakter[256] = {0};  // Array untuk menyimpan jumlah kemunculan karakter
    int i;

    printf("Karakter yang tidak berulang: ");

    // Menghitung jumlah kemunculan setiap karakter dalam string
    for (i = 0; i < panjang; i++) {
        karakter[kalimat[i]]++;
    }

    // Menampilkan karakter yang tidak berulang
    for (i = 0; i < panjang; i++) {
        if (karakter[kalimat[i]] == 1) {
            printf("%c ", kalimat[i]);
        }
    }

    printf("\n");

    return 0;
}
