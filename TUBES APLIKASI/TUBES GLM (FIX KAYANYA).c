#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define FILE_NAME "daftarbuku.txt"
#define PEMINJAMAN_FILE "peminjaman.txt"
#define MAX_CHAR 200
#define DENDA_PER_HARI 500

struct library {
    int kode;
    int tahun;
    int jumlahBuku;
    char judul[MAX_CHAR];
    char pengarang[MAX_CHAR];
    char genre[MAX_CHAR];
};

struct peminjaman {
    char namaPeminjam[MAX_CHAR];
    char judulBuku[MAX_CHAR];
    char tanggalPinjam[MAX_CHAR];
    char tanggalKembali[MAX_CHAR];
};

void setConsoleColor(int color);
void drawBox(int width);
void loadingBar(int duration, int width);
void printTextWithDelay(const char *text, int delay);
void opsi(char *breadcrumb);
bool loginPetugas();
int isKodeBukuExists(int kode);

//fungsi untuk petugas perpustakaan 
void tampilanMenuPetugas(char *breadcrumb);
void tambahBuku(char *breadcrumb);
void daftarBuku(char *breadcrumb);
void editBuku(char *breadcrumb);
void hapusBuku(char *breadcrumb, int kodeBuku);
void historyPeminjaman(char *breadcrumb);

//fungsi untuk pengunjung
void tampilanMenuPengunjung(char *breadcrumb);
void toLowerCase(char *str);
void cariBuku(char *breadcrumb);
bool isBukuAvailable(const char *judulBuku);
void peminjamanBuku(char *breadcrumb);
void tambahPeminjaman(const char *namaPeminjam, const char *judulBuku, const char *tanggalPinjam, const char *tanggalKembali);
bool parseDate(const char *dateString, struct tm *result);
void pengembalianBuku(char *breadcrumb);
void hitungDenda(const char *tanggalKembali);
void hapusPeminjaman(const char *namaPeminjam, const char *judulBuku);
char breadcrumb[MAX_CHAR] = "Beranda >";


int main() {
    system("cls");
    setConsoleColor(12);
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t");
	const char *myText = "\033[7mHELLO! WELCOME TO GENIUS LIBRARY MANAGER!\033[1m";
    printTextWithDelay(myText, 50); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    loadingBar(10, 155);
    system("cls");
    setConsoleColor(14);
    opsi(breadcrumb);
    return 0;
}

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawBox(int width) {
	int i;
    printf("\n");
    for (i = 0; i < width; i++) {
        printf("\033[1;31m\xdb\033[1;33m");  
    }
    printf("\n");
}

void loadingBar(int duration, int width) {
    int i;
    for (i = 0; i < width; i++) {
        setConsoleColor(6); 
        printf("\xdb");
        Sleep(duration);
    }
    printf("\n");
}

void printTextWithDelay(const char *text, int delay) {
    int i = 0;
    while (text[i] != '\0') {
        putchar(text[i]);
        Sleep(delay);
        i++;
    }
}

