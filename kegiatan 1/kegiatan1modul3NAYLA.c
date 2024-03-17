#include <stdio.h>

enum makanan {
    Nasi_Goreng = 1, Ayam_Goreng, Mie_Goreng, Nasi_Padang, Nasi_Uduk
};

enum minuman {
    Air_Mineral = 1, Es_Teh, Jus_Jeruk, Jus_Mangga, Es_Buah
};

int main () {
    int pilihanMakanan;
    int pilihanMinuman;
    int totalBelanja = 0;
    char member; 
    int uangAnda; 
    int kembalianAnda;
    
    //pemilihan makanan
    printf ("===Rumah Makan===\n");
    printf ("\nMenu Makanan");
    printf ("\n1. Nasi Goreng = 50000\n");
    printf ("2. Mie Goreng = 45000\n");
    printf ("3. Ayam Goreng = 65000\n");
    printf ("4. Nasi Padang = 80000\n");
    printf ("5. Nasi_Uduk = 70000\n");
    printf ("Pilih menu makanan 1-5: ");
    scanf ("%d",&pilihanMakanan);

    switch (pilihanMakanan) {
        case Nasi_Goreng:
            totalBelanja += 50000;
            break;
        case Mie_Goreng:
            totalBelanja += 45000;
            break;
        case Ayam_Goreng:
            totalBelanja += 65000;
            break;
        case Nasi_Padang:
        	totalBelanja += 80000;
        	break;
        case Nasi_Uduk :
        	totalBelanja += 70000;
        	break;
        default:
            printf("Pilihan makanan tidak valid.\n");
    }

    //pemilihan minuman
    printf("\nMenu Minuman\n");
    printf("1. Air Mineral = 13000\n");
    printf("2. Es Teh = 15000\n");
    printf("3. Jus Jeruk = 20000\n");
    printf("4. Jus Mangga = 30000\n");
    printf("5. Es Buah = 40000\n");
    printf("Pilih menu minuman 1-5: ");
    scanf("%d", &pilihanMinuman);
    getchar ();
    
    switch (pilihanMinuman) {
        case Air_Mineral:
            totalBelanja += 13000;
            break;
        case Es_Teh:
            totalBelanja += 15000;
            break;
        case Jus_Jeruk:
            totalBelanja += 20000;
            break;
        case Jus_Mangga:
        	totalBelanja += 30000;
        	break;
        case Es_Buah:
        	totalBelanja += 40000;
        	break;
        default:
            printf("Pilihan minuman tidak valid.\n");
    }

    //menanyakan tentang member
    printf ("\nApakah anda member? (Y/N): ");
    scanf ("%c",&member);

    //hitung total belanja, jika pelanggan adalah member dapatkan diskon 10%
    if (member == 'Y' || member == 'y') {
        totalBelanja = totalBelanja * 0.9; 
    } else {
        totalBelanja = totalBelanja;
    }
    //output total belanja 
    printf("Total belanja: %d\n", totalBelanja);
    printf ("Alamat memori variabel total: %p\n");
    
    //menginput uang dan hasil kembalian
    printf ("Masukkan uang pembayaran: ");
    scanf ("%d",&uangAnda);

    if (uangAnda > totalBelanja) {
        kembalianAnda = uangAnda-totalBelanja;
        printf ("Kembalian anda : %d\n",kembalianAnda);
    } else if (uangAnda < totalBelanja) {
        printf ("\nUang anda tidak cukup, masukan jumlah yang sesuai\n");
    } else {
        kembalianAnda = 0;
        printf ("\nUang anda pas, terimakasih\n");
    }
    return 0;
}