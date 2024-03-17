#include <stdio.h>
#include <string.h>

int main() {
    char kalimat[1000];
    char kata[100][100];
    int frekuensi[100] = {0};
    int jumlahKata = 0;
    int i, j;

    // Memasukkan input dari pengguna
    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghapus karakter newline dari input
    kalimat[strcspn(kalimat, "\n")] = '\0';

    // Memecah string menjadi kata-kata
    char *token = strtok(kalimat, " ");

    while (token != NULL) {
        strcpy(kata[jumlahKata], token);
        jumlahKata++;
        token = strtok(NULL, " ");
    }

    printf("Duplikat kata: ");

    // Mencari dan menampilkan kata yang duplikat
    for (i = 0; i < jumlahKata; i++) {
        for (j = i + 1; j < jumlahKata; j++) {
            if (strcmp(kata[i], kata[j]) == 0 && frekuensi[j] == 0) {
                printf("%s ", kata[i]);
                frekuensi[j] = 1;
            }
        }
    }

    printf("\n");

    return 0;
}
