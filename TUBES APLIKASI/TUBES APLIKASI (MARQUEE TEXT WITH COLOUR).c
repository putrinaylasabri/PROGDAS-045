#include <stdio.h>
#define ANSI_COLOR_RED "\033[1;31m"
#define ANSI_COLOR_RESET "\033[0m"

void scrollText(const char *text, int speed);

void scrollText(const char *text, int speed) {
    int length = 80;
    int i;
    int j;

    while (1) {
        for (i = 0; i < length; ++i) {
            printf("\033[H\033[J");
            for (j = 0; j < i; ++j) {
                printf(" ");
            }
            printf("%s%s\033[0m", ANSI_COLOR_RED, text);
            usleep(speed * 1000);
        }
    }
}

int main() {
    const char *text = "SELAMAT DATANG DI APLIKASI GENIUS SELL MANAGER ";
    int speed = 100;
    scrollText(text, speed);
    return 0;
}
