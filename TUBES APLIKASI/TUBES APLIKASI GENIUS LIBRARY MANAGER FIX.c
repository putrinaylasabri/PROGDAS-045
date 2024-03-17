#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.Ah>
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
void opsi(char *breadcrumb);
bool loginPetugas(char *breadcrumb);
bool isKodeBukuExists(int kode);

//fungsi untuk petugas perpustakaan 
void tampilanMenuPetugas(char *breadcrumb);
void tambahBuku(char *breadcrumb);
void daftarBuku(char *breadcrumb);
void editBuku(char *breadcrumb);
void hapusBuku(char *breadcrumb, int kodeBuku);

//fungsi untuk pengunjung
void tampilanMenuPengunjung(char *breadcrumb);
void toLowerCase(char *str);
void cariBuku(char *breadcrumb);
void peminjamanBuku(char *breadcrumb);
void tambahPeminjaman(const char *namaPeminjam, const char *judulBuku, const char *tanggalPinjam, const char *tanggalKembali);
bool parseDate(const char *dateString, struct tm *result);
void pengembalianBuku(char *breadcrumb);
void hitungDenda(const char *tanggalKembali);
void hapusPeminjaman(const char *namaPeminjam, const char *judulBuku);
char breadcrumb[MAX_CHAR] = "Beranda >";

