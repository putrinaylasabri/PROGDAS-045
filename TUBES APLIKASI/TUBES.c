#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED "\033[1;32m"
#define ANSI_COLOR_RESET "\033[0m"

void scrollText(const char *text, int speed, int iterations);
void tampilanMenu ();
void opsiPenjual();

int main() {
    const char *text = "SELAMAT DATANG DI APLIKASI EASY RETAIL MANAGER ";
    int speed = 100;
    int iterations = 1; 
    scrollText(text, speed, iterations);
    tampilanMenu();
    return 0;
}


void scrollText(const char *text, int speed, int iterations) {
    int length = 80;
    int i, j, k;

    for (k = 0; k < iterations; ++k) {
        for (i = 0; i < length; ++i) {
            printf("\033[H\033[J");
            for (j = 0; j < i; ++j) {
                printf(" ");
            }
            printf("%s%s\033[0m", ANSI_COLOR_RED, text);
            usleep(speed * 1000);
            if (i == length / 2) {
                break;
            }
        }
    }
}

void tampilanMenu() {
    char pilihan;
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\033[032mAPA ROLE ANDA?\n");
    printf("\t\t\t\t\t\t\tA. Penjual / Seller\n");
    printf("\t\t\t\t\t\t\tB. Pembeli / Customer\n");
    printf("\033[13;37H");

    printf("\n\n\t\t\t\t\t\t\tAnda memilih: ");
    scanf(" %c", &pilihan);
    system ("cls");

    if (pilihan == 'a' || pilihan == 'A') {
        opsiPenjual(); }
    else {
        opsiPembeli();
    }
}

void opsiPenjual() {
    int opsi;
    printf("\033[033m1. Sign Up\n");
    printf("\033[033m2. Login\n");
    printf("\033[033mPilih opsi: ");
    scanf("\033[033m%d", &opsi);
}

void opsiPembeli () {
    printf("\033[033mOpsi:\n");
    printf("\033[033m[1] \n");
    printf("\033[033m[2] \n");
    printf("\033[033m[3] \n");
    printf("\033[033m[4] \n");
    printf("\033[033m[5] \n");

}