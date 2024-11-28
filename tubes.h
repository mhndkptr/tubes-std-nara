#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

struct karyawan {
    int ID_karyawan;
    string nama_karyawan;
    string alamat_karyawan;
    int no_telp_karyawan;
    string email_karyawan;
};

struct projek {
    int ID_projek;
    string nama_projek;
    string jenis_projek;
    int durasi_projek;
    int anggaran_projek;
};

void insertFirstKaryawan();
void showAllKaryawan();
void deleteKaryawanDanProjek();
void searchKaryawan();
void insertLastProjek();



#endif // TUBES_H_INCLUDED
