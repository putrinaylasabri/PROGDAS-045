#include <stdio.h>

int main() {
    int pilihan;
    int matriks1[3][3];
    int matriks2[3][3];
    int hasilPenjumlahan[3][3] = {0}; 
    int hasilPengurangan[3][3] = {0};  
    int hasilPerkalian[3][3] = {0};   
    int i, j, k;

    // Opsi pilihan
    printf("===Operasi Matriks===\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Perkalian\n");

    // Meminta input user
    printf("Pilih salah satu (1/2/3): ");
    scanf("%d", &pilihan);

    // Validasi pilihan
    if (pilihan < 1 || pilihan > 3) {
        printf("Input tidak valid.\n");
        return 1;
    }

    // Meminta input elemen matriks pertama
    printf("Masukkan elemen pada matriks pertama (3x3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriks1[i][j]);
        }
    }

    // Meminta input elemen matriks kedua
    printf("Masukkan elemen pada matriks kedua (3x3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriks2[i][j]);
        }
    }

    // Menampilkan hasil matriks pertama
    printf("\nMatriks pertama:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriks1[i][j]);
        }
        printf("\n");
    }

    // Menampilkan hasil matriks kedua
    printf("\nMatriks kedua:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriks2[i][j]);
        }
        printf("\n");
    }

    if (pilihan == 1) {
        printf("\nHasil penjumlahan matriks:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                hasilPenjumlahan[i][j] = matriks1[i][j] + matriks2[i][j];
                printf("%d ", hasilPenjumlahan[i][j]);
            }
            printf("\n");
        }
    } else if (pilihan == 2) {
        printf("\nHasil pengurangan matriks:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                hasilPengurangan[i][j] = matriks1[i][j] - matriks2[i][j];
                printf("%d ", hasilPengurangan[i][j]);
            }
            printf("\n");
        }
    } else if (pilihan == 3) {
        printf("\nHasil perkalian matriks:\n");

        // Perkalian matriks
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    hasilPerkalian[i][j] += matriks1[i][k] * matriks2[k][j];
                }
            }
        }

        // Menampilkan hasil matriks perkalian
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d ", hasilPerkalian[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}