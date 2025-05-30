#include "typa"
#include "datas"
#include <stdio.h>

int main() {
    int choice;
    int nomorUrut;

    initializeFile(); // Memastikan file data.dat ada

    do {
        printf("Pilih opsi:\n");
        printf("1. Input data\n");
        printf("2. Tampilkan data\n");
        printf("3. Hapus data\n");
        printf("4. Ubah data\n");
        printf("0. Keluar\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan jumlah data yang ingin diinput: ");
                int n;
                scanf("%d", &n);
                inputData(n);
                break;

            case 2:
                displayData();
                break;

            case 3:
                printf("Masukkan nomor data yang ingin dihapus: ");
                scanf("%d", &nomorUrut);
                deleteData(nomorUrut);
                break;

            case 4:
                printf("Masukkan NIK data yang ingin diubah: ");
                long long int nik;
                scanf("%lld", &nik);
                updateData(nik);
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 0);

    return 0;
}
#include "file.h"
#include "file.c"
#include <stdio.h>

int main() {
    int choice;
    int nomorUrut;

    initializeFile(); // Memastikan file data.dat ada

    do {
        printf("Pilih opsi:\n");
        printf("1. Input data\n");
        printf("2. Tampilkan data\n");
        printf("3. Hapus data\n");
        printf("4. Ubah data\n");
        printf("0. Keluar\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan jumlah data yang ingin diinput: ");
                int n;
                scanf("%d", &n);
                inputData(n);
                break;

            case 2:
                displayData();
                break;

            case 3:
                printf("Masukkan nomor data yang ingin dihapus: ");
                scanf("%d", &nomorUrut);
                deleteData(nomorUrut);
                break;

            case 4:
                printf("Masukkan NIK data yang ingin diubah: ");
                long long int nik;
                scanf("%lld", &nik);
                updateData(nik);
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 0);

    return 0;
}
