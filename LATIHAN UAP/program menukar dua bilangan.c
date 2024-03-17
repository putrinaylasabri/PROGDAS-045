#include <stdio.h>
int main () {
int a, b, c;
printf ("Bilangan sebelum ditukar\n");
printf ("Masukan angka pertama : ");
scanf ("%d",&a);
printf ("Masukan angka kedua : ");
scanf ("%d",&b);

//menukar bilangan
c = a;
a = b;
b = c;
printf ("\nBilangan pertama setelah ditukar adalah %d\n",a);
printf ("Bilangan kedua setelah ditukar adalah %d", b);
return 0;
}