#include <stdio.h>
int main () {

    float celcius, reamur, kelvin, fahrenheit;
    printf ("Masukan derajat dalam celcius ");
    scanf ("%f", &celcius);

    reamur = (4.0/5.0) * celcius;
    kelvin = celcius + 273.15;
    fahrenheit = (9.0/5.0)*celcius+32;

    printf ("\nDerajat %.2f dalam reamur adalah %.2f", celcius, reamur);
    printf ("\nDerajat %.2f dalam fahrenheit adalah %.2f", celcius, kelvin);
    printf ("\nDerajat %.2f dalam kelvin adalah %.2f", celcius, fahrenheit);
    return 0;
}
