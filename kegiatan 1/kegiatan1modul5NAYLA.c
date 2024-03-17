#include <stdio.h>
int main () {

//deklarasikan variabel
int total;
int genap = 0;
int ganjil = 0;
int i;

//meminta input pengguna
printf ("Masukkan jumlah elemen yang akan diinput: ");
scanf ("%d", &total);
printf ("Input %d elemen: \n", total);

//deklarasikan array
int arrayTotal[total];
int arrayGenap[total];
int arrayGanjil[total];

//memisahkan array menjadi 2 kelompok 
for (i = 0; i < total; i++) 
{
    scanf ("%d", &arrayTotal[i]);
    
    if (arrayTotal[i] % 2 == 0) {
    arrayGenap[genap] = arrayTotal[i];
    genap++;

    }
    else 
    {
    arrayGanjil[ganjil] = arrayTotal[i];
    ganjil++;
    }
}

//menampilkan bilangan ganjil 
printf ("\nBilangan Ganjil dalam array: "); 
for (i=0; i < ganjil; i++) 
{
   printf ("%d ", arrayGanjil[i]);
}

//menampilkan bilangan genap
printf ("\nBilangan Genap dalam array: ");
for (i=0; i<genap; i++)
{
    printf ("%d ", arrayGenap[i]);
}
return 1;
}