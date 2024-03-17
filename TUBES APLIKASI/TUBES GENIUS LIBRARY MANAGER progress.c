#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#define FILE_NAME1 "daftaruser.txt"
#define FILE_NAME "daftarbuku.txt"
#define MAX_CHAR 200

struct library {
    int kode;
    int tahun;
    int jumlahBuku;
    char judul[MAX_CHAR];
    char pengarang[MAX_CHAR];
    char genre[MAX_CHAR];
    char username[MAX_CHAR];
    int password;
};

void loadingBar(int duration, int width);
void tampilanMenu();
void tambahUser();
//fungsi untuk petugas perpustakaan 
void tambahBuku();
void daftarBuku();
void editBuku();
void hapusBuku();
//fungsi untuk pengunjung
void cariBuku();
void peminjamanBuku();
void pengembalianBuku();
void cekDenda();
bool check_duplicate_user(char *username, char *password);
int check_duplicate_id(const int* library_kode);

int main () {
    printf ("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\033[7mSELAMAT DATANG DI APLIKASI MANAJEMEN PERPUSTAKAAN");
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    loadingBar(10, 155);
    system ("cls");
    tambahBuku();
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

/*void tambahUser () {
    struct library library_user;

    printf ("Masukan nama anda: ");
    fgets (library_user.nama, sizeof(library_user.nama), stdin);
    printf ("\nMasukan NIM anda: ");
    scanf ("%d", &library_user.password);
    fclose(file);
    printf ("Data anda berhasil ditambahkan!\n");

    //check duplikasi
    if (!check_duplicate_user(library_user.username, library_user.password)) {
        return;
    }

    FILE *file = fopen (FILE_NAME1, "a");
    if (file == NULL) {
        printf ("FILE GAGAL DIBUKA");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Nama: %sNIM: %d\n", library_user.username, library_user.password);
    fclose(file);
    printf ("Data berhasil ditambahkan!");
    tampilanMenu();
}

bool check_duplicate_user (char *username, char *password) {
    FILE *file = fopen (FILE_NAME1, "r");
    if (file == NULL) {
        printf ("FILE GAGAL DIBUKA\n");
        return false;
    }

    //check nim/nama duplikat
    char buffer [100];
    while (fgets(buffer, sizeof(buffer),file)!= NULL) {
        if (strstr(buffer, username)!= NULL || strstr(buffer, password) != NULL) {
            printf ("Nama atau NIM sudah ada\n");
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}*/

void tampilanMenu() {
    int opsi;
    printf ("Apa yang ingin anda lakukan?\n");
    printf ("1. Tambah Buku\n");
    printf ("2. Daftar Buku\n");
    printf ("3. Edit Informasi Buku\n");
    printf ("4. Hapus Buku\n");
    printf ("5. Cari Buku\n");
    printf ("6. Pinjam Buku\n");
    printf ("7. Cek Denda\n");
    printf ("Pilihan anda adalah: ");
    scanf ("%d",&opsi);

    switch (opsi) {
        case 1:
        tambahBuku();
        break;

        case 2:
        daftarBuku();
        break;

        case 3:
        editBuku();
        break;

        case 4:
        hapusBuku();
        break;

        case 5:
        cariBuku();
        break;

        case 6:
        peminjamanBuku();
        break;

        case 7:
        pengembalianBuku();
        break;

        case 8:
        cekDenda();

        default:
        printf ("MASUKAN PILIHAN YANG VALID\n");
    }
    }

    void tambahBuku()
    {
        struct library add_library;
        printf ("Masukan kode ISBN buku: ");
        scanf ("%s", add_library.kode);

        //check isbn  
        if (check_duplicate_id(add_library.kode)) {
        printf("ISBN SUDAH TERDAFTAR\n");
        return;
    }

        printf ("Masukan judul buku: ");
        fgets (add_library.judul, sizeof(add_library.judul), stdin);
        printf ("Masukan nama pengarang: ");
        fgets (add_library.pengarang, sizeof(add_library.pengarang), stdin);
        printf ("Masukan genre buku: ");
        fgets (add_library.genre, sizeof(add_library.genre), stdin);
        printf ("Masukan tahun terbit buku: ");
        scanf ("%d", &add_library.tahun);
        printf ("Masukan jumlah stok buku: ");
        scanf ("%d", add_library.jumlahBuku);

        FILE *file = fopen (FILE_NAME, "a");
        if (file == NULL) {
            printf ("FILE GAGAL DIBUKA");
            exit(EXIT_FAILURE);
        }

        fprintf(file, "%d, %s, %s, %s, %d, %d\n",add_library.kode, add_library.judul, add_library.pengarang, add_library.genre, add_library.tahun, add_library.jumlahBuku);
        fclose(file);
        
        printf("Buku berhasil ditambahkan.\n");
    }

    void daftarBuku()
    {
        struct library display_library;
        FILE *file = fopen(FILE_NAME, "r");

        if (file == NULL) {
            printf ("FILE GAGAL DIBUKA");
            exit(EXIT_FAILURE);
        }

        printf("\nDaftar Buku:\n");
        printf("----------------------------------------------------------------------------------------\n");
        printf("| %-2s | %-30s | %-20s | %-8s | %-15s |\n", "ID", "Judul", "Author", "Halaman", "Genre");
        printf("----------------------------------------------------------------------------------------\n");

    // Tampilkan data buku dari file
    while (fscanf(file, "%d, %[^,],%[^,],%[^,],%d,%d\n]\n",display_library.kode, display_library.judul, display_library.pengarang, display_library.genre, &display_library.tahun, &display_library.jumlahBuku) != EOF) {
        printf("|  $-2s  | %-2s | %-30s | %-20s | %-8s | %-15s |\n", display_library.kode, display_library.judul, display_library.pengarang, display_library.genre, display_library.tahun, display_library.jumlahBuku);
    }
    fclose(file);
    printf("----------------------------------------------------------------------------------------\n");

    }

    void editBuku()
    {
        struct library edit_library;
        char target_kode[MAX_CHAR];
        int found = 0;

        printf("Masukkan ID Buku yang ingin diupdate: ");
        scanf("%s", target_kode);

        FILE *file = fopen (FILE_NAME, "r");
        if (file == NULL) {
            printf ("FILE GAGAL DIBUKA");
            exit(EXIT_FAILURE);
        }

        FILE *temp_file = fopen ("temporary.txt", "w");
        if (temp_file == NULL) {
            printf ("FILE GAGAL DIBUKA");
            exit(EXIT_FAILURE);
        }

        while (fscanf(file, "%d, %[^,],%[^,],%[^,],%d,%d\n]\n", edit_library.kode, edit_library.judul, edit_library.pengarang, edit_library.genre, edit_library.tahun, edit_library.jumlahBuku) != EOF) {
        if (strcmp(edit_library.kode, target_kode) == 0) {
            found = 1;

            printf("Masukkan informasi baru untuk buku %s:\n", target_kode);
            printf("Masukkan Judul Buku: ");
            fgets (edit_library.kode, sizeof(edit_library.kode), stdin);
            printf("Masukkan Nama Pengarang: ");
            fgets (edit_library.pengarang, sizeof(edit_library.pengarang), stdin);
            printf("Masukkan Genre Buku: ");
            fgets (edit_library.genre, sizeof (edit_library.genre), stdin);
            printf("Masukkan Tahun Terbit: ");
            scanf("%d", &edit_library.tahun);
            printf("Masukkan Jumlah Stok Buku: ");
            scanf("%d", &edit_library.jumlahBuku);
        }

        fprintf(temp_file, "%d,%s,%s,%s,%d,%d\n", edit_library.kode, edit_library.judul, edit_library.pengarang, edit_library.genre, edit_library.tahun, edit_library.jumlahBuku);
    }

    fclose(file);
    fclose(temp_file);

    if (!found) {
        printf("Buku dengan ID %s tidak ditemukan.\n", target_kode);
        remove("temporary.txt");
    } else {
        remove(FILE_NAME);
        rename("temporary.txt", FILE_NAME);
        printf("Informasi buku berhasil diupdate.\n");
    }
}

    void hapusBuku()
    {
        struct library delete_library;
        int delete_kode;

        printf ("Masukan kode buku yang akan dihapus");
        scanf ("%s", delete_kode);

        FILE *temp_file = fopen("temporary.txt", "w");
        FILE *file = fopen(FILE_NAME, "r");

        if (file == NULL || temp_file == NULL) {
            printf ("FILE GAGAL DIBUKA");
            exit(EXIT_FAILURE);
        }

        int found = 0;
        while (fscanf(file, "%d,%[^,],%[^,],%[^,],%d, %d\n]\n", delete_library.kode, delete_library.judul, delete_library.pengarang, delete_library.genre, &delete_library.tahun, &delete_library.jumlahBuku) != EOF) {
        if (strcmp(delete_library.kode, delete_kode) == 0) {
            found = 1;
        } else {
            fprintf(temp_file, "%d,%s,%s,%s,%d, %d\n", delete_library.kode, delete_library.judul, delete_library.pengarang, delete_library.genre, &delete_library.tahun, &delete_library.jumlahBuku);
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(FILE_NAME);
    rename("temporary.txt", FILE_NAME);

    if (found) {
        printf("Buku dengan ID %s berhasil dihapus.\n", delete_kode);
    } else {
        printf("Buku dengan ID %s tidak ditemukan.\n", delete_kode);
    }
}

    void cariBuku()
    {

    }

    void peminjamanBuku()
    {

    }

    void pengembalianBuku()
    {
        
    }

    void cekDenda()
    {

    }
