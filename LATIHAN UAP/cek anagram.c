#include <stdio.h>
#include <string.h>

// Fungsi untuk mengurutkan karakter dalam string
void sortString(char *str) {
    int i, j;
    int n = strlen(str);
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
}

// Fungsi untuk mengecek apakah dua string adalah anagram
int isAnagram(const char *str1, const char *str2) {
    int n1 = strlen(str1), n2 = strlen(str2);
    if (n1 != n2) return 0;

    char temp1[n1 + 1], temp2[n2 + 1];
    strcpy(temp1, str1);
    strcpy(temp2, str2);

    sortString(temp1);
    sortString(temp2);

    return (strcmp(temp1, temp2) == 0);
}

int main() {
    char str1[100], str2[100];

    printf("Masukkan string pertama: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Masukkan string kedua: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (isAnagram(str1, str2))
        printf("String \"%s\" dan \"%s\" adalah anagram.\n", str1, str2);
    else
        printf("String \"%s\" dan \"%s\" bukan anagram.\n", str1, str2);

    return 0;
}
