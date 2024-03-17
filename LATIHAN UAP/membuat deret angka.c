//membuat deret angka
#include <stdio.h>
int main () {
    int a;
    int i;
    int total = 0;
    printf ("Masukan jumlah deret yang diinginkan: ");
    scanf ("%d", &a);

    for (i = 1; i <= a; i++) {
        printf ("%d ", i * 3);
        total += i*3;
    }

    printf ("total jumlah deret adalah %d", total);
    return 0;
}