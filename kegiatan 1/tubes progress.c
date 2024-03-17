#include <stdio.h>
#include <unistd.h>

#define ANSI_COLOR_RED "\033[1;31m"
#define ANSI_COLOR_RESET "\033[0m"

void scrollText(const char *text, int speed, int iterations);
void tampilanMenu ();
void eksekusiPilihan();

int main() {
    const char *text = "SELAMAT DATANG DI APLIKASI GENIUS SELL MANAGER ";
    int speed = 100;
    int iterations = 1; 
    scrollText(text, speed, iterations);
    tampilanMenu();
    system ("cls");
    eksekusiPilihan();

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

            // Hentikan scrolling ketika mencapai tengah layar
            if (i == length / 2) {
                break;
            }
        }
    }
}

void tampilanMenu() {
    char pilihan;
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tAPA ROLE ANDA?\n");
    printf("\t\t\t\t\t\t\tA. Penjual / Seller\n");
    printf("\t\t\t\t\t\t\tB. Pembeli / Customer\n");

    // Pindahkan kursor ke posisi tengah layar
    printf("\033[13;37H");

    printf("\n\n\t\t\t\t\t\t\tAnda memilih: ");
    scanf(" %c", &pilihan);
    return pilihan;
}

void eksekusiPilihan() {
	char pilihan;
	char a, A;
	char username[20];
	char password[20];
	if (pilihan == a || pilihan == A) {
		printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tMASUKAN IDENTITAS PENJUAL:\n");
		printf ("\t\t\t\t\t\tUsername : ");
		scanf ("%s", username);
		printf ("\t\t\t\t\t\tPassword : ");
		scanf ("%s", password);
	}
}