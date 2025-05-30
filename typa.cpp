#ifndef FILE_H
#define FILE_H

typedef struct {
    long long int NIK;
    char nama[50];
    char TTL[25];
    char JK[4];
    char alamat[50];
    char rtRw[10];
    char kelDesa[20];
    char kec[20];
    char agama[15];
    char SP[12];
    char pekerjaan[15];
    char kewarg[4];
    char masa[15];
} KTP;

void inputData(int n);
void displayData();
void deleteData(long long int nik);
void updateData(long long int nik);

#endif