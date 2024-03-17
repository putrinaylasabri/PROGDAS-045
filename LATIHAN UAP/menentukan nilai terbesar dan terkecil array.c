#include <stdio.h>

int main() {
    int panjang;
    int i;
    
    // Meminta input panjang array dari pengguna
    printf("Masukkan panjang array: ");
    scanf("%d", &panjang);

    // Inisialisasi array
    int nilai[panjang];

    // Meminta input nilai-nilai array dari pengguna
    printf("Masukkan nilai-nilai:\n");
    for (i = 0; i < panjang; i++) {
        printf("Nilai ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    // Inisialisasi nilai terbesar dan terkecil
    int terbesar = nilai[0];
    int terkecil = nilai[0];

    // Mencari nilai terbesar dan terkecil
    for (i = 1; i < panjang; i++) {
        if (nilai[i] > terbesar) {
            terbesar = nilai[i];
        }
        if (nilai[i] < terkecil) {
            terkecil = nilai[i];
        }
    }

    // Menampilkan hasil
    printf("Nilai terbesar: %d\n", terbesar);
    printf("Nilai terkecil: %d\n", terkecil);

    return 0;
}
