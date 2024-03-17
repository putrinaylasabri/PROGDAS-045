#include <stdio.h>
#include <string.h>

int main() {
    char kalimat[1000];
    int panjang, jumlahKata;
    int i;

    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghapus karakter newline di akhir kalimat
    panjang = strlen(kalimat);
    if (kalimat[panjang - 1] == '\n') {
        kalimat[panjang - 1] = '\0';
    }

    jumlahKata = 0;

    // Menghitung jumlah kata
    for (i = 0; kalimat[i] != '\0'; i++) {
        if (kalimat[i] == ' ' || kalimat[i] == '\t' || kalimat[i] == '\n') {
            jumlahKata++;
        }
    }

    // Menambah 1 untuk kata terakhir (karena tidak diakhiri oleh spasi)
    jumlahKata++;

    printf("Jumlah kata dalam kalimat: %d\n", jumlahKata);

    return 0;
}
