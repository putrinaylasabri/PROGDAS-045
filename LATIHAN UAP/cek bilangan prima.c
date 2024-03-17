#include <stdio.h>
int main () {
    int n, i;
    int angkaprima = 1;

    printf ("Masukan suatu angka: ");
    scanf ("%d", &n);

    if (n == 0||n== 1) {
        angkaprima = 0;
    } else {
    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            angkaprima = 0;
            break;
        }
    }
    }

if (angkaprima == 1) {
    printf ("Bilangan %d merupakan bilangan prima", n);
} else {
    printf ("Bilangan %d bukan merupakan bilangan prima", n);
}
return 0;
}