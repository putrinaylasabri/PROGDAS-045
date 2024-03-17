//menentukan huruf vokal 

#include <stdio.h>
int main () {
    char huruf;
    printf ("Masukan huruf: ");
    scanf ("%c", &huruf);

    if (huruf == 'a' || huruf == 'A' || huruf == 'i' || huruf == 'I' || huruf == 'u' || huruf == 'U' || huruf == 'e' || huruf == 'E' || huruf == 'o' || huruf == 'O')
    { printf ("huruf %c adalah huruf vokal", huruf);} 
    else { printf ("huruf %c bukan huruf vokal", huruf);}

    return 0;
}