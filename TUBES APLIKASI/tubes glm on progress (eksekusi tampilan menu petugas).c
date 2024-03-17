#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#define FILE_NAME "daftarbuku.txt"
#define MAX_CHAR 200

struct library {
    int kode;
    int tahun;
    int jumlahBuku;
    char judul[MAX_CHAR];
    char pengarang[MAX_CHAR];
    char genre[MAX_CHAR];
};

void loadingBar(int duration, int width);
void opsi(char *breadcrumb);
bool loginPetugas(char *breadcrumb);
bool isKodeBukuExists(int kode);
//fungsi untuk petugas perpustakaan 
void tampilanMenuPetugas(char *breadcrumb);
void tambahBuku(char *breadcrumb);
void daftarBuku(char *breadcrumb);
void editBuku(char *breadcrumb);
void hapusBuku(char *breadcrumb);
//fungsi untuk pengunjung
void tampilanMenuPengunjung();
void cariBuku();
void peminjamanBuku();
void pengembalianBuku();
void cekDenda();
//bool check_duplicate_user(char *username, char *password);
//int check_duplicate_id(const int* library_kode);
char breadcrumb[MAX_CHAR] = "Beranda >";

int main() {
    printf ("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\033[7mSELAMAT DATANG DI APLIKASI MANAJEMEN PERPUSTAKAAN");
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    loadingBar(10, 155);
    system ("cls");
    opsi(breadcrumb);
    Sleep(500);
    loadingBar(10, 155);
    system("cls");
    tampilanMenuPetugas(breadcrumb);
    return 0;
}

void loadingBar(int duration, int width) {
    int i;
    for (i = 0; i < width; i++) {
        printf("\033[0;32m\xdb\033[0m");
        Sleep(duration);
    }
    printf("\n");
}

void opsi(char *breadcrumb) {
    int opsi;
    printf ("Apa posisi anda?");
    printf ("\n1. Petugas");
    printf ("\n2. Pengunjung");
    printf ("\nPilihan anda adalah: ");
    scanf ("%d", &opsi);

    if (opsi == 1) {
        system("cls");
        strcat(breadcrumb, " Petugas >");
        loginPetugas(breadcrumb);
    } else {
        system ("cls");
        strcat(breadcrumb, " Pengunjung >");
        tampilanMenuPengunjung(); 
    }
}

bool loginPetugas(char *breadcrumb) {
    char expectedUsername[] = "geniuslibrary";
    char expectedPassword[] = "000000123";
    char username[MAX_CHAR];
    char password[MAX_CHAR];
    char ch;
    int i;

    do {
        i = 0;
        printf("Masukkan username khusus petugas: ");
        scanf("%s", username);
        
        printf("Masukkan Password: ");
        while (1) {
            ch = getch();
            if (ch == 13)
                break;
            password[i++] = ch;
            printf("*");
        }
        password[i] = '\0';

        if (strcmp(password, expectedPassword) == 0 && strcmp(username, expectedUsername) == 0) {
            printf("\n\033[033mANDA BERHASIL LOGIN!\033[0m\n");
            return true;  
        } else {
            printf("\n\033[031mPassword atau username salah! Silakan coba lagi.\n\n\033[0m");
        }
    } while (1);
}

void tampilanMenuPengunjung () 
{

}

void tampilanMenuPetugas(char *breadcrumb) {
    FILE *file = fopen(FILE_NAME, "a+");
    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    
    int opsi;
    do {
        printf ("%s", breadcrumb);
        printf ("\n\nApa yang ingin anda lakukan?\n");
        printf ("1. Tambah Buku\n");
        printf ("2. Daftar Buku\n");
        printf ("3. Edit Informasi Buku\n");
        printf ("4. Hapus Buku\n");
        printf ("5. Keluar dari program\n");
        printf ("Pilihan anda adalah: ");
        scanf ("%d",&opsi);
        Sleep (600);
        system ("cls");

        switch (opsi) {
            case 1:
   	            strcat(breadcrumb, " Tambah Buku >");
                tambahBuku(breadcrumb);
                break;

            case 2:
                strcat(breadcrumb, " Daftar Buku >");
                daftarBuku(breadcrumb);
                break;

            case 3:
                strcat(breadcrumb, " Edit Buku >");
                editBuku(breadcrumb);
                break;

            case 4:
                strcat(breadcrumb, " Hapus Buku >");
                hapusBuku(breadcrumb);
                break;

            case 5:
                printf ("Terimakasih! Keluar dari program\n");
                break;

            default:
                printf ("MASUKAN PILIHAN YANG VALID\n");
        }
    } while (opsi != 5);
}

void tambahBuku(char *breadcrumb) {
    printf("%s", breadcrumb);
    struct library add;
    printf("\n\nMasukkan kode buku: ");
    scanf("%d", &add.kode);

    if (isKodeBukuExists(add.kode)) {
        printf("Kode buku sudah ada. Masukkan kode buku lain.\n");
        tambahBuku(breadcrumb);
        return;
    }

    printf("Masukkan tahun terbit: ");
    scanf("%d", &add.tahun);
    printf("Masukkan jumlah buku: ");
    scanf("%d", &add.jumlahBuku);
    printf("Masukkan judul: ");
    scanf(" %[^\n]s", add.judul); 
    printf("Masukkan pengarang: ");
    scanf(" %[^\n]s", add.pengarang); 
    printf("Masukkan genre: ");
    scanf(" %[^\n]s", add.genre); 

    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Gagal membuka file atau file tidak ditemukan. Membuat file baru...\n");
		exit(EXIT_FAILURE);
        }

    fprintf(file, "%d %d %d %s %s %s\n", add.kode, add.tahun, add.jumlahBuku, add.judul, add.pengarang, add.genre);
    fclose(file);
    printf("Buku berhasil ditambahkan.\n");
}

bool isKodeBukuExists(int kode) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    struct library temp;
    while (fscanf(file, "%d %d %d %s %s %s\n", &temp.kode, &temp.tahun, &temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre) == 6) {
        if (temp.kode == kode) {
            fclose(file);
            return true; 
        }
    }

    fclose(file);
    return false; 
}

   void daftarBuku(char *breadcrumb) {
    printf("%s", breadcrumb);
    printf("\n\nDaftar Buku:\n");

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    printf("| %-10s | %-10s | %-15s | %-20s | %-20s | %-15s |\n", "Kode", "Tahun", "Jumlah Buku", "Judul", "Pengarang", "Genre");
    printf("|------------|------------|------------------|-----------------------|-----------------------|------------------|\n");

    struct library temp;
    while (fscanf(file, "%d %d %d %s %s %s\n", &temp.kode, &temp.tahun, &temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre) == 6) {
        printf("| %-10d | %-10d | %-15d | %-20s | %-20s | %-15s |\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
    }

    fclose(file);
}

void editBuku(char *breadcrumb) {
    // Implementasi edit buku
}

void hapusBuku(char *breadcrumb) {
    // Implementasi hapus buku
}
