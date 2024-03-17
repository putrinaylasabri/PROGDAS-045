#include <stdio.h>

int main() {
    int pilihan;
    int baris = 3, kolom = 3;
    int matriks1[3][3];
    int matriks2[3][3];
    int hasilPenjumlahan;
    int hasilPengurangan;
    int hasilPerkalian[3][3];
    int i, j, k;
    int m, n, p;

    // Opsi pilihan
    printf ("===Operasi Matriks===\n");
    printf ("1. Penjumlahan\n");
    printf ("2. Pengurangan\n");
    printf ("3. Perkalian\n");
    
    // Meminta input user
    printf ("Pilih salah satu (1/2/3): ");
    scanf ("%d", &pilihan);

    // Meminta input elemen matriks pertama 
    printf("Masukkan elemen pada matriks pertama (3x3):\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            scanf("%d", &matriks1[i][j]);
        }
    }

    // Meminta input elemen matriks kedua
    printf("Masukkan elemen pada matriks kedua (3x3):\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            scanf("%d", &matriks2[i][j]);
        }
    }

    // Menampilkan hasil matriks pertama
    printf ("\nMatriks pertama:\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf ("%d ", matriks1[i][j]);
        }
        printf ("\n");
    }

    // Menampilkan hasil matriks kedua
    printf ("\nMatriks kedua:\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf ("%d ", matriks2[i][j]);
        }
        printf ("\n");
    }

    if (pilihan == 1) {
        printf ("\nHasil penjumlahan matriks:\n");
        for (i = 0; i < baris; i++) {
            for (j = 0; j < kolom; j++) {
                hasilPenjumlahan = matriks1[i][j] + matriks2[i][j];
                printf ("%d ", hasilPenjumlahan);
            }
            printf ("\n");
        }
    } else if (pilihan == 2) {
        printf ("\nHasil pengurangan matriks:\n");
        for (i = 0; i < baris; i++) {
            for (j = 0; j < kolom; j++) {
                hasilPengurangan = matriks1[i][j] - matriks2[i][j];
                printf ("%d ", hasilPengurangan);
            }
            printf ("\n");
        }
    } else if (pilihan == 3) {
        printf ("\nHasil perkalian matriks:\n");
        
        // Meminta input ukuran matriks pertama dan kedua
        printf("Masukkan ukuran matriks pertama (baris kolom): ");
        scanf("%d %d", &m, &n);

        printf("Masukkan ukuran matriks kedua (baris kolom): ");
        scanf("%d %d", &n, &p);

        // Inisialisasi hasil matriks perkalian dengan 0
        for (i = 0; i < m; i++) {
            for (j = 0; j < p; j++) {
                hasilPerkalian[i][j] = 0;
            }
        }

        // Perkalian matriks
        for (i = 0; i < m; i++) {
            for (j = 0; j < p; j++) {
                for (k = 0; k < n; k++) {
                    hasilPerkalian[i][j] += matriks1[i][k] * matriks2[k][j];
                }
            }
        }

        // Menampilkan hasil matriks perkalian
        for (i = 0; i < m; i++) {
            for (j = 0; j < p; j++) {
                printf("%d ", hasilPerkalian[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Pilihan tidak valid\n");
    }
    
    return 0;
}