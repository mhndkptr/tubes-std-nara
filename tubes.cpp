#include "tubes.h"

void insertFirstProjek(listProjek &LP, adr_projek P);

void showAllProjek(listProjek LP) {
    if(firstProjek(LP) == NULL) {
        cout << "Projek Kosong" << endl;
    } else {
        adr_projek P = firstProjek(LP);
        int i = 1
        cout << "Data Projek: " << endl;
        while(P != NULL) {
            cout << "Data ke-" << i << ": " << endl;
            cout << "ID Projek: " << infoProjek(P).ID_projek << endl;
            cout << "Nama Projek: " << infoProjek(P).nama_projek << endl;
            cout << "Kategori Projek: " << infoProjek(P).kategori_projek << endl;
            cout << "Tanggal Mulai Projek: " << infoProjek(P).tanggal_mulai_projek << endl;
            cout << "Tanggal Selesai Projek: " << infoProjek(P).tanggal_selesai_projek << endl;
            cout << endl;
            P = nextProjek(P);
            i++;
        }
    }
}

void deleteProjekDanKaryawan(listProjek &LP, int ID_projek);

adr_projek searchProjek(listProjek LP, int ID_projek) {
    if(firstProjek(LP) == NULL) {
        cout << "Projek Kosong" << endl;
        return NULL;
    } else {
        adr_projek P = firstProjek(LP);
        while(P != NULL && infoProjek(P).ID_projek != ID_projek) {
            P = nextProjek(P)
        }
        return P;
    }
}

void insertLastKaryawan(listKaryawan &LK, adr_karyawan K);

void connectProjekToKaryawan(listProjek &LP, listKaryawan LK, string ID_projek) {
    if(firstProjek(LP) == NULL) {
        cout << "Projek Kosong" << endl;
    } else if(firstKaryawan(LK) == NULL) {
        cout << "Karyawan Kosong" << endl;
    } else {
        adr_projek = searchProjek(LP, ID_projek);
        if(adr_projek == NULL) {
            cout << "Data projek tidak ditemukan."
        } else {
            firstKaryawanProjek(LP) = firstKaryawan(LK);
        }
    }
}

void showAllProjekAndKaryawan(listProjek LP);

adr_karyawan searchKaryawan(listKaryawan LK, int ID_karyawan, listProjek LP, int ID_projek) {
    adr_projek P = searchProjek(LP, ID_projek);
    if(P == NULL) {
        cout << "Projek Tidak Ditemukan" << endl;
    } else {
        adr_karyawan K = firstKaryawanProjek(P);
        if(K == NULL) {
            cout << "Data karyawan pada projek dengan ID: " << ID_projek << " kosong" << endl;
        } else {
            int i = 1
            cout << "Data Karyawan: " << endl;
            while(K != NULL) {
                cout << "Data ke-" << i << ": " << endl;
                cout << "ID Karyawan: " << infoKaryawan(K).ID_karyawan << endl;
                cout << "Nama Karyawan: " << infoKaryawan(K).nama_karyawan << endl;
                cout << "Tanggal Lahir Karyawan: " << infoKaryawan(K).tanggal_lahir << endl;
                cout << "Alamat Karyawan: " << infoKaryawan(K).alamat_karyawan << endl;
                cout << "No Telp Karyawan: " << infoKaryawan(K).no_telp_karyawan << endl;
                cout << "Email Karyawan: " << infoKaryawan(K).email_karyawan << endl;
                cout << endl;
                i++;
                K = nextKaryawan(K);
            }
        }
    }
}

void deleteKaryawan(listKaryawan &LK, listProjek LP, int ID_projek) {
    if(firstKaryawan(LK) == NULL) {
        cout << "Karyawan Kosong" <<  endl;
    } else {
        adr_projek P = searchProjek(LP, ID_projek);
        if(P == NULL) {
            cout << "Projek tidak ditemukan" << endl;
        } else {
            adr_karyawan K = firstKaryawanProjek(LP);
            adr_karyawan tempK;
            while(nextKaryawan(K) != NULL) {
                K = nextKaryawan(K);
            }
            tempK = K;
            K = prevKaryawan(K);
            next(K) = NULL;
            prevKaryawan(tempK) = NULL;
        }
    }
}

int countKaryawanInProjek(int ID_projek);
