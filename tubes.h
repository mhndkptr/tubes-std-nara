#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

#ifdef _WIN32
#include <bits/stdc++.h>
#endif

#define nextKaryawan(P) P->nextKaryawan
#define prevKaryawan(P) P->prevKaryawan
#define firstKaryawan(L) L.first
#define lastKaryawan(L) L.last
#define infoKaryawan(P) P->infoKaryawan
#define nextProjek(P) P->nextProjek
#define infoProjek(P) P->infoProjek
#define firstProjek(L) L.first
#define dataKaryawan(P) P->dataKaryawan

struct karyawan {
    int ID_karyawan;
    string nama_karyawan;
    string tanggal_lahir;
    string alamat_karyawan;
    string no_telp_karyawan;
    string email_karyawan;
};

struct projek {
    int ID_projek;
    string nama_projek;
    string kategori_projek;
    string tanggal_mulai_projek;
    string tanggal_selesai_projek;
};

typedef projek infotype_projek;
typedef karyawan infotype_karyawan;
typedef struct elmProjek *adr_projek;
typedef struct elmKaryawan *adr_karyawan;

struct elmKaryawan {
    infotype_karyawan infoKaryawan;
    adr_karyawan prevKaryawan;
    adr_karyawan nextKaryawan;
};

struct listKaryawan {
    adr_karyawan first;
    adr_karyawan last;
};

struct elmProjek {
    infotype_projek infoProjek;
    adr_projek nextProjek;
    listKaryawan dataKaryawan;
};

struct listProjek {
    adr_projek first;
};

void createListProjek(listProjek &LP);
void createListKaryawan(listKaryawan &LK);
adr_projek allocateProjek(infotype_projek dataProjek);
adr_karyawan allocateKaryawan(infotype_karyawan dataKaryawan);

void insertFirstProjek(listProjek &LP, adr_projek P);
void showAllProjek(listProjek LP);
void deleteProjekDanKaryawan(listProjek &LP);
adr_projek searchProjek(listProjek LP, int ID_projek);
void insertLastKaryawan(listKaryawan &LK, adr_karyawan K);
void connectProjekToKaryawan(listProjek &LP, int ID_projek, adr_karyawan K);
void showAllProjekAndKaryawan(listProjek LP);
adr_karyawan searchKaryawan(listKaryawan LK, int ID_karyawan);
void deleteKaryawan(listKaryawan &LK);
int countKaryawanInProjek(listProjek LP, int ID_projek);
adr_projek searchKaryawanInAllProjek(listProjek LP, int ID_karyawan);

// Utils
void clearScreen();
void pause();
int intInput(string prompt);
void tableHorizontalSparator(vector<int> colWidth);
void tableRow(vector<int> colWidth, vector<string> data);
vector<int> colWidth(vector<vector<string>> &t);
void table(vector<vector<string>> &t);
void inisialisasi_data_perusahaan(listProjek &LP);

// Menu
void menu_welcome();
void menu(listProjek &LP);
void list_menu_utama();
void headerMenu(string title, string subtitle);
void menu_input_projek(listProjek &LP);
void menu_input_karyawan(listProjek &LP);

#endif // TUBES_H_INCLUDED
