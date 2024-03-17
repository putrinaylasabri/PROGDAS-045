#include <stdio.h>
int main () {
    int jumlahVokal = 0;
    int jumlahKonsonan = 0;
    int i = 0;
    char kalimat[100];
    printf ("Masukan kalimat: ");
    fgets (kalimat, sizeof(kalimat), stdin);

    for (i = 0; kalimat[i]!= '\0';i++) {
        char huruf = kalimat[i];
        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o' ||
			huruf == 'A' || huruf == 'I' || huruf == 'U' || huruf == 'E' || huruf == 'O')
            {
                jumlahVokal++;
            }
        else if ((huruf >= 'a' && huruf <= 'z') || (huruf >= 'A' && huruf <= 'Z'))
        {
            jumlahKonsonan++;
        }
    }

    printf ("\nJumlah huruf vokal %d", jumlahVokal);
    printf ("\nJumlah huruf konsonan %d", jumlahKonsonan);
    return 0;
}