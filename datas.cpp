#include "typa"
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void initializeFile() {
    FILE *file = fopen("data.dat", "ab");
    fclose(file);
}

void inputData(int n) {
    FILE *fileWrite = fopen("data.dat", "ab");

    if (fileWrite == NULL) {
        printf("Gagal membuka file untuk ditulis.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        KTP data;

        printf("\nMasukkan data KTP ke-%d:\n", i + 1);
        printf("NIK: "); scanf("%lld", &data.NIK);
        printf("Nama: "); scanf(" %[^\n]", data.nama);
        printf("Tempat, Tgl. Lahir: "); scanf(" %[^\n]", data.TTL);
        printf("Jenis Kelamin (L/P): "); scanf(" %s", data.JK);
        printf("Alamat: "); scanf(" %[^\n]", data.alamat);
        printf("RT/RW: "); scanf(" %[^\n]", data.rtRw);
        printf("Kel/Desa: "); scanf(" %[^\n]", data.kelDesa);
        printf("Kecamatan: "); scanf(" %[^\n]", data.kec);
        printf("Agama: "); scanf(" %[^\n]", data.agama);
        printf("Status Perkawinan: "); scanf(" %[^\n]", data.SP);
        printf("Pekerjaan: "); scanf(" %[^\n]", data.pekerjaan);
        printf("Kewarganegaraan: "); scanf(" %[^\n]", data.kewarg);
        printf("Berlaku Hingga: "); scanf(" %[^\n]", data.masa);

        fwrite(&data, sizeof(KTP), 1, fileWrite);
    }

    fclose(fileWrite);
}


void displayKTPData(const KTP *data) {
    printf("NIK                 : %lld\n", data->NIK);
    printf("Nama                : %s\n", data->nama);
    printf("Tempat, Tgl. Lahir  : %s\n", data->TTL);
    printf("Jenis Kelamin       : %s\n", data->JK);
    printf("Alamat              : %s\n", data->alamat);
    printf("RT/RW               : %s\n", data->rtRw);
    printf("Kel/Desa            : %s\n", data->kelDesa);
    printf("Kecamatan           : %s\n", data->kec);
    printf("Agama               : %s\n", data->agama);
    printf("Status Perkawinan   : %s\n", data->SP);
    printf("Pekerjaan           : %s\n", data->pekerjaan);
    printf("Kewarganegaraan     : %s\n", data->kewarg);
    printf("Berlaku Hingga      : %s\n\n", data->masa);
}

void displayAllData(FILE *file) {
    KTP readData;
    int count = 0;

    while (fread(&readData, sizeof(KTP), 1, file) == 1) {
        printf("\nKTP ke-%d\n", count + 1);
        printf("--------\n");
        displayKTPData(&readData);
        count++;
    }
}

void filterAndDisplayData(const KTP *readData, const char *filterValue) {
    if (strstr((char *) &(readData->NIK), filterValue) != NULL) {
        printf("Data ditemukan:\n");
        displayKTPData(readData);
    }
}

void filterAndDisplayDataByName(const KTP *readData, const char *filterValue) {
    if (strcmp(readData->nama, filterValue) == 0) {
        printf("Data ditemukan:\n");
        displayKTPData(readData);
    }
}

void filterData(FILE *file, int option, const char *filterValue) {
    KTP readData;
    int count = 0;
    int found = 0;

    // Membaca setiap record dari file
    while (fread(&readData, sizeof(KTP), 1, file) == 1) {
        char *fieldToFilter;

        // Menentukan field yang akan dijadikan filter berdasarkan opsi
        switch (option) {
            case 1:
                fieldToFilter = (char *)&(readData.NIK);
                break;
            case 2:
                fieldToFilter = readData.nama;
                break;
            case 3:
                fieldToFilter = readData.TTL;
                break;
            case 4:
                fieldToFilter = readData.JK;
                break;
            case 5:
                fieldToFilter = readData.alamat;
                break;
            case 6:
                fieldToFilter = readData.rtRw;
                break;
            case 7:
                fieldToFilter = readData.kelDesa;
                break;
            case 8:
                fieldToFilter = readData.kec;
                break;
            case 9:
                fieldToFilter = readData.agama;
                break;
            case 10:
                fieldToFilter = readData.SP;
                break;
            case 11:
                fieldToFilter = readData.pekerjaan;
                break;
            case 12:
                fieldToFilter = readData.kewarg;
                break;
            case 13:
                fieldToFilter = readData.masa;
                break;
            default:
                printf("Opsi tidak valid.\n");
                return;
        }

        // Cek apakah field yang dipilih mengandung nilai filter
        if (strstr(fieldToFilter, filterValue) != NULL) {
            if (!found) {
                printf("\nData yang memenuhi kriteria filter:\n");
            }

            // Menampilkan data yang memenuhi filter
            printf("\nKTP ke-%d\n", count + 1);
            printf("--------\n");
            displayKTPData(&readData);
            found = 1;
        }

        count++;
    }

    if (!found) {
        printf("\nTidak ada data yang memenuhi kriteria filter.\n");
    }
}

void displayFilteredData(FILE *file) {
    int option;
    printf("\nPilihan elemen untuk filter:\n");
    printf("1. NIK\n");
    printf("2. Nama\n");
    printf("3. Tempat, Tgl. Lahir\n");
    printf("4. Jenis Kelamin\n");
    printf("5. Alamat\n");
    printf("6. RT/RW\n");
    printf("7. Kel/Desa\n");
    printf("8. Kecamatan\n");
    printf("9. Agama\n");
    printf("10. Status Perkawinan\n");
    printf("11. Pekerjaan\n");
    printf("12. Kewarganegaraan\n");
    printf("13. Masa Berlaku\n");

    printf("Pilih opsi: ");
    scanf("%d", &option);

    // Buffer to store the user input for filtering
    char filterValue[MAX_STRING_LENGTH];

    printf("Masukkan nilai untuk filter: ");
    scanf(" %[^\n]", filterValue);

    // Memanggil fungsi filterData
    filterData(file, option, filterValue);
}

void displayData() {
    FILE *fileRead = fopen("data.dat", "rb");

    if (fileRead == NULL) {
        printf("Gagal membuka file untuk dibaca.\n");
        return;
    }

    int option;

    // Display options
    printf("\nPilihan tampilkan data:\n");
    printf("1. Tampilkan semua data\n");
    printf("2. Tampilkan berdasarkan elemen\n");
    printf("Pilih opsi: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            displayAllData(fileRead);
            break;
        case 2:
            displayFilteredData(fileRead);
            break;
        default:
            printf("Opsi tidak valid.\n");
            break;
    }

    fclose(fileRead);
}

void deleteData(int number) {
    FILE *fileRead = fopen("data.dat", "rb");
    FILE *fileWrite = fopen("temp.dat", "wb");

    if (fileRead == NULL || fileWrite == NULL) {
        printf("Gagal membuka file untuk dibaca atau ditulis.\n");
        return;
    }

    KTP readData;
    int count = 0;

    while (fread(&readData, sizeof(KTP), 1, fileRead) == 1) {
        if (++count != number) {
            fwrite(&readData, sizeof(KTP), 1, fileWrite);
        }
    }

    fclose(fileRead);
    fclose(fileWrite);

    remove("data.dat");
    rename("temp.dat", "data.dat");
}

void updateData(long long int nik) {
    FILE *fileRead = fopen("data.dat", "rb");
    FILE *fileWrite = fopen("temp.dat", "wb");

    if (fileRead == NULL || fileWrite == NULL) {
        printf("Gagal membuka file untuk dibaca atau ditulis.\n");
        return;
    }

    KTP readData;

    while (fread(&readData, sizeof(KTP), 1, fileRead) == 1) {
        if (readData.NIK == nik) {
            // Input data baru
            printf("\nData yang ingin diupdate:\n");
            printf(" 1. NIK\n");
            printf(" 2. Nama\n");
            printf(" 3. Tempat, Tgl. Lahir\n");
            printf(" 4. Jenis Kelamin\n");
            printf(" 5. Alamat\n");
            printf(" 6. RT/RW\n");
            printf(" 7. Kel/Desa\n");
            printf(" 8. Kecamatan\n");
            printf(" 9. Agama\n");
            printf("10. Status Perkawinan\n");
            printf("11. Pekerjaan\n");
            printf("12. Kewarganegaraan\n");
            printf("13. Masa Berlaku\n");

            int option;
            printf("Pilih opsi yang ingin diupdate: ");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    printf("NIK baru: ");
                    scanf("%lld", &readData.NIK);
                    break;
                case 2:
                    printf("Nama baru: ");
                    scanf(" %[^\n]", readData.nama);
                    break;
                case 3:
                    printf("Tempat, Tgl. Lahir baru: ");
                    scanf(" %[^\n]", readData.TTL);
                    break;
                case 4:
                    printf("Jenis Kelamin baru: ");
                    scanf(" %s", readData.JK);
                    break;
                case 5:
                    printf("Alamat baru: ");
                    scanf(" %[^\n]", readData.alamat);
                    break;
                case 6:
                    printf("RT/RW baru: ");
                    scanf(" %[^\n]", readData.rtRw);
                    break;
                case 7:
                    printf("Kel/Desa baru: ");
                    scanf(" %[^\n]", readData.kelDesa);
                    break;
                case 8:
                    printf("Kecamatan baru: ");
                    scanf(" %[^\n]", readData.kec);
                    break;
                case 9:
                    printf("Agama baru: ");
                    scanf(" %[^\n]", readData.agama);
                    break;
                case 10:
                    printf("Status Perkawinan baru: ");
                    scanf(" %[^\n]", readData.SP);
                    break;
                case 11:
                    printf("Pekerjaan baru: ");
                    scanf(" %[^\n]", readData.pekerjaan);
                    break;
                case 12:
                    printf("Kewarganegaraan baru: ");
                    scanf(" %[^\n]", readData.kewarg);
                    break;
                case 13:
                    printf("Masa Berlaku baru: ");
                    scanf(" %[^\n]", readData.masa);
                    break;
                default:
                    printf("Opsi tidak valid.\n");
                    break;
            }
        }

        fwrite(&readData, sizeof(KTP), 1, fileWrite);
    }

    fclose(fileRead);
    fclose(fileWrite);

    remove("data.dat");
    rename("temp.dat", "data.dat");
}
