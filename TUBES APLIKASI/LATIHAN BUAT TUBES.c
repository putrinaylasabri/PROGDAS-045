#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NAME "bookpedia.txt"
#define MAX_CHAR 50

struct book {
	int kode;
	int jumlahBuku;
	int halaman;
	int tahun;
	char judul[MAX_CHAR];
	char pengarang[MAX_CHAR];
	char kategori[MAX_CHAR];
};

void textBerjalan();
void loading();
void opsiUtama (char *breadcrumb);
bool login();
void modePengunjung(char *breadcrumb);
char breadcrumb[MAX_CHAR] = "Beranda > ";

//mode petugas
void modePetugas(char *breadcrumb);
bool cekKodeBuku (int kode);
void tambahBuku (char *breadcrumb);
void daftarBuku (char *breadcrumb);
void editBuku (char *breadcrumb);
void hapusBuku (char *breadcrumb);
void historyPeminjaman (char *breadcrumb);

int main ()
{
	textBerjalan();
	loading();
	opsiUtama(breadcrumb);
	return 0;
}

void textBerjalan() {
	int i = 0;
	printf ("\n\n\n\n\n\n\n\t\t\t\t\t\t\t");
	const char *text = "HELLO! WELCOME TO GENIUS LIBRARY MANAGER";
	while (text[i]!='\0'){
		putchar(text[i]);
		Sleep(100);
		i++;
	}
}

void loading() {
	int a = 155;
	int i;
	printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for (i = 0; i < a; i++) {
		printf ("\xdb");
		Sleep(10);
	}
	system ("cls");
}

void opsiUtama(char *breadcrumb) {
	int opsi;
	printf ("%s", breadcrumb);
	printf ("\n\n\n\n\t\t\t\t\t\t\tSELAMAT DATANG DI APLIKASI SISTEM PERPUSTAKAAN!\n\n");
	printf ("\t\t\t\t\t\t\tApa posisi anda saat ini?\n");
	printf ("\t\t\t\t\t\t\t[1] Petugas\n");
	printf ("\t\t\t\t\t\t\t[2] Pengunjung\n");
	printf ("\t\t\t\t\t\t\tPilihan anda adalah: ");
	scanf ("%d", &opsi);
	
	if (opsi == 1) {
		login();
	} else if (opsi == 2) {
		strcat (breadcrumb, "Pengunjung >");
		modePengunjung(breadcrumb);
	} else {
		printf ("\nMASUKAN PILIHAN YANG VALID!");
	}
}

bool login() {
	system ("cls");
	char usernameAsli[] = "librarymanager";
	char passwordAsli[] = "1234567890";
	char username[MAX_CHAR];
	char password[MAX_CHAR];
	int i;
	char ch;
	
	do {
		i = 0;
		printf ("\n\t\t\t\t\t\t\tUSERNAME: ");
		scanf ("%s", username);
		
		printf ("\t\t\t\t\t\t\tPASSWORD: ");
		while(1) {
			ch = getch();
			if (ch == 13) {
				break;
			}
			password[i++] = ch;
			printf ("*");
		}
			password[i] ='\0';

			if (strcmp(usernameAsli, username) == 0 && strcmp (passwordAsli, password) == 0) {
				printf ("\n\t\t\t\t\t\t\tLOGIN BERHASIL!\n");
				Sleep(600);
				system ("cls");
				modePetugas(breadcrumb);
				return true;
			} else {
				Sleep(600);
				system("cls");
				printf ("\n\t\t\t\t\t\t\tUSERNAME ATAU PASSWORD TIDAK SESUAI, MASUKAN INPUTAN YANG VALID!");
			}
	} while (1);
}

