#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan informasi barang
struct Barang {
    int kodeBarang;
    char namaBarang[50];
    int jumlahStok;
    float hargaPerBarang;
};

// Fungsi untuk menampilkan display barang berbentuk tabel
void tampilkanDisplayBarang(struct Barang barang) {
    printf("| %-11d | %-19s | %-11d | %-16.2f |\n", barang.kodeBarang, barang.namaBarang, barang.jumlahStok, barang.hargaPerBarang);
}

// Fungsi untuk menyimpan informasi barang ke dalam file
void simpanInformasiBarangKeFile(struct Barang daftarBarang[], int jumlahBarang) {
    int i;
    FILE *file = fopen("informasi_barang.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk penulisan.\n");
        return;
    }

    for (i = 0; i < jumlahBarang; i++) {
        fprintf(file, "%d %s %d %.2f\n", daftarBarang[i].kodeBarang, daftarBarang[i].namaBarang,
                daftarBarang[i].jumlahStok, daftarBarang[i].hargaPerBarang);
    }

    fclose(file);
}

// Fungsi untuk membaca informasi barang dari file
int bacaInformasiBarangDariFile(struct Barang daftarBarang[]) {
    FILE *file = fopen("informasi_barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file untuk membaca.\n");
        return 0;
    }

    int jumlahBarang = 0;
    char line[100];  // Sesuaikan ukuran buffer sesuai kebutuhan

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d %49[^0-9] %d %f", &daftarBarang[jumlahBarang].kodeBarang,
               daftarBarang[jumlahBarang].namaBarang, &daftarBarang[jumlahBarang].jumlahStok,
               &daftarBarang[jumlahBarang].hargaPerBarang);

        jumlahBarang++;
    }

    fclose(file);

    return jumlahBarang;
}


int main() {
    // Deklarasi variabel
    int jumlahBarang;
    int i;

    // Menampilkan pesan selamat datang
    printf("SELAMAT DATANG DI PROGRAM TOKO\n");

    // Input jumlah barang
    printf("Masukkan jumlah barang: ");
    scanf("%d", &jumlahBarang);

    // Bersihkan buffer stdin
    while (getchar() != '\n');

    // Membuat array dari struktur Barang untuk menyimpan informasi barang
    struct Barang daftarBarang[jumlahBarang];

    // Mode penjual: memasukkan informasi barang
    for (i = 0; i < jumlahBarang; i++) {
        printf("\nMasukkan informasi untuk Barang %d:\n", i + 1);

        // Input informasi barang
        printf("Kode Barang   : ");
        scanf("%d", &daftarBarang[i].kodeBarang);

        // Bersihkan buffer stdin
        while (getchar() != '\n');

        printf("Nama Barang   : ");
        fgets(daftarBarang[i].namaBarang, sizeof(daftarBarang[i].namaBarang), stdin);
        daftarBarang[i].namaBarang[strcspn(daftarBarang[i].namaBarang, "\n")] = '\0';

        printf("Jumlah Stok   : ");
        scanf("%d", &daftarBarang[i].jumlahStok);

        printf("Harga Barang  : ");
        scanf("%f", &daftarBarang[i].hargaPerBarang);
    }

    // Menyimpan informasi barang ke dalam file
    simpanInformasiBarangKeFile(daftarBarang, jumlahBarang);

    // Mode pembeli: membaca informasi barang dari file dan menampilkan dalam bentuk tabel
    printf("\nDISPLAY BARANG UNTUK PEMBELI:\n");
    printf("| Kode Barang | Nama Barang         | Jumlah Stok | Harga Per Barang |\n");
    printf("|-------------|---------------------|-------------|------------------|\n");

    int jumlahBarangPembeli = bacaInformasiBarangDariFile(daftarBarang);

    for (i = 0; i < jumlahBarangPembeli; i++) {
        tampilkanDisplayBarang(daftarBarang[i]);
    }

    return 0;
}
