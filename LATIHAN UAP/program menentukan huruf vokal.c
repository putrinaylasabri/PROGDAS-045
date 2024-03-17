#include <stdio.h>
int main () {
int a;
int b;
printf ("masukan bilangan pertama: ");
scanf ("%i",&a);
printf ("masukan bilangan kedua: ");
scanf ("%i",&b);

if (a > b) {
    printf ("bilangan pertama lebih besar dari bilangan kedua");
} else {
    printf ("bilangan kedua lebih besar dari bilangan pertama");
}
return 0;
}