#include <stdio.h>
#include <string.h>

int main() {
    char kalimat[1000];
    char stringCari[100];

    // Memasukkan kalimat
    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);
    kalimat[strcspn(kalimat, "\n")] = '\0';

    // Memasukkan string yang ingin dicari
    printf("Masukkan string yang ingin dicari: ");
    fgets(stringCari, sizeof(stringCari), stdin);
    stringCari[strcspn(stringCari, "\n")] = '\0';

    int panjangKalimat = strlen(kalimat);
    int panjangCari = strlen(stringCari);
    int indeksKata = 1; 
    int i;

    for (i = 0; i <= panjangKalimat - panjangCari; i++) {
        int j;
        for (j = 0; j < panjangCari; j++) {
            if (kalimat[i + j] != stringCari[j]) {
                break;
            }
        }

        if (j == panjangCari) {
            printf("String '%s' ditemukan dalam kata ke-%d dalam kalimat.\n", stringCari, indeksKata);
            return 0;
        }

        if (kalimat[i + j] == ' ') {
            indeksKata++;
        }
    }

    printf("String '%s' tidak ditemukan dalam kalimat.\n", stringCari);

    return 0;
}
