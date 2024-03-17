#include <stdio.h>
#include <windows.h>

void MarqueeText(char *kalimat, int speed) {
    int x;

    for (x = 0; kalimat[x] != '\0'; x++) {
        printf("%c", kalimat[x]);
        fflush(stdout);
        Sleep(speed * 50); 

    }
}

int main() {
    MarqueeText("Ini adalah contoh Marquee Text.", 1);
    return 1;
}
