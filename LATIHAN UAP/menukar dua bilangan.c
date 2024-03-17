#include <stdio.h>

int main() {
    int bilangan1, bilangan2;

    printf("Masukkan bilangan pertama: ");
    scanf("%d", &bilangan1);

    printf("Masukkan bilangan kedua: ");
    scanf("%d", &bilangan2);
    printf("Bilangan sebelum pertukaran: %d dan %d\n", bilangan1, bilangan2);

    int temp = bilangan1;
    bilangan1 = bilangan2;
    bilangan2 = temp;

    printf("Bilangan setelah pertukaran: %d dan %d\n", bilangan1, bilangan2);
    return 0;
}
