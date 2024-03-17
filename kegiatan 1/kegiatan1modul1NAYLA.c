#include <stdio.h>
int main () {
	float nilai_kalkulus, nilai_pancasila, nilai_orkom;
	
	//membuat input nilai
	printf ("masukkan nilai kalkulus anda: ");
	scanf ("%f",&nilai_kalkulus);
	printf ("masukkan nilai pancasila anda: ");
	scanf ("%f",&nilai_pancasila);
	printf ("masukkan nilai orkom anda: ");
	scanf ("%f",&nilai_orkom);
	
	//menampilkan hasil
	printf ("\nhasil nilai kalkulus anda adalah %.0f", nilai_kalkulus);
	printf ("\nhasil nilai pancasila anda adalah %.0f", nilai_pancasila);
	printf ("\nhasil nilai orkom anda adalah %.0f", nilai_orkom);
	return 0;
}