#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256

int main() {
    char kalimat[1000];
    int i;
    
    // Meminta input kalimat dari pengguna
    printf("Masukkan sebuah kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghapus karakter newline di akhir kalimat
    kalimat[strcspn(kalimat, "\n")] = '\0';

    // Menentukan frekuensi munculnya setiap karakter
    int frekuensi[MAX_CHAR] = {0};
    int panjang = strlen(kalimat);

    for (i = 0; i < panjang; i++) {
        frekuensi[kalimat[i]]++;
    }

    // Menampilkan karakter yang sering muncul
    printf("Karakter yang sering muncul:\n");
    for (i = 0; i < MAX_CHAR; i++) {
        if (frekuensi[i] > 1 && isprint(i)) {
            printf("'%c' muncul %d kali\n", i, frekuensi[i]);
        }
    }

    return 0;
}
