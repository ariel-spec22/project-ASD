#include <iostream>
#include <iomanip> // untuk setprecision()
using namespace std;

int main() {
    int jumlahBarang, jumlahDiskon;
    double hargaAwal, hargaAkhir, diskon, potongan, totalBelanja;
    char ulang;

    do {
        totalBelanja = 0; // reset setiap perhitungan baru

        cout << "===================================" << endl;
        cout << "     PROGRAM KALKULATOR DISKON     " << endl;
        cout << "===================================" << endl;

        cout << "Masukkan jumlah barang yang ingin dihitung: ";
        cin >> jumlahBarang;

        if (jumlahBarang <= 0) {
            cout << "Error: Jumlah barang harus lebih dari 0!" << endl;
            continue; // kembali ke awal loop
        }

        // Proses untuk setiap barang
        for (int b = 1; b <= jumlahBarang; b++) {
            cout << "\n--- Barang ke-" << b << " ---" << endl;

            cout << "Masukkan harga awal barang (Rp): ";
            cin >> hargaAwal;

            if (hargaAwal <= 0) {
                cout << "Error: Harga barang harus lebih dari 0!" << endl;
                continue;
            }

            cout << "Masukkan jumlah diskon yang digunakan: ";
            cin >> jumlahDiskon;

            if (jumlahDiskon <= 0) {
                cout << "Error: Jumlah diskon harus minimal 1!" << endl;
                continue;
            }

            hargaAkhir = hargaAwal;
            double potonganTotal = 0;

            // Loop untuk setiap diskon
            for (int i = 1; i <= jumlahDiskon; i++) {
                cout << "Masukkan diskon ke-" << i << " (%): ";
                cin >> diskon;

                if (diskon < 0 || diskon > 100) {
                    cout << "Error: Diskon harus antara 0 - 100%" << endl;
                    i--; // ulang input diskon ini
                    continue;
                }

                potongan = (diskon / 100.0) * hargaAkhir;
                hargaAkhir -= potongan;
                potonganTotal += potongan;
            }

            cout << fixed << setprecision(2);
            cout << "Total potongan barang ke-" << b << " : Rp " << potonganTotal << endl;
            cout << "Harga akhir barang ke-" << b << "   : Rp " << hargaAkhir << endl;

            totalBelanja += hargaAkhir;
        }

        cout << "\n===================================" << endl;
        cout << "TOTAL SELURUH BARANG : Rp " << fixed << setprecision(2) << totalBelanja << endl;
        cout << "===================================" << endl;

        // Menu ulang atau keluar
        cout << "\nApakah ingin menghitung lagi? (y/n): ";
        cin >> ulang;
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Terima kasih telah menggunakan program ini!" << endl;
    cout << "===================================" << endl;

    return 0;
}
