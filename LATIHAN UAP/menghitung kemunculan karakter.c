//menghitung kemunculan karakter 
#include <stdio.h>
#include <string.h>
int main () {
    char string[100];
    char karakter;
    int jumlah = 0;
    int i;

    printf ("Masukan string: ");
    fgets (string, sizeof(string), stdin);
    printf ("Masukan karakter yang ingin dihitung: ");
    scanf ("%c", &karakter);

    for (i = 0; i < strlen(string); i++){
        if (string[i]==karakter) {
            jumlah++;
        }
    }

    printf ("kemunculan karakter %c adalah: %d", karakter, jumlah);
    return 0;
}