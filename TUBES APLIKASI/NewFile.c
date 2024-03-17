#include <stdio.h>
#include <windows.h>
//PROGRAM KONVERSI

void konversiDetik();
void konversiCentimeter(); 

void opening () {
	int i = 0;
	const char *text = "SELAMAT DATANG DI APLIKASI KONVERSI!";
	while (text[i]!='\0'){
		putchar(text[i]);
		Sleep(50);
		i++;
}
}

void loading () {
	int i;
	int a = 145;
	printf ("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf ("Loading...");
	for (i = 0; i < a; i++) {
		printf ("\xdb");
		Sleep(20);
	}
}

void opsiMenu() {
    int opsi;
    int lanjutkanProgram = 1; // Inisialisasi variabel lanjutkanProgram
    
    do {
        printf("Apa yang ingin anda lakukan?\n");
        printf("[1] Konversi Detik\n");
        printf("[2] Konversi Centimeter\n");
        printf("[3] Keluar dari program\n");
        printf("Pilihan anda adalah: ");
        scanf("%d", &opsi);
        
        switch (opsi) {
            case 1:
                konversiDetik();
                break;

            case 2:
                konversiCentimeter();
                break;

            case 3:
                printf("\nTERIMAKASIH SUDAH MENGGUNAKAN PROGRAM INI!\n");
                break;

            default:
                printf("MASUKAN PILIHAN YANG VALID\n");

                if (opsi != 3) {
                    do {
                        printf("Apakah anda ingin melanjutkan program?");
                        printf(" 1 = Ya\n");
                        printf(" 0 = Tidak\n");
                        scanf("%d", &lanjutkanProgram);

                        if (lanjutkanProgram != 0 && lanjutkanProgram != 1) {
                            printf("\nMASUKAN INPUT YANG VALID\n");
                        }
                        if (lanjutkanProgram == 0) {
                            printf("\nTERIMAKASIH SUDAH MENGGUNAKAN APLIKASI GENIUS LIBRARY MANAGER!\n");
                        }
                    } while (lanjutkanProgram != 0 && lanjutkanProgram != 1);
                }
        }
    } while (lanjutkanProgram == 1 && opsi != 3);
}

			
void konversiDetik () {
	int total, jam, menit, detik, sisa;
	printf ("MASUKAN TOTAL DETIK\n");
	scanf ("%d", &total);
	
	jam = total/3600;
	sisa = total%3600;
	menit = sisa/60;
	detik = sisa%60;
	
	printf ("HASIL KONVERSI TOTAL DETIK ADALAH %d JAM, %d MENIT, %d DETIK", jam, menit, detik);
}

void konversiCentimeter () 
{
	
}

int main() {
	opening();
	loading();
	Sleep(500);
	system ("cls");
	opsiMenu();
	return 0;
}