void opsi(char *breadcrumb) {
    int opsi;
    system("cls");

    // Header
    printf("\033[1;31m");
    drawBox(155);
    printf("\t\t\t\t\t\t\t SELAMAT DATANG DI APLIKASI PERPUSTAKAAN ");
    drawBox(155);
    printf("\n\n");

    // Opsi menu
    printf("\033[1;33m");  // Yellow text
    printf(" \n\n\n\n\n\n\t\t\t\t\t\t\t==============================\n");
    printf(" \t\t\t\t\t\t\t|      Apa Posisi Anda?      |\n");
    printf(" \t\t\t\t\t\t\t==============================\n");
    printf(" \t\t\t\t\t\t\t| 1  | Petugas               |\n");
    printf(" \t\t\t\t\t\t\t| 2  | Pengunjung            |\n");
    printf(" \t\t\t\t\t\t\t==============================\n");
    printf (" \t\t\t\t\t\t\tPilihan anda: ");
    scanf("%d", &opsi);

    // Memilih opsi
    if (opsi == 1) {
        system("cls");
        strcat(breadcrumb, " Petugas >");
		printf("\033[1;31m");
        drawBox(155);
        printf("\t\t\t\t\t\t\t\t\t LOGIN PETUGAS ");
        drawBox(155);
        loginPetugas(breadcrumb);
    } else {
        system("cls");
        strcat(breadcrumb, " Pengunjung >");
        tampilanMenuPengunjung(breadcrumb);
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
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tUSERNAME: ");
        scanf("%s", username);
        
        printf("\t\t\t\t\t\t\t\tPASSWORD: ");
        while (1) {
            ch = getch();
            if (ch == 13)
                break;
            password[i++] = ch;
            printf("*");
        }
        password[i] = '\0';

        if (strcmp(password, expectedPassword) == 0 && strcmp(username, expectedUsername) == 0) {
            printf("\n\033[032m\t\t\t\t\t\t\t\tANDA BERHASIL LOGIN!\033[0m\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            loadingBar(10, 155);
            Sleep (600);
            system("cls");
            setConsoleColor(11); // Cyan
            tampilanMenuPetugas(breadcrumb);
            return true;  
        } else {
            printf("\n\033[031m\t\t\t\t\t\t\t\tPassword atau username salah! Silakan coba lagi.\n\033[0m");
        }
    } while (1);
}

void tampilanMenuPetugas(char *breadcrumb) {
    FILE *file = fopen(FILE_NAME, "a+");
    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }
    fclose(file);

    int opsi, lanjutkanProgram;
    do {
    	printf("%s", breadcrumb);
        printf("\033[1;31m");
        drawBox(155);
        printf("\t\t\t\t\t\t\t\t\t MENU PETUGAS ");
        drawBox(155);
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n");
        printf("\t\t\t\t\t\t\t\t| Apa yang ingin anda lakukan?|\n");
        printf(" \t\t\t\t\t\t\t\t===============================\n");
        printf("\t\t\t\t\t\t\t\t| 1 | Tambah Buku             | \n");
        printf("\t\t\t\t\t\t\t\t| 2 | Daftar Buku             | \n");
        printf("\t\t\t\t\t\t\t\t| 3 | Edit Informasi Buku     | \n");
        printf("\t\t\t\t\t\t\t\t| 4 | Hapus Buku              | \n");
        printf("\t\t\t\t\t\t\t\t| 5 | Lihat History Peminjaman| \n");
        printf("\t\t\t\t\t\t\t\t| 6 | Keluar dari program     | \n");
        printf(" \t\t\t\t\t\t\t\t===============================\n");
        printf("\t\t\t\t\t\t\t\tPilihan anda adalah: ");
        scanf("%d", &opsi);

        Sleep(600);
        system("cls");

        switch (opsi) {
            case 1:
                strcat(breadcrumb, " Tambah Buku >");
                printf("%s", breadcrumb);
                drawBox(155);
                printf("\t\t\t\t\t\t\t\t\t TAMBAH BUKU ");
                drawBox(155);
                tambahBuku(breadcrumb);
                break;

            case 2:
                strcat(breadcrumb, " Daftar Buku >");
                printf("%s", breadcrumb);
                drawBox(155);
                printf("\t\t\t\t\t\t\t\t\t DAFTAR BUKU ");
                drawBox(155);
                daftarBuku(breadcrumb);
                break;

            case 3:
                strcat(breadcrumb, " Edit Buku >");
                printf("%s", breadcrumb);
                drawBox(155);
                printf("\t\t\t\t\t\t\t\t\t EDIT BUKU ");
                drawBox(155);
                editBuku(breadcrumb);
                break;

            case 4:
                strcat(breadcrumb, " Hapus Buku >");
                printf("%s", breadcrumb);
                drawBox(155);
                printf("\t\t\t\t\t\t\t\t\t HAPUS BUKU ");
                drawBox(155);
                int kodeBukuToDelete;
                printf("\n\n\t\t\t\t\t\t\tKODE BUKU YANG INGIN DIHAPUS: ");
                scanf("%d", &kodeBukuToDelete);
                hapusBuku(breadcrumb, kodeBukuToDelete);
                break;
            
            case 5:
            	strcat(breadcrumb, "History Peminjaman >");
            	printf ("%s", breadcrumb);
				drawBox(155);
                printf("\t\t\t\t\t\t\t\t HISTORY PEMINJAMAN ");
                drawBox(155);
                historyPeminjaman(breadcrumb);
                break;

            case 6:
                lanjutkanProgram = 0;
                printf("\033[1;36m");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                drawBox(155);
                printf("\t\t\t\t\t\t\tTERIMAKASIH! KELUAR DARI PROGRAM");
                drawBox(155);
                while (getchar() != '\n');
                break;

            default:
                printf("\t\t\t\t\t\t\t\033[031mMASUKAN PILIHAN YANG VALID\n\033[0m");
        }

        if (opsi != 6) {
            do {
                printf("\n\t\t\t\t\t\t\tApakah Anda ingin melanjutkan program? (1: Ya, 0: Tidak): ");
                scanf("%d", &lanjutkanProgram);
                Sleep(600);
                system("cls");

                // Menampilkan pesan validasi jika input tidak valid
                if (lanjutkanProgram != 0 && lanjutkanProgram != 1) {
                    printf("MASUKAN INPUTAN YANG VALID\n");
                } if (lanjutkanProgram == 0) {
				printf("\033[1;36m");
            	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            	drawBox(155);
                printf ("\t\t\t\t\t\t\tTERIMAKASIH! KELUAR DARI PROGRAM");
                drawBox(155);
				}
				
            } while (lanjutkanProgram != 0 && lanjutkanProgram != 1);
        }
    } while (lanjutkanProgram == 1);
}


