#include <stdio.h>

int main() {
    float nilai_Matematika, nilai_Fisika, nilai_Biologi;
    const int sks_Matematika = 4;
    const int sks_Fisika = 3;
    const int sks_Biologi = 2;
    
    printf ("==Perhitungan nilai rata-rata===");
    
	printf("\n\nMasukkan jumlah nilai Matematika: ");
    scanf("%f", &nilai_Matematika);

 	printf("Masukkan jumlah nilai Fisika: ");
    scanf("%f", &nilai_Fisika);
    
 	printf("Masukkan jumlah nilai Biologi: ");
    scanf("%f", &nilai_Biologi);

    float total_nilai = (sks_Matematika* nilai_Matematika) + (sks_Fisika * nilai_Fisika) + (sks_Biologi * nilai_Biologi);
    int total_sks = sks_Matematika + sks_Fisika + sks_Biologi;

    float nilai_rata_rata = total_nilai / total_sks;
    printf("\nNilai rata-rata dengan bobot SKS adalah %.2f\n",nilai_rata_rata);

    return 0;
}