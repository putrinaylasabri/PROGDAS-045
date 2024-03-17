#include <stdio.h>
int hitungFaktorial (int input) {
    if (input > 1) {
        return input * hitungFaktorial(input - 1);
    } else {
        return 1;
    }
}

int main () {
    int angka, hasil;
    printf ("Masukan angka: ");
    scanf ("%d", &angka);

    hasil = hitungFaktorial(angka);
    printf ("Hasil faktorial dari %d adalah %d", angka, hasil);
    return 0;
}