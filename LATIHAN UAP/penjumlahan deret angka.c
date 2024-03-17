#include <stdio.h>
int main () {
    int i, a;
    int total = 0;
    printf ("Masukan jumlah deret: ");
    scanf ("%d", &a);
    
    for (i = 1; i <= a; i++) {
        printf (" %d ", i);
        total+=i;
    }

    printf ("= %d", total);
    return 0;
}