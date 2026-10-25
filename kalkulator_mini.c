#include <stdio.h>
#include <math.h>

/* Fungsi operasi */
double tambah(double a, double b)  { return a + b; }
double kurang(double a, double b)  { return a - b; }
double kali(double a, double b)    { return a * b; }
double bagi(double a, double b)    { return a / b; }

/* Membaca angka dengan validasi input */
double bacaAngka(const char *pesan) {
    double nilai;
    int hasil;

    while (1) {
        printf("%s", pesan);
        hasil = scanf("%lf", &nilai);
        if (hasil == 1) {
            return nilai;
        }
        printf("Input tidak valid! Masukkan angka.\n");
        while (getchar() != '\n');   /* bersihkan buffer */
    }
}

void tampilMenu(void) {
    printf("\n==============================\n");
    printf("     KALKULATOR SEDERHANA\n");
    printf("==============================\n");
    printf("1. Penjumlahan   (+)\n");
    printf("2. Pengurangan   (-)\n");
    printf("3. Perkalian     (*)\n");
    printf("4. Pembagian     (/)\n");
    printf("5. Modulus       (%%)\n");
    printf("6. Pangkat       (^)\n");
    printf("7. Akar Kuadrat\n");
    printf("0. Keluar\n");
    printf("==============================\n");
    printf("Pilih menu: ");
}

int main(void) {
    int pilihan;
    double a, b, hasil;

    do {
        tampilMenu();
        if (scanf("%d", &pilihan) != 1) {
            printf("Pilihan tidak valid!\n");
            while (getchar() != '\n');
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
            case 1:
                a = bacaAngka("Angka pertama : ");
                b = bacaAngka("Angka kedua   : ");
                printf("Hasil: %.2f + %.2f = %.2f\n", a, b, tambah(a, b));
                break;
            case 2:
                a = bacaAngka("Angka pertama : ");
                b = bacaAngka("Angka kedua   : ");
                printf("Hasil: %.2f - %.2f = %.2f\n", a, b, kurang(a, b));
                break;
            case 3:
                a = bacaAngka("Angka pertama : ");
                b = bacaAngka("Angka kedua   : ");
                printf("Hasil: %.2f * %.2f = %.2f\n", a, b, kali(a, b));
                break;
            case 4:
                a = bacaAngka("Angka pertama : ");
                b = bacaAngka("Angka kedua   : ");
                if (b == 0) {
                    printf("Error: pembagian dengan nol tidak diperbolehkan!\n");
                } else {
                    printf("Hasil: %.2f / %.2f = %.2f\n", a, b, bagi(a, b));
                }
                break;
            case 5:
                a = bacaAngka("Angka pertama (bilangan bulat) : ");
                b = bacaAngka("Angka kedua (bilangan bulat)   : ");
                if ((int)b == 0) {
                    printf("Error: modulus dengan nol tidak diperbolehkan!\n");
                } else {
                    printf("Hasil: %d %% %d = %d\n", (int)a, (int)b, (int)a % (int)b);
                }
                break;
            case 6:
                a = bacaAngka("Bilangan dasar : ");
                b = bacaAngka("Pangkat        : ");
                hasil = pow(a, b);
                printf("Hasil: %.2f ^ %.2f = %.2f\n", a, b, hasil);
                break;
            case 7:
                a = bacaAngka("Masukkan angka : ");
                if (a < 0) {
                    printf("Error: akar dari bilangan negatif tidak terdefinisi!\n");
                } else {
                    printf("Hasil: akar(%.2f) = %.2f\n", a, sqrt(a));
                }
                break;
            case 0:
                printf("Terima kasih telah menggunakan kalkulator!\n");
                break;
            default:
                printf("Pilihan tidak tersedia, coba lagi.\n");
        }
    } while (pilihan != 0);

    return 0;
}