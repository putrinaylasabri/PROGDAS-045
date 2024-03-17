#include <stdio.h>
#include <string.h>

int main () {
	char string[60];
	printf ("Masukan string: ");
	fgets (string, sizeof(string),stdin);
	
	if (string[strlen(string) - 1] == '\n'){
	string[strlen(string) - 1] = '\0';}
	
	int panjang = strlen(string);
	int i, j;
	
	for (i = 0, j = panjang - 1; i < j; i++, j--) {
		if (string[i]!=string[j]) {
			printf ("string %s bukan palindrom", string);
			return 1;
		} else {
			printf ("string %s adalah palindrom", string);
			return 0;
		}
	}
	return 0;
}