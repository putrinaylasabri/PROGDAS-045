#include <stdio.h>
int main () {
    int a, i;
    int hasil;
    printf ("Masukan bilangan faktorial: ");
    scanf ("%d", &a);

    hasil = 1;
    for (i = 1; i <= a; i++) {
        hasil = hasil * i;
        printf("%d",i);
        if(i != a) {
            printf (" * ");
    }
    }

    printf (" = %d", hasil);
    return 0;
}