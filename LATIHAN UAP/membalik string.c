#include <stdio.h>
#include <string.h>

int main() {
    char kalimat[1000];

    // Meminta input kalimat dari pengguna
    printf("Masukkan sebuah kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghapus karakter newline di akhir kalimat
    kalimat[strcspn(kalimat, "\n")] = '\0';

    // Memanggil fungsi untuk membalik string
    strrev(kalimat);

    // Menampilkan hasil setelah dibalik
    printf("Kalimat setelah dibalik: %s\n", kalimat);

    return 0;
}