void tambahBuku(char *breadcrumb) {
    struct library add;

    printf("\n\n\t\t\t\t\t\t\tKODE BUKU: ");
    scanf("%d", &add.kode);

    if (isKodeBukuExists(add.kode)) {
        printf("\t\t\t\t\t\t\t\033[031mKode buku sudah ada. Masukkan kode buku lain.\n\033[0m");
        return;
    }

    printf("\t\t\t\t\t\t\tTAHUN TERBIT: ");
    scanf("%d", &add.tahun);
    printf("\t\t\t\t\t\t\tJUMLAH BUKU: ");
    scanf("%d", &add.jumlahBuku);

    while (getchar() != '\n');  // Membersihkan newline character dari stdin
    printf("\t\t\t\t\t\t\tJUDUL: ");
    fgets(add.judul, sizeof(add.judul), stdin);
    printf("\t\t\t\t\t\t\tPENGARANG: ");
    fgets(add.pengarang, sizeof(add.pengarang), stdin);
    printf("\t\t\t\t\t\t\tKATEGORI: ");
    fgets(add.genre, sizeof(add.genre), stdin);

    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Gagal membuka file atau file tidak ditemukan. Membuat file baru...\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d %d %d %s %s %s\n", add.kode, add.tahun, add.jumlahBuku, add.judul, add.pengarang, add.genre);
    fclose(file);
    printf("\n\t\t\t\t\t\t\t\033[033mBuku berhasil ditambahkan.\n\n\033\0m");
}

