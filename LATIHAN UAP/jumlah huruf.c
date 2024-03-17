#include <stdio.h>

int main() {
    char kalimat[1000];
    int i;

    // Meminta input kalimat dari pengguna
    printf("Masukkan sebuah kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghitung jumlah huruf dalam kalimat
    int jumlahHuruf = 0;
    for (i = 0; kalimat[i] != '\0'; i++) {
        if ((kalimat[i] >= 'a' && kalimat[i] <= 'z') || (kalimat[i] >= 'A' && kalimat[i] <= 'Z')) {
            jumlahHuruf++;
        }
    }

    // Menampilkan hasil
    printf("Jumlah huruf dalam kalimat: %d\n", jumlahHuruf);

    return 0;
}