int main() {
    system("cls");
    setConsoleColor(10); // Hijau
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\033[7m\033[1mSELAMAT DATANG DI APLIKASI MANAJEMEN PERPUSTAKAAN");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    loadingBar(10, 155);
    
    system("cls");
    setConsoleColor(14); // Kuning
    opsi(breadcrumb);
    
    Sleep(500);
    
    loadingBar(10, 155);
    system("cls");
    
    setConsoleColor(11); // Cyan
    tampilanMenuPetugas(breadcrumb);
    
    return 0;
}

void loadingBar(int duration, int width) {
    int i;
    for (i = 0; i < width; i++) {
        setConsoleColor(10); // Hijau
        printf("\xdb");
        Sleep(duration);
    }
    printf("\n");
}

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawBox(int width) {
	int i;
    printf("\n");
    for (i = 0; i < width; i++) {
        printf("\033[0;34m\xdb\033[0m");  // Blue box
    }
    printf("\n");
}

void opsi(char *breadcrumb) {
    int opsi;
    system("cls");

    // Header
    printf("\033[1;36m");  // Cyan header
    drawBox(155);
    printf("\t\t\t\t\t\t\t SELAMAT DATANG DI APLIKASI PERPUSTAKAAN ");
    drawBox(155);
    printf("\n\n");

    // Opsi menu
    printf("\033[1;33m");  // Yellow text
    printf(" \t\t\t\t\t\t\t==============================\n");
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
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tMasukkan username khusus petugas: ");
        scanf("%s", username);
        
        printf("\t\t\t\t\t\t\tMasukkan Password: ");
        while (1) {
            ch = getch();
            if (ch == 13)
                break;
            password[i++] = ch;
            printf("*");
        }
        password[i] = '\0';

        if (strcmp(password, expectedPassword) == 0 && strcmp(username, expectedUsername) == 0) {
            printf("\n\033[033m\t\t\t\t\t\t\tANDA BERHASIL LOGIN!\033[0m\n");
            return true;  
        } else {
            printf("\n\033[031m\t\t\t\t\t\t\tPassword atau username salah! Silakan coba lagi.\n\n\033[0m");
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

    int opsi;
        printf ("%s", breadcrumb);
		printf("\n\n\t\t\t\t\t\t\t==============================\n");
        printf ("\t\t\t\t\t\t\t| Apa yang ingin anda lakukan?|\n");
		printf(" \t\t\t\t\t\t\t===============================\n");
        printf ("\t\t\t\t\t\t\t| 1 | Tambah Buku             | \n");
        printf ("\t\t\t\t\t\t\t| 2 | Daftar Buku             | \n");
        printf ("\t\t\t\t\t\t\t| 3 | Edit Informasi Buku     | \n");
        printf ("\t\t\t\t\t\t\t| 4 | Hapus Buku              | \n");
        printf ("\t\t\t\t\t\t\t| 5 | Keluar dari program     |\n");
		printf(" \t\t\t\t\t\t\t===============================\n");
        printf ("\t\t\t\t\t\t\tPilihan anda adalah: ");
        scanf ("%d",&opsi);
		while (getchar() != '\n');
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
				int kodeBukuToDelete;
				printf("Masukkan kode buku yang ingin dihapus: ");
				scanf("%d", &kodeBukuToDelete); 
				hapusBuku(breadcrumb, kodeBukuToDelete);
                break;

            case 5:
            	printf("\033[1;36m");
            	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            	drawBox(155);
                printf ("\t\t\t\t\t\t\tTERIMAKASIH! KELUAR DARI PROGRAM");
                drawBox(155);
                break;

            default:
                printf ("\t\t\t\t\t\t\t\033[031mMASUKAN PILIHAN YANG VALID\n\033[0m");
        }
}

void tambahBuku(char *breadcrumb) {
    printf("%s", breadcrumb);
    struct library add;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tMasukkan kode buku: ");
    scanf("%d", &add.kode);

    if (isKodeBukuExists(add.kode)) {
        printf("Kode buku sudah ada. Masukkan kode buku lain.\n");
        tambahBuku(breadcrumb);
        return;
    }

    printf("\t\t\t\t\t\t\tMasukkan tahun terbit: ");
    scanf("%d", &add.tahun);
    printf("\t\t\t\t\t\t\tMasukkan jumlah buku: ");
    scanf("%d", &add.jumlahBuku);
    printf("\t\t\t\t\t\t\tMasukkan judul: ");
    scanf(" %[^\n]s", add.judul); 
    printf("\t\t\t\t\t\t\tMasukkan pengarang: ");
    scanf(" %[^\n]s", add.pengarang); 
    printf("\t\t\t\t\t\t\tMasukkan genre: ");
    scanf(" %[^\n]s", add.genre); 

    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Gagal membuka file atau file tidak ditemukan. Membuat file baru...\n");
		exit(EXIT_FAILURE);
        }

    fprintf(file, "%d %d %d %s %s %s\n", add.kode, add.tahun, add.jumlahBuku, add.judul, add.pengarang, add.genre);
    fclose(file);
    printf("\n\t\t\t\t\t\t\t\033[033mBuku berhasil ditambahkan.\n\n\033\0m");
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

    printf("| %-10s | %-10s | %-15s | %-20s | %-20s | %-16s |\n", "Kode", "Tahun", "Jumlah Buku", "Judul", "Pengarang", "Genre");
    printf("|------------|------------|-----------------|----------------------|----------------------|------------------|\n");

    struct library temp;
    while (fscanf(file, "%d %d %d %s %s %s\n", &temp.kode, &temp.tahun, &temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre) == 6) {
        printf("| %-10d | %-10d | %-15d | %-20s | %-20s | %-16s |\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
    }

    fclose(file);
}

void editBuku(char *breadcrumb) {
    printf("%s", breadcrumb);
    int kodeBukuToEdit;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nMasukkan kode buku yang ingin diedit: ");
    scanf("%d", &kodeBukuToEdit);

    if (!isKodeBukuExists(kodeBukuToEdit)) {
        printf("\n\033[031mBuku dengan kode %d tidak ditemukan.\n\n\033[0m", kodeBukuToEdit);
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

    while (fscanf(file, "%d %d %d %s %s %s\n", &temp.kode, &temp.tahun, &temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre) == 6) {
        if (temp.kode == kodeBukuToEdit) {
            printf("\nData Lama:\n");
            printf("| %-10s | %-10s | %-15s | %-20s | %-20s | %-16s |\n", "Kode", "Tahun", "Jumlah Buku", "Judul", "Pengarang", "Genre");
            printf("|------------|------------|-----------------|----------------------|----------------------|------------------|\n");
            printf("| %-10d | %-10d | %-15d | %-20s | %-20s | %-16s |\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);

            printf("Masukkan data baru:\n");
            printf("Masukkan tahun terbit: ");
            scanf("%d", &temp.tahun);
            printf("Masukkan jumlah buku: ");
            scanf("%d", &temp.jumlahBuku);
            printf("Masukkan judul: ");
            scanf(" %[^\n]", temp.judul);
            printf("Masukkan pengarang: ");
            scanf(" %[^\n]", temp.pengarang);
            printf("Masukkan genre: ");
            scanf(" %[^\n]", temp.genre);

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


void hapusBuku(char *breadcrumb, int kodeBuku) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Gagal membuat file sementara.\n");
        exit(EXIT_FAILURE);
    }

    struct library temp;
    int found = 0;
    while (fscanf(file, "%d %d %d %s %s %s\n", &temp.kode, &temp.tahun, &temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre) == 6) {
        if (temp.kode != kodeBuku) {
            fprintf(tempFile, "%d %d %d %s %s %s\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("\n\033[031mBuku dengan kode %d tidak ditemukan.\n\n\033[0m", kodeBuku);
        remove("temp.txt"); 
    } else {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("\n\033[032mBuku dengan kode %d berhasil dihapus.\n\n\033[0m", kodeBuku);
    }
}

void tampilanMenuPengunjung(char *breadcrumb) {
    FILE *file = fopen(FILE_NAME, "a+");
    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    
    int opsi;
        printf ("%s", breadcrumb);
        printf("\n\n\t\t\t\t\t\t\t==============================\n");
        printf ("\t\t\t\t\t\t\t| Apa yang ingin anda lakukan?|\n");
        printf(" \t\t\t\t\t\t\t==============================\n");
        printf ("\t\t\t\t\t\t\t| 1 | Menampilkan Daftar Buku |\n");
        printf ("\t\t\t\t\t\t\t| 2 | Cari Buku               |\n");
        printf ("\t\t\t\t\t\t\t| 3 | Pinjam Buku             |\n");
        printf ("\t\t\t\t\t\t\t| 4 | Mengembalikan Buku      |\n");
        printf ("\t\t\t\t\t\t\t| 5 | Keluar dari program     |\n");
        printf(" \t\t\t\t\t\t\t==============================\n");
        printf ("\t\t\t\t\t\t\tPilihan anda adalah: ");
        scanf ("%d",&opsi);
        Sleep (600);
        system ("cls");

        switch (opsi) {
            case 1:
   	            strcat(breadcrumb, " Daftar Buku >");
                daftarBuku(breadcrumb);
                break;

            case 2:
                strcat(breadcrumb, " Cari Buku >");
                cariBuku(breadcrumb);
                break;

            case 3:
                strcat(breadcrumb, " Edit Buku >");
                peminjamanBuku(breadcrumb);
                break;

            case 4:
                strcat(breadcrumb, " Hapus Buku >");
                pengembalianBuku(breadcrumb);
                break;

            case 5:
            	printf("\033[1;36m");
            	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            	drawBox(155);
                printf ("\t\t\t\t\t\t\tTERIMAKASIH! KELUAR DARI PROGRAM");
                drawBox(155);
                break;

            default:
                printf ("MASUKAN PILIHAN YANG VALID\n");
        }
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
    printf("\n\nMasukkan judul buku yang ingin dicari: ");
    fgets(judulCari, sizeof(judulCari), stdin);

    judulCari[strcspn(judulCari, "\n")] = '\0';
    
    toLowerCase(judulCari);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    printf("\n\nHasil Pencarian:\n");
    printf("| %-10s | %-10s | %-15s | %-20s | %-20s | %-16s |\n", "Kode", "Tahun", "Jumlah Buku", "Judul", "Pengarang", "Genre");
    printf("|------------|------------|-----------------|----------------------|----------------------|------------------|\n");

    struct library temp;
    while (fscanf(file, "%d %d %d %s %s %s\n", &temp.kode, &temp.tahun, &temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre) == 6) {
        char judulTemp[MAX_CHAR];
        strcpy(judulTemp, temp.judul);
        toLowerCase(judulTemp);
        toLowerCase(judulCari);

        if (strstr(judulTemp, judulCari) != NULL) {
            printf("| %-10d | %-10d | %-15d | %-20s | %-20s | %-16s |\n", temp.kode, temp.tahun, temp.jumlahBuku, temp.judul, temp.pengarang, temp.genre);
        }
    }

    fclose(file);
}

void peminjamanBuku(char *breadcrumb) {
    printf("%s", breadcrumb);
    
    struct peminjaman pinjaman;

    printf("\n\nMasukkan nama peminjam: ");
    scanf(" %[^\n]", pinjaman.namaPeminjam);

    printf("Masukkan judul buku yang ingin dipinjam: ");
    scanf(" %[^\n]", pinjaman.judulBuku);
    
    time_t waktuSekarang;
    struct tm *waktuLocal;

    time(&waktuSekarang);
    waktuLocal = localtime(&waktuSekarang);

    strftime(pinjaman.tanggalPinjam, sizeof(pinjaman.tanggalPinjam), "%Y-%m-%d", waktuLocal);

    struct tm waktuKembali = *waktuLocal;
    waktuKembali.tm_mday += 4; 
    mktime(&waktuKembali);

    strftime(pinjaman.tanggalKembali, sizeof(pinjaman.tanggalKembali), "%Y-%m-%d", &waktuKembali);
    tambahPeminjaman(pinjaman.namaPeminjam, pinjaman.judulBuku, pinjaman.tanggalPinjam, pinjaman.tanggalKembali);

    printf("\n\033[032mBuku '%s' berhasil dipinjam oleh %s.\n", pinjaman.judulBuku, pinjaman.namaPeminjam);
    printf("Tanggal peminjaman: %s\n", pinjaman.tanggalPinjam);
    printf("Tanggal harus dikembalikan: %s\n\n\033[0m", pinjaman.tanggalKembali);
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

    printf("\n\nMasukkan nama peminjam: ");
    scanf(" %[^\n]", namaPeminjam);

    printf("Masukkan judul buku yang dikembalikan: ");
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
        printf("\n\033[031mBuku dengan judul '%s' tidak ditemukan atau tidak sedang dipinjam oleh %s.\n\n\033[0m", judulBuku, namaPeminjam);
        return;
    }

    hitungDenda(pinjaman.tanggalKembali);
    hapusPeminjaman(namaPeminjam, judulBuku);

    printf("\n\033[032mBuku '%s' berhasil dikembalikan oleh %s.\n", judulBuku, namaPeminjam);
    printf("Tanggal pengembalian: %s\n\n\033[0m", tanggalKembali);
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
        printf("\n\033[031mBuku terlambat dikembalikan! Denda: Rp%d\n\033[0m", denda);
    }
}