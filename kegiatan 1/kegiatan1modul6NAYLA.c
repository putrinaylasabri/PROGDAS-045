#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 100
#define FILE_NAME "library_books.txt"

struct Book {
    char id[MAX_CHAR];
    char title[MAX_CHAR];
    char author[MAX_CHAR];
    char pages[MAX_CHAR];
    char genre[MAX_CHAR];
};

void display_menu();
void create_book();
void display_books();
void update_book();
void delete_book();
int check_duplicate_id(const char* book_id);

int main() {
    printf("Selamat datang di Program CRUD Buku\n");
    printf("Program ini digunakan untuk mengelola informasi buku.\n");

    FILE *file = fopen(FILE_NAME, "a+");
    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }
    fclose(file);

    int choice;
    do {
        display_menu();
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                update_book();
                break;
            case 4:
                delete_book();
                break;
            case 5:
                printf("Terima kasih telah menggunakan program CRUD Buku.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 5);

    return 0;
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Tambah Buku Baru\n");
    printf("2. Tampilkan Daftar Buku\n");
    printf("3. Update Informasi Buku\n");
    printf("4. Hapus Buku\n");
    printf("5. Keluar\n");
}

void create_book() {
    struct Book new_book;

    printf("Masukkan ID Buku: ");
    fgets (new_book.id, sizeof(new_book.id), stdin);

    if (check_duplicate_id(new_book.id)) {
        printf("ID SUDAH TERDAFTAR\n");
        return;
    }

    printf("Masukkan Judul Buku: ");
    scanf("%s", new_book.title);
    printf("Masukkan Nama Author: ");
    scanf("%s", new_book.author);
    printf("Masukkan Jumlah Halaman: ");
    scanf("%s", new_book.pages);
    printf("Masukkan Genre Buku: ");
    scanf("%s", new_book.genre);

    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s,%s,%s,%s,%s\n", new_book.id, new_book.title, new_book.author, new_book.pages, new_book.genre);
    fclose(file);

    printf("Buku berhasil ditambahkan.\n");
}

void display_books() {
    struct Book book;
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nDaftar Buku:\n");
    printf("ID\t\tJudul\t\tAuthor\t\tHalaman\t\tGenre\n");
    printf("-------------------------------------------------------------------------\n");

    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", book.id, book.title, book.author, book.pages, book.genre) != EOF) {
        printf("%s\t\t%s\t%s\t%s\t\t%s\n", book.id, book.title, book.author, book.pages, book.genre);
    }

    fclose(file);
}

void update_book() {
    struct Book updated_book;
    char target_id[MAX_CHAR];
    int found = 0;

    printf("Masukkan ID Buku yang ingin diupdate: ");
    scanf("%s", target_id);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Error: Gagal membuat file sementara.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", updated_book.id, updated_book.title, updated_book.author, updated_book.pages, updated_book.genre) != EOF) {
        if (strcmp(updated_book.id, target_id) == 0) {
            found = 1;

            printf("Masukkan informasi baru untuk buku %s:\n", target_id);
            printf("Masukkan Judul Buku: ");
            scanf("%s", updated_book.title);
            printf("Masukkan Nama Author: ");
            scanf("%s", updated_book.author);
            printf("Masukkan Jumlah Halaman: ");
            scanf("%s", updated_book.pages);
            printf("Masukkan Genre Buku: ");
            scanf("%s", updated_book.genre);
        }

        fprintf(temp_file, "%s,%s,%s,%s,%s\n", updated_book.id, updated_book.title, updated_book.author, updated_book.pages, updated_book.genre);
    }

    fclose(file);
    fclose(temp_file);

    if (!found) {
        printf("Buku dengan ID %s tidak ditemukan.\n", target_id);
        remove("temp.txt");  // menghapus file semenstara arna buku tidak ditemukan
    } else {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Informasi buku berhasil diupdate.\n");
    }
}


void delete_book() {
    struct Book book;
    char delete_id[MAX_CHAR];

    printf("Masukkan ID Buku yang akan dihapus: ");
    scanf("%s", delete_id);

    FILE *temp_file = fopen("temp.txt", "w");
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL || temp_file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    int found = 0;

    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", book.id, book.title, book.author, book.pages, book.genre) != EOF) {
        if (strcmp(book.id, delete_id) == 0) {
            found = 1;
        } else {
            fprintf(temp_file, "%s,%s,%s,%s,%s\n", book.id, book.title, book.author, book.pages, book.genre);
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Buku dengan ID %s berhasil dihapus.\n", delete_id);
    } else {
        printf("Buku dengan ID %s tidak ditemukan.\n", delete_id);
    }
}


int check_duplicate_id(const char* book_id) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        exit(EXIT_FAILURE);
    }

    struct Book current_book;
    while (fscanf(file, "%[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n", current_book.id) != EOF) {
        if (strcmp(current_book.id, book_id) == 0) {
            fclose(file);
            return 1;  // ID sudah terdaftar
        }
    }

    fclose(file);
    return 0;  // ID belum terdaftar
}