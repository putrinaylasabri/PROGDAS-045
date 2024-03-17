#include <stdio.h>

int main() {
    int panjangArray, target;

    // Memasukkan panjang array dari pengguna
    printf("Masukkan panjang array: ");
    scanf("%d", &panjangArray);

    int data[panjangArray];
    int i; 

    // Memasukkan elemen array dari pengguna
    printf("Masukkan elemen array:\n");
    for (i = 0; i < panjangArray; i++) {
        scanf("%d", &data[i]);
    }

    // Memasukkan data yang ingin dicari dari pengguna
    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &target);

    int indeks = -1;

    // Mencari data dalam array
    for (i = 0; i < panjangArray; i++) {
        if (data[i] == target) {
            indeks = i+1;
            break;
        }
    }

    // Menampilkan hasil pencarian
    if (indeks != -1) {
        printf("Data %d ditemukan di indeks %d dalam array.\n", target, indeks);
    } else {
        printf("Data %d tidak ditemukan dalam array.\n", target);
    }

    return 0;
}
