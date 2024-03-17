#include <stdio.h>
#define FILE_NAME "ratingtoko.txt"

int rating; 
void ratingToko ();
void tampilanRatingtoko ();

int main () {
    ratingToko();
    tampilanRatingtoko();
    return 0;
}

void ratingToko () {
    int i;
    printf ("\nTERIMA KASIH KARENA SUDAH BERBELANJA DI TOKO KAMI!\n");
    printf ("Berikan penilaian anda sebagai bentuk dukungan terhadap kami!\n");
    printf ("Dari skala 1-5 seberapa puas anda terhadap toko kami? : ");
    scanf ("%d", &rating);
    for (i = 0; i < rating; i++) {
        printf ("*");
    }

    printf ("\nTerimakasih, atas dukungan anda!\n\n");

    FILE *file = fopen (FILE_NAME, "a");
    fprintf (file, "%d", rating);
    fclose(file);
}

void tampilanRatingtoko() {
    printf ("RATING PENGGUNA:\n");
    FILE *file = fopen (FILE_NAME, "r");
    while (fscanf(file, "%d\n", &rating) != EOF) {
    printf("%d\t\n", &rating);
}
fclose(file);
}