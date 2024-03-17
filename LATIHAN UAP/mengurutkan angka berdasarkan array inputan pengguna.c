#include <stdio.h>
void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                tukar(&arr[j], &arr[j + 1]);
}

int main() {
    int panjangArray;
    int i;

    printf("Masukkan panjang array: ");
    scanf("%d", &panjangArray);

    int data[panjangArray];

    printf("Masukkan elemen array:\n");
    for (i = 0; i < panjangArray; scanf("%d", &data[i++]));

    bubbleSort(data, panjangArray);

    printf("Array setelah diurutkan: ");
    for (i = 0; i < panjangArray; printf("%d ", data[i++]));

    return 0;
}
