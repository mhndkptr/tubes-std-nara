#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define nextKaryawan(P) P->nextKaryawan
#define prevKaryawan(P) P->prevKaryawan
#define firstKaryawan(L) L.first
#define lastKaryawan(L) L.last
#define infoKaryawan(P) P->infoKaryawan
#define nextProjek(P) P->nextProjek
#define infoProjek(P) P->infoProjek
#define firstProjek(L) L.firstProjek
#define firstKaryawanProjek(L) L.firstKaryawan

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


struct elmProjek {
    infotype_projek infoProjek;
    adr_projek nextProjek;
    adr_karyawan firstKaryawan;
};

struct elmKaryawan {
    infotype_karyawan infoKaryawan;
    adr_karyawan prevKaryawan;
    adr_karyawan nextKaryawan;
};

struct listProjek {
    adr_projek first;
};

struct listKaryawan {
    adr_karyawan first;
    adr_karyawan last;
};

void insertFirstProjek(listProjek &LP, adr_projek P);
void showAllProjek(listProjek LP);
void deleteProjekDanKaryawan(listProjek &LP, int ID_projek);
adr_projek searchProjek(listProjek LP, int ID_projek);
void insertLastKaryawan(listKaryawan &LK, adr_karyawan K);
void connectProjekToKaryawan(listProjek &LP, listKaryawan LK, string ID_projek);
void showAllProjekAndKaryawan(listProjek LP);
adr_karyawan searchKaryawan(listKaryawan LK, int ID_karyawan, listProjek LP, int ID_projek);
void deleteKaryawan(listKaryawan &LK, listProjek LP, int ID_projek);
int countKaryawanInProjek(int ID_projek);




#endif // TUBES_H_INCLUDED
