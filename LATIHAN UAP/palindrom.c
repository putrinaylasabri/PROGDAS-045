#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    printf("Masukkan string: ");
    fgets(string, sizeof(string), stdin);

    // Menghilangkan karakter newline jika ada
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }

    // Memeriksa apakah string adalah palindrom
    int panjang = strlen(string);
    int i, j;

    for (i = 0, j = panjang - 1; i < j; i++, j--) {
        if (string[i] != string[j]) {
            printf("%s bukan palindrom.\n", string);
            return 0;
        }
    }

    printf("%s adalah palindrom.\n", string);

    return 0;
}
