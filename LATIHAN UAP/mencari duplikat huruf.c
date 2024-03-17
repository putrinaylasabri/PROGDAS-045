#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Untuk menggunakan tolower

int main() {
    char kalimat[1000];
    int frekuensi[256] = {0};  // Array untuk menyimpan jumlah kemunculan huruf ASCII
    int i;

    // Memasukkan input dari pengguna
    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghapus karakter newline dari input
    kalimat[strcspn(kalimat, "\n")] = '\0';

    printf("Duplikat huruf: ");

    // Mencari dan menampilkan huruf yang duplikat
    for (i = 0; i < strlen(kalimat); i++) {
        char huruf = kalimat[i];

        // Memeriksa apakah huruf merupakan huruf alfabet
        if ((huruf >= 'a' && huruf <= 'z') || (huruf >= 'A' && huruf <= 'Z')) {
            // Mengonversi huruf menjadi huruf kecil (jika huruf adalah huruf besar)
            huruf = tolower(huruf);

            // Memeriksa duplikat huruf
            if (frekuensi[huruf] == 1) {
                printf("%c ", huruf);
            }

            // Menandai kemunculan huruf
            frekuensi[huruf]++;
        }
    }

    printf("\n");

    return 0;
}