void modePetugas(char *breadcrumb) {
	FILE *file = fopen (FILE_NAME, "a");
	if (file == NULL) {
		printf ("FILE GAGAL DIBUKA!");
		exit(EXIT_FAILURE);
	}
	
	int opsi, lanjutkanProgram;
	do {
	printf ("\n\t\t\t\t\t\t\tApa yang ingin anda lakukan?\n");
	printf ("\t\t\t\t\t\t\t[1] Tambah Buku\n");
	printf ("\t\t\t\t\t\t\t[2] Menampilkan Daftar Buku\n");
	printf ("\t\t\t\t\t\t\t[3] Edit Informasi Buku\n");
	printf ("\t\t\t\t\t\t\t[4] Hapus Buku\n");
	printf ("\t\t\t\t\t\t\t[5] Lihat History Peminjaman\n");
	printf ("\t\t\t\t\t\t\t[6] Keluar dari aplikasi\n");
	printf ("\t\t\t\t\t\t\tPilihan anda: ");
	scanf ("%d", &opsi);	
	
	switch (opsi) {
		case 1: 
			Sleep(600);
			system ("cls");
			strcat (breadcrumb, "Tambah Buku > ");
			tambahBuku(breadcrumb);
			break;
		
		case 2:
			strcat (breadcrumb, "Daftar Buku > ");
			daftarBuku(breadcrumb);
			break;
		
		case 3:
			strcat (breadcrumb, "Edit Buku > ");
			editBuku(breadcrumb);
			break;
		
		case 4:
			strcat (breadcrumb, "Hapus Buku > ");
			hapusBuku(breadcrumb);
			break;
		
		case 5:
			strcat (breadcrumb, "History Peminjaman > ");
			historyPeminjaman(breadcrumb);
			break;
		
		default:
			printf ("\nTERIMAKASIH SUDAH MENGGUNAKAN APLIKASI GENIUS LIBRARY MANAGER!\n");
			
			if (opsi != 6) {
				do {
					printf ("Apakah anda ingin melanjutkan program?");
					printf ("1 = Ya\n");
					printf ("0 = Tidak\n");
					scanf ("%d", &lanjutkanProgram);
					
					if (lanjutkanProgram != 0 && lanjutkanProgram != 1) {
						printf ("\nMASUKAN INPUT YANG VALID\n");
					} if (lanjutkanProgram == 0) {
						printf ("\nTERIMAKASIH SUDAH MENGGUNAKAN APLIKASI GENIUS LIBRARY MANAGER!\n");
					}
				} while (lanjutkanProgram != 0 && lanjutkanProgram != 1);
			}
		
	}
	} while (lanjutkanProgram == 1);
}

void tambahBuku (char *breadcrumb)
{
	struct book add;
	printf ("\nKODE BUKU: ");
	scanf ("%d", &add.kode);
	if (cekKodeBuku(add.kode)) {
		printf ("KODE BUKU SUDAH ADA! MASUKAN KODE LAIN");
		tambahBuku(breadcrumb);
		return;
	}
	
	printf ("JUMLAH STOK BUKU: ");
	scanf ("%d", &add.jumlahBuku);
	printf ("JUMLAH HALAMAN: ");
	scanf ("%d", &add.halaman);
	printf ("JUDUL: ");
	fgets (add.halaman, sizeof(add.halaman), stdin);
	printf ("PENGARANG: ");
	fgets (add.pengarang, sizeof(add.pengarang), stdin);
	printf ("KATEGORI: ");
	fgets (add.kategori, sizeof(add.kategori), stdin);
	
	FILE *file = fopen (FILE_NAME, "a+");
	if (file == NULL) {
		printf ("FILE GAGAL DIBUKA!");
		exit(EXIT_FAILURE);
	} 
	
	fprintf (file, "%d %d %d %d", add.kode, add.jumlahBuku, add.halaman, add.tahun);
	//fputs (file, add.judul, add.pengarang, add.kategori);
	fclose (file);
	printf ("\nBUKU BERHASIL DITAMBAHKAN!\n");
}

bool cekKodeBuku(int kode) 
{
	FILE *file = fopen (FILE_NAME, "r");
	if (file == NULL) {
		printf ("FILE GAGAL DIBUKA!");
		exit(EXIT_FAILURE);
	}
	
	struct book temp;
	while (fscanf(file, "%d %d %d %d %s %s %s\n", &temp.kode, &temp.jumlahBuku, &temp.halaman, &temp.tahun, temp.judul, temp.pengarang, temp.kategori) == 6) {
		if (temp.kode == kode) {
			return true;
		}
	}
	
	fclose (file);
	return false;
}

void daftarBuku (char *breadcrumb) {
	
}

void editBuku (char *breadcrumb) {
	
}

void hapusBuku (char *breadcrumb) {
	
}

void historyPeminjaman (char *breadcrumb) {
	
}

void modePengunjung(char *breadcrumb){
	
}
