#include <stdio.h>
int main () {
//deklarasikan variabel
int total, km, cm, m, sisa;
printf ("PROGRAM KONVERSI CENTIMETER\n");
printf ("Masukan jumlah cm : ");
scanf ("%i",&total);

//konversi
km = total / 100000;
sisa = total % 100000;
m = sisa / 100;
cm = sisa % 100;

// menampilkan hasil konversi
printf("\nJumlah km = %i kilometer \n",km);
printf("Jumlah m = %i meter \n",m);
printf("Jumlah cm = %i centimeter \n",cm);
}