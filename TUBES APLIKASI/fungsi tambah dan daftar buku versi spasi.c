#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

#define filename "librarypedia.txt"
#define peminjaman "pemimjamanlibrary.txt"
#define max 100

struct library {
    int kode; 
    int rak;
    int halaman;
    int tahun;
    int jumlahBuku;
    char judul[max];
    char pengarang[max];
    char kategori[max];
};

/*struct peminjaman {
    char namaPeminjam[max];
    char judulBuku[max];
    char tanggalPinjam[max];
    char tanggalKembali[max];
};*/

//fungsi tampilan grafis
void setConsoleColor(int color);
void drawBox(int width);
void loadingBar(int duration, int width);
void printTextWithDelay(const char *text, int delay);
void opsi(char *breadcrumb);
char breadcrumb[max] = "Beranda >";

//fungsi petugas
bool loginPetugas();
void tampilanMenuPetugas (char *breadcrumb);

//fungsi pengunjung
void tampilanMenuPengunjung (char *breadcrumb);

int main()
{
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
        setConsoleColor(8); 
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

void opsi(char *breadcrumb)
{

}


bool loginPetugas(char *breadcrumb) {
    char expectedUsername[] = "geniuslibrary";
    char expectedPassword[] = "000000123";
    char username[max];
    char password[max];
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
            printf("\n\033[033m\t\t\t\t\t\t\tANDA BERHASIL LOGIN!\033[0m\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            loadingBar(10, 155);
            Sleep (600);
            system("cls");
            setConsoleColor(11); 
            tampilanMenuPetugas(breadcrumb);
            return true;  
        } else {
            printf("\n\033[031m\t\t\t\t\t\t\tPassword atau username salah! Silakan coba lagi.\n\n\033[0m");
        }
    } while (1);
}

void tampilanMenuPengunjung(char *breadcrumb)
{
	
}

void tampilanMenuPetugas(char *breadcrumb)
{

}

/*void tambahBuku(struct Buku **daftarBuku, int *jumlahBuku) {
	int i;
    struct Buku bukuBaru;
    
    FILE *file = fopen (filename, "a+");
    if (file == NULL) {
		printf ("FILE GAGAL DIBUKA");
		exit(EXIT_FAILURE);
	}

    // Input data buku
    printf("Masukkan kode buku: ");
    scanf("%d", &bukuBaru.kode);

    // Cek duplikasi
    for (i = 0; i < *jumlahBuku; i++) {
        if (bukuBaru.kode == (*daftarBuku)[i].kode) {
            printf("Kode buku sudah ada. Masukkan kode buku yang baru.\n");
            return;
        }
    }

    printf("Masukkan tahun terbit: ");
    scanf("%d", &bukuBaru.tahun_terbit);

    printf("Masukkan jumlah buku: ");
    scanf("%d", &bukuBaru.jumlah_buku);

    printf("Masukkan judul buku: ");
    scanf(" %[^\n]s", bukuBaru.judul);

    printf("Masukkan nama pengarang: ");
    scanf(" %[^\n]s", bukuBaru.pengarang);

    printf("Masukkan genre buku: ");
    scanf(" %[^\n]s", bukuBaru.genre);

    // Menambahkan buku ke dalam daftar
    *daftarBuku = realloc(*daftarBuku, (*jumlahBuku + 1) * sizeof(struct Buku));
    (*daftarBuku)[*jumlahBuku] = bukuBaru;
    (*jumlahBuku)++;

    printf("Buku berhasil ditambahkan.\n");
    fclose (file);
}

// Fungsi untuk menampilkan daftar buku
void tampilkanDaftarBuku(struct Buku *daftarBuku, int jumlahBuku) {
	int i;
	FILE *file = fopen (filename, "r");
	if (file == NULL) {
		printf ("FILE GAGAL DIBUKA");
		exit(EXIT_FAILURE);
	}
	
    printf("============================================================================================================================================================\n");
    printf("| %-10s | %-10s | %-15s | %-50s | %-30s | %-22s |\n", "Kode", "Tahun", "Jumlah Buku", "Judul", "Pengarang", "Genre");
    printf("============================================================================================================================================================\n");

    for (i = 0; i < jumlahBuku; i++) {
        printf("| %-10d | %-10d | %-15d | %-50s | %-30s | %-22s |\n",
               daftarBuku[i].kode, daftarBuku[i].tahun_terbit, daftarBuku[i].jumlah_buku,
               daftarBuku[i].judul, daftarBuku[i].pengarang, daftarBuku[i].genre);
    }

    printf("============================================================================================================================================================\n");
	fclose (file);
	}

int main() {
    struct Buku *daftarBuku = NULL;
    int jumlahBuku = 0;
    char pilihan;

    do {
        // Menampilkan menu
        printf("\nMenu:\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Daftar Buku\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf(" %c", &pilihan);

        // Memproses pilihan
        switch (pilihan) {
            case '1':
                tambahBuku(&daftarBuku, &jumlahBuku);
                break;
            case '2':
                tampilkanDaftarBuku(daftarBuku, jumlahBuku);
                break;
            case '3':
                free(daftarBuku); // Membebaskan memori sebelum keluar
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != '3');

    return 0;
}*/
