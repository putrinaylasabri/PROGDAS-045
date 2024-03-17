#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

// Batas maksimal jumlah pengguna dan panjang username/password
#define MAX_PENGGUNA 10
#define PANJANG_USERNAME 20
#define PANJANG_PASSWORD 20

// Struktur untuk merepresentasikan pengguna
struct Pengguna {
    char username[PANJANG_USERNAME];
    char password[PANJANG_PASSWORD];
};

// Fungsi untuk sign up
void signUp(struct Pengguna* pengguna, int* jumlahPengguna) {
    if (*jumlahPengguna < MAX_PENGGUNA) {
        printf("Masukkan Username Baru: ");
        scanf("%s", pengguna[*jumlahPengguna].username);

        printf("Masukkan Password Baru: ");
        scanf("%s", pengguna[*jumlahPengguna].password);

        // Menyimpan data pengguna ke dalam file
        FILE* file = fopen("data_pengguna.txt", "a");
        if (file != NULL) {
            fprintf(file, "%s %s\n", pengguna[*jumlahPengguna].username, pengguna[*jumlahPengguna].password);
            fclose(file);
        } else {
            printf("Gagal menyimpan data ke dalam file.\n");
        }

        (*jumlahPengguna)++;

        printf("Akun Anda berhasil dibuat!\n");
    } else {
        printf("Jumlah pengguna telah mencapai batas maksimal.\n");
    }
}

// Fungsi untuk login
bool login(struct Pengguna* pengguna, int jumlahPengguna) {
    char username[PANJANG_USERNAME];
    char password[PANJANG_PASSWORD];
    char ch;
    int i = 0;
    int j = 0;

    printf("Masukkan Username: ");
    scanf("%s", username);

    for (j = 0; j < jumlahPengguna; j++) {
        if (strcmp(pengguna[j].username, username) == 0) {
            printf("Masukkan Password: ");

            // Mengubah tampilan password menjadi bintang (*)
            while (1) {
                ch = getch();
                if (ch == 13) // Enter
                    break;
                password[i++] = ch;
                printf("*");
            }
            password[i] = '\0'; // Menambahkan karakter null untuk menandai akhir string

            if (strcmp(pengguna[j].password, password) == 0) {
                printf("\nANDA BERHASIL LOGIN\n");
                return true;
            } else {
                printf("\nPassword salah!\n");
                return false;
            }
        }
    }

    printf("Username tidak ditemukan!\n");
    return false;
}

// Fungsi untuk membaca data pengguna dari file
void bacaDataPengguna(struct Pengguna* pengguna, int* jumlahPengguna) {
    FILE* file = fopen("data_pengguna.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s", pengguna[*jumlahPengguna].username, pengguna[*jumlahPengguna].password) == 2) {
            (*jumlahPengguna)++;
        }
        fclose(file);
    } else {
        printf("Gagal membaca data dari file atau file tidak ada.\n");
    }
}

int main() {
    struct Pengguna dataPengguna[MAX_PENGGUNA];
    int jumlahPengguna = 0;
    int pilihan;

    // Membaca data pengguna dari file saat program dimulai
    // bacaDataPengguna(dataPengguna, &jumlahPengguna);

    do {
        printf("Pilih Menu:\n");
        printf("1. Sign Up\n");
        printf("2. Log In\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                signUp(dataPengguna, &jumlahPengguna);
                break;
            case 2:
                login(dataPengguna, jumlahPengguna);
                    // Lakukan tindakan setelah login berhasil
                    // Misalnya, tampilkan menu lain atau lakukan operasi lainnya
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

    } while (pilihan != 0);

    return 0;
}
