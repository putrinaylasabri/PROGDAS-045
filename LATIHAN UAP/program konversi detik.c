#include <stdio.h>
int main () {
int jam, menit, detik, sisa, total;
printf ("PROGRAM KONVERSI DETIK\n");
printf ("Masukan jumlah detik\t");
scanf ("%d",&total);
jam = total / 3600;
sisa = total % 3600;
menit = sisa / 60;
detik = sisa % 60;
printf ("\nTotal jam adalah : %d jam\n", jam);
printf ("Total menit adalah : %d menit\n", menit);
printf ("Total detik adalah : %d detik\n", detik);
return 0;
}