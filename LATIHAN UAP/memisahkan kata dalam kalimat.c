#include <stdio.h>
#include <string.h>

int main() {
    char kalimat[1000];

    // Memasukkan input dari pengguna
    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghapus karakter newline dari input
    kalimat[strcspn(kalimat, "\n")] = '\0';

    // Memisahkan kata dalam string
    printf("Kata-kata dalam kalimat:\n");

    char *token = strtok(kalimat, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