void daftarBuku(char *breadcrumb) {
    printf("\n\nDaftar Buku:\n");

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    printf("============================================================================================================================================================\n");
    printf("| %-10s | %-10s | %-15s | %-50s | %-30s | %-22s |\n", "Kode", "Tahun", "Jumlah Buku", "Judul", "Pengarang", "Genre");
    printf("============================================================================================================================================================\n");
    struct library temp;

    while (fscanf(file, "%d %d %d", &temp.kode, &temp.tahun, &temp.jumlahBuku) == 3) {
        fgets(temp.judul, sizeof(temp.judul), file);
        fgets(temp.pengarang, sizeof(temp.pengarang), file);
        fgets(temp.genre, sizeof(temp.genre), file);

        temp.judul[strcspn(temp.judul, "\n")] = '\0';
        temp.pengarang[strcspn(temp.pengarang, "\n")] = '\0';
        temp.genre[strcspn(temp.genre, "\n")] = '\0';

        printf("| %-10d | %-10d | %-15d | %-50s | %-30s | %-22s |\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
    }

    printf("============================================================================================================================================================\n");
    fclose(file);
}

void editBuku(char *breadcrumb) {
    int kodeBukuToEdit;
    printf("\n\n\t\t\t\t\t\t\tMasukkan kode buku yang ingin diedit: ");
    scanf("%d", &kodeBukuToEdit);

    if (!isKodeBukuExists(kodeBukuToEdit)) {
        printf("\n\t\t\t\t\t\t\t\033[031mBuku dengan kode %d tidak ditemukan.\n\n\033[0m", kodeBukuToEdit);
        return;
    }

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Gagal membuat file sementara.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    struct library temp;
    int found = 0;

    while (fscanf(file, "%d %d %d %[^\n] %[^\n] %[^\n]\n", &temp.kode, &temp.tahun, &temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre) == 6) {
        if (temp.kode == kodeBukuToEdit) {
            printf("\nData Lama:\n");
            printf("============================================================================================================================================================\n");
            printf("| %-10s | %-10s | %-15s | %-50s | %-30s | %-22s |\n", "Kode", "Tahun", "Jumlah Buku", "Judul", "Pengarang", "Genre");
            printf("============================================================================================================================================================\n");
            printf("| %-10d | %-10d | %-15d | %-50s | %-30s | %-22s |\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
            printf("============================================================================================================================================================\n");

            printf("\nMasukkan data baru:\n");
            printf("TAHUN TERBIT: ");
            scanf("%d", &temp.tahun);
            printf("JUMLAH BUKU: ");
            scanf("%d", &temp.jumlahBuku);

            while (getchar() != '\n');  // Membersihkan newline character dari stdin
            printf("\t\t\t\t\t\t\tJUDUL: ");
            fgets(temp.judul, sizeof(temp.judul), stdin);
            printf("\t\t\t\t\t\t\tPENGARANG: ");
            fgets(temp.pengarang, sizeof(temp.pengarang), stdin);
            printf("\t\t\t\t\t\t\tKATEGORI: ");
            fgets(temp.genre, sizeof(temp.genre), stdin);

            // Menghapus newline character
            temp.judul[strcspn(temp.judul, "\n")] = '\0';
            temp.pengarang[strcspn(temp.pengarang, "\n")] = '\0';
            temp.genre[strcspn(temp.genre, "\n")] = '\0';

            found = 1;
        }

        fprintf(tempFile, "%d %d %d %s %s %s\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("\n\033[031mBuku dengan kode %d tidak ditemukan.\n\n\033[0m", kodeBukuToEdit);
        remove("temp.txt");
    } else {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("\n\033[032mBuku dengan kode %d berhasil diedit.\n\n\033[0m", kodeBukuToEdit);
    }
}

void hapusBuku(char *breadcrumb, int kodeBukuToDelete) {
    printf("\n\n\t\t\t\t\t\t\tMasukkan kode buku yang ingin dihapus: ");
    scanf("%d", &kodeBukuToDelete);

    if (!isKodeBukuExists(kodeBukuToDelete)) {
        printf("\n\t\t\t\t\t\t\t\033[031mBuku dengan kode %d tidak ditemukan.\n\n\033[0m", kodeBukuToDelete);
        return;
    }

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Gagal membuat file sementara.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    struct library temp;
    int found = 0;

    while (fscanf(file, "%d %d %d %[^\n] %[^\n] %[^\n]\n", &temp.kode, &temp.tahun, &temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre) == 6) {
        if (temp.kode == kodeBukuToDelete) {
            printf("\nData Buku yang akan dihapus:\n");
            printf("============================================================================================================================================================\n");
            printf("| %-10s | %-10s | %-15s | %-50s | %-30s | %-22s |\n", "Kode", "Tahun", "Jumlah Buku", "Judul", "Pengarang", "Genre");
            printf("============================================================================================================================================================\n");
            printf("| %-10d | %-10d | %-15d | %-50s | %-30s | %-22s |\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
            printf("============================================================================================================================================================\n");

            found = 1;
        } else {
            fprintf(tempFile, "%d %d %d %s %s %s\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("\n\033[031mBuku dengan kode %d tidak ditemukan.\n\n\033[0m", kodeBukuToDelete);
        remove("temp.txt");
    } else {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("\n\033[032mBuku dengan kode %d berhasil dihapus.\n\n\033[0m", kodeBukuToDelete);
    }
}

int isKodeBukuExists(int kode) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    struct library temp;
    while (fscanf(file, "%d %d %d", &temp.kode, &temp.tahun, &temp.jumlahBuku) == 3) {
        fgets(temp.judul, sizeof(temp.judul), file);
        fgets(temp.pengarang, sizeof(temp.pengarang), file);
        fgets(temp.genre, sizeof(temp.genre), file);

        if (temp.kode == kode) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void historyPeminjaman(char *breadcrumb) {
    FILE *filePeminjaman = fopen(PEMINJAMAN_FILE, "r");
    if (filePeminjaman == NULL) {
        printf("Error: Gagal membuka file peminjaman.\n");
        exit(EXIT_FAILURE);
    }

    struct peminjaman pinjaman;
    printf("\n");
    printf("\n============================================================================================================================================================\n");
    printf("| %-30s | %-50s | %-20s | %-20s |\n", "Nama Peminjam", "Judul Buku", "Tanggal Pinjam", "Tanggal Kembali");
    printf("============================================================================================================================================================\n");

    while (fscanf(filePeminjaman, "%[^|]|%[^|]|%[^|]|%[^\n]\n", pinjaman.namaPeminjam, pinjaman.judulBuku, pinjaman.tanggalPinjam, pinjaman.tanggalKembali) == 4) {
        printf("| %-30s | %-50s | %-20s | %-20s |\n",
               pinjaman.namaPeminjam, pinjaman.judulBuku, pinjaman.tanggalPinjam, pinjaman.tanggalKembali);
    }

    printf("============================================================================================================================================================\n");
    fclose(filePeminjaman);
}

void tampilanMenuPengunjung(char *breadcrumb) {
    FILE *file = fopen(FILE_NAME, "a+");
    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }
    
    fclose(file);
    
    int opsi, lanjutkanProgram;
    
    do {
        printf ("%s", breadcrumb);
        printf("\033[1;31m");
        drawBox(155);
        printf("\t\t\t\t\t\t\t\t\t MENU PENGUNJUNG ");
        drawBox(155);
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n");
        printf ("\t\t\t\t\t\t\t\t| Apa yang ingin anda lakukan?|\n");
        printf(" \t\t\t\t\t\t\t\t==============================\n");
        printf ("\t\t\t\t\t\t\t\t| 1 | Menampilkan Daftar Buku |\n");
        printf ("\t\t\t\t\t\t\t\t| 2 | Cari Buku               |\n");
        printf ("\t\t\t\t\t\t\t\t| 3 | Pinjam Buku             |\n");
        printf ("\t\t\t\t\t\t\t\t| 4 | Mengembalikan Buku      |\n");
        printf ("\t\t\t\t\t\t\t\t| 5 | Keluar dari program     |\n");
        printf(" \t\t\t\t\t\t\t\t==============================\n");
        printf ("\t\t\t\t\t\t\t\tPilihan anda adalah: ");
        scanf ("%d",&opsi);
        Sleep (600);
        system ("cls");

        switch (opsi) {
            case 1:
   	            strcat(breadcrumb, " Daftar Buku >");
                printf("%s", breadcrumb);
                drawBox(155);
                printf("\t\t\t\t\t\t\t\t\t DAFTAR BUKU ");
                drawBox(155);
                daftarBuku(breadcrumb);
                break;

            case 2:
                strcat(breadcrumb, " Cari Buku >");
                printf("%s", breadcrumb);
                drawBox(155);
                printf("\t\t\t\t\t\t\t\t\t CARI BUKU ");
                drawBox(155);
                cariBuku(breadcrumb);
                break;

            case 3:
                strcat(breadcrumb, " Pinjam Buku >");
                printf("%s", breadcrumb);
                drawBox(155);
                printf("\t\t\t\t\t\t\t\t\t PEMINJAMAN BUKU ");
                drawBox(155);
                peminjamanBuku(breadcrumb);
                break;

            case 4:
                strcat(breadcrumb, " Kembalikan Buku >");
                printf("%s", breadcrumb);
                drawBox(155);
                printf("\t\t\t\t\t\t\t\t\t PENGEMBALIAN BUKU ");
                drawBox(155);
                pengembalianBuku(breadcrumb);
                break;

            case 5:
            	lanjutkanProgram = 0;
				printf("\033[1;36m");
            	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            	drawBox(155);
                printf ("\t\t\t\t\t\t\t\tTERIMAKASIH! KELUAR DARI PROGRAM");
                drawBox(155);
				while (getchar() != '\n');
                break;

            default:
                printf ("\t\t\t\t\t\t\t\t\033[031mMASUKAN PILIHAN YANG VALID\n\033[0m");
        }
        
        if (opsi != 5) {
            do {
                printf("\n\t\t\t\t\t\t\tApakah Anda ingin melanjutkan program? (1: Ya, 0: Tidak): ");
                scanf("%d", &lanjutkanProgram);
                Sleep(600);
                system("cls");

                if (lanjutkanProgram != 0 && lanjutkanProgram != 1) {
                    printf("MASUKAN INPUTAN YANG VALID\n");
                } if (lanjutkanProgram == 0) {
				printf("\033[1;36m");
            	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            	drawBox(155);
                printf ("\t\t\t\t\t\t\tTERIMAKASIH! KELUAR DARI PROGRAM");
                drawBox(155);
				}
            } while (lanjutkanProgram != 0 && lanjutkanProgram != 1);
        }
    } while (lanjutkanProgram == 1);
}

void toLowerCase(char *str) {
	int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void cariBuku(char *breadcrumb) {
    printf("%s", breadcrumb);
    char judulCari[MAX_CHAR];
    getchar();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tMasukkan judul buku yang ingin dicari: ");
    fgets(judulCari, sizeof(judulCari), stdin);

    judulCari[strcspn(judulCari, "\n")] = '\0';
    toLowerCase(judulCari);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    printf("\n\nHasil Pencarian:\n");
    printf("============================================================================================================================================================\n");
    printf("| %-10s | %-10s | %-15s | %-50s | %-30s | %-22s |\n", "Kode", "Tahun", "Jumlah Buku", "Judul", "Pengarang", "Genre");
    printf("============================================================================================================================================================\n");

    struct library temp;
    int adaBuku = 0; // Flag untuk menandai apakah ada buku yang cocok

    while (fscanf(file, "%d %d %d %[^\n] %[^\n] %[^\n]\n", &temp.kode, &temp.tahun, &temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre) == 6) {
        toLowerCase(temp.judul);

        // Menggunakan strstr untuk mencocokkan substring judulCari dalam judul
        if (strstr(temp.judul, judulCari) != NULL) {
            if (!adaBuku) {
                adaBuku = 1;
            }
            printf("| %-10d | %-10d | %-15d | %-50s | %-30s | %-22s |\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
        }
    }

    if (!adaBuku) {
        printf("| %-122s |\n", "Tidak ada buku yang cocok.");
    }

    printf("============================================================================================================================================================\n");

    // Cetak judulCari dan judul setiap kali ada pencocokan atau setelah loop selesai
    printf("JudulCari: %s, Judul: %s\n", judulCari, temp.judul);

    fclose(file);
}

bool isBukuAvailable(const char *judulBuku) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    struct library temp;
    while (fscanf(file, "%*d %*d %*d %[^\n]s %*s %*s\n", temp.judul) == 1) {
        toLowerCase(temp.judul);
        toLowerCase(judulBuku);

        if (strstr(temp.judul, judulBuku) != NULL) {
            fclose(file);
            return true; // Buku tersedia
        }
    }

    fclose(file);
    return false; // Buku tidak tersedia
}

void peminjamanBuku(char *breadcrumb) {
    printf("%s", breadcrumb);

    struct peminjaman pinjaman;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNAMA PEMINJAM (NAMA PANJANG): ");
    scanf(" %[^\n]", pinjaman.namaPeminjam);

    // Loop hingga judul buku tersedia
    do {
        printf("\t\t\t\t\t\t\tJUDUL BUKU YANG DIPINJAM: ");
        scanf(" %[^\n]", pinjaman.judulBuku);

        if (!isBukuAvailable(pinjaman.judulBuku)) {
            printf("\n\t\t\t\t\t\t\t\033[031mBuku '%s' tidak tersedia. Masukkan judul buku lain.\n\n\033[0m", pinjaman.judulBuku);
        }
    } while (!isBukuAvailable(pinjaman.judulBuku));

    time_t waktuSekarang;
    struct tm *waktuLocal;

    time(&waktuSekarang);
    waktuLocal = localtime(&waktuSekarang);

    strftime(pinjaman.tanggalPinjam, sizeof(pinjaman.tanggalPinjam), "%Y-%m-%d", waktuLocal);

    struct tm waktuKembali = *waktuLocal;
    waktuKembali.tm_mday += 1; 
    mktime(&waktuKembali);

    strftime(pinjaman.tanggalKembali, sizeof(pinjaman.tanggalKembali), "%Y-%m-%d", &waktuKembali);
    tambahPeminjaman(pinjaman.namaPeminjam, pinjaman.judulBuku, pinjaman.tanggalPinjam, pinjaman.tanggalKembali);

    printf("\n\t\t\t\t\t\t\t\033[032mBUKU '%s' BERHASIL DIPINJAM OLEH %s.\n", pinjaman.judulBuku, pinjaman.namaPeminjam);
    printf("\t\t\t\t\t\t\tTANGGAL PEMINJAMAN: %s\n", pinjaman.tanggalPinjam);
    printf("\t\t\t\t\t\t\tTANGGAL HARUS DIKEMBALIKAN: %s\n\n\033[0m", pinjaman.tanggalKembali);
}

void tambahPeminjaman(const char *namaPeminjam, const char *judulBuku, const char *tanggalPinjam, const char *tanggalKembali) {
    FILE *file = fopen(PEMINJAMAN_FILE, "a");
    if (file == NULL) {
        printf("Error: Gagal membuka file peminjaman.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s|%s|%s|%s\n", namaPeminjam, judulBuku, tanggalPinjam, tanggalKembali);
    fclose(file);
}

bool parseDate(const char *dateString, struct tm *result) {
    memset(result, 0, sizeof(struct tm));

    if (sscanf(dateString, "%d-%d-%d", &result->tm_year, &result->tm_mon, &result->tm_mday) != 3) {
        return false;
    }

    result->tm_year -= 1900;
    result->tm_mon--;

    return true;
}

void pengembalianBuku(char *breadcrumb) {
    printf("%s", breadcrumb);

    char namaPeminjam[MAX_CHAR];
    char judulBuku[MAX_CHAR];
    getchar();

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNAMA PEMINJAM: ");
    scanf(" %[^\n]", namaPeminjam);

    printf("\t\t\t\t\t\t\tJUDUL BUKU YANG DIKEMBALIKAN: ");
    scanf(" %[^\n]", judulBuku);

    time_t waktuSekarang;
    struct tm *waktuLocal;

    time(&waktuSekarang);
    waktuLocal = localtime(&waktuSekarang);

    char tanggalKembali[MAX_CHAR];
    strftime(tanggalKembali, sizeof(tanggalKembali), "%Y-%m-%d", waktuLocal);

    FILE *filePeminjaman = fopen(PEMINJAMAN_FILE, "r");
    if (filePeminjaman == NULL) {
        printf("Error: Gagal membuka file peminjaman.\n");
        exit(EXIT_FAILURE);
    }

    bool bukuDitemukan = false;
    struct peminjaman pinjaman;

    while (fscanf(filePeminjaman, "%[^|]|%[^|]|%[^|]|%[^\n]\n", pinjaman.namaPeminjam, pinjaman.judulBuku, pinjaman.tanggalPinjam, pinjaman.tanggalKembali) == 4) {
        if (strcmp(pinjaman.namaPeminjam, namaPeminjam) == 0 && strcmp(pinjaman.judulBuku, judulBuku) == 0) {
            bukuDitemukan = true;
            break;
        }
    }

    fclose(filePeminjaman);

    if (!bukuDitemukan) {
        printf("\n\t\t\t\t\t\t\t\033[031mBUKU DENGAN JUDUL '%s' TIDAK DITEMUKAN ATAU TIDAK SEDANG DIPINJAM OLEH %s.\n\n\033[0m", judulBuku, namaPeminjam);
        return;
    }

    hitungDenda(pinjaman.tanggalKembali);
    hapusPeminjaman(namaPeminjam, judulBuku);

    printf("\n\t\t\t\t\t\t\t\033[032mBUKU '%s' BERHASIL DIKEMBALIKAN OLEH %s.\n", judulBuku, namaPeminjam);
    printf("\t\t\t\t\t\t\tTANGGAL PENGEMBALIAN: %s\n\n\033[0m", tanggalKembali);
}

void hapusPeminjaman(const char *namaPeminjam, const char *judulBuku) {
    FILE *filePeminjaman = fopen(PEMINJAMAN_FILE, "r");
    FILE *tempFile = fopen("temp_peminjaman.txt", "w");

    if (filePeminjaman == NULL || tempFile == NULL) {
        printf("Error: Gagal membuka file peminjaman atau file sementara.\n");
        exit(EXIT_FAILURE);
    }

    struct peminjaman pinjaman;

    while (fscanf(filePeminjaman, "%[^|]|%[^|]|%[^|]|%[^\n]\n", pinjaman.namaPeminjam, pinjaman.judulBuku, pinjaman.tanggalPinjam, pinjaman.tanggalKembali) == 4) {
        if (strcmp(pinjaman.namaPeminjam, namaPeminjam) != 0 || strcmp(pinjaman.judulBuku, judulBuku) != 0) {
            fprintf(tempFile, "%s|%s|%s|%s\n", pinjaman.namaPeminjam, pinjaman.judulBuku, pinjaman.tanggalPinjam, pinjaman.tanggalKembali);
        }
    }

    fclose(filePeminjaman);
    fclose(tempFile);

    remove(PEMINJAMAN_FILE);
    rename("temp_peminjaman.txt", PEMINJAMAN_FILE);
}

void hitungDenda(const char *tanggalKembali) {
    time_t waktuSekarang;
    struct tm *waktuLocal;

    time(&waktuSekarang);
    waktuLocal = localtime(&waktuSekarang);

    char tanggalSekarang[MAX_CHAR];
    strftime(tanggalSekarang, sizeof(tanggalSekarang), "%Y-%m-%d", waktuLocal);

    struct tm t1, t2;

    if (!parseDate(tanggalSekarang, &t1) || !parseDate(tanggalKembali, &t2)) {
        printf("Error: Gagal mengonversi tanggal.\n");
        exit(EXIT_FAILURE);
    }

    time_t hariSekarang = mktime(&t1);
    time_t hariKembali = mktime(&t2);

    int selisihHari = (int)difftime(hariSekarang, hariKembali) / (60 * 60 * 24);

    if (selisihHari > 0) {
        int denda = selisihHari * DENDA_PER_HARI;
        printf("\n\t\t\t\t\t\t\t\033[031mBUKU TERLAMBAT DIKEMBALIKAN! DENDA: Rp%d\n\033[0m", denda);
    }
}