#include "tubes.h"

void insertFirstProjek(listProjek &LP, adr_projek P) {
    if (firstProjek(LP) == NULL) {
        firstProjek(LP) == P;
    } else {
        nextProjek(P) = firstProjek(LP);
        firstProjek(LP) = P;
    }
}

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

void deleteProjekDanKaryawan(listProjek &LP, int ID_projek) {
    if (firstProjek(LP) == NULL) {
        cout << "Projek Kosong" << endl;
    }else {
        adr_projek P = firstProjek(LP);
        while (nextProjek(P) != NULL) {
            P = nextProjek(P);
        }
        adr_karyawan K = firstKaryawanProjek(P);
        if (K == NULL) {
            cout << "Karyawan Tidak Ada" << endl;
        }else {
            while (firstKaryawanProjek(LP) != NULL) {
                deleteKaryawan(LP, ID_projek);
            }
        }
        if (nextProjek(P) == NULL) {
            adr_projek tempP = P;
            firstProjek(LP) = NULL;
        }else {
            while(nextProjek(nextProjek(P)) != NULL) {
                P = nextProjek(P)
            }
            adr_projek tempP = P;
            nextProjek(P) = NULL;
        }
    }
}

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

void insertLastKaryawan(listKaryawan &LK, adr_karyawan K) {
    if (firstKaryawan(LK) == NULL) {
        firstKaryawan(LK) = K;
    }else {
        adr_karyawan Q = firstKaryawan(LK);
        while (nextKaryawan(Q) != NULL) {
            Q = nextKaryawan(LK)
        }
        nextKaryawan(LK) = K;
    }
}

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

void showAllProjekAndKaryawan(listProjek LP) {
    showAllProjek(LP);
    adr_projek P = firstProjek(LP);
    while (P != NULL) {
        cout << "Karyawan untuk Projek ID : " << infoProjek(P).ID_projek << endl;
        adr_karyawan K = firstKaryawanProjek(P);
        if (K == NULL) {
            cout << "Tidak ada karyawan untuk projek ini." << endl;
        } else {
            int i = 1
            cout << "Data Karyawan : "
            while (K != NULL) {
                cout << "Data ke-" << i++ << ": " << endl;
                cout << "ID Karyawan: " << infoKaryawan(K).ID_karyawan << endl;
                cout << "Nama Karyawan: " << infoKaryawan(K).nama_karyawan << endl;
                cout << "Tanggal Lahir Karyawan: " << infoKaryawan(K).tanggal_lahir << endl;
                cout << "Alamat Karyawan: " << infoKaryawan(K).alamat_karyawan << endl;
                cout << "No Telp Karyawan: " << infoKaryawan(K).no_telp_karyawan << endl;
                cout << "Email Karyawan: " << infoKaryawan(K).email_karyawan << endl;
                cout << endl;
                K = nextKaryawan(K);
            }
        }
        P = nextProjek(P);
    }
}

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

void deleteKaryawan(listProjek LP, int ID_projek) {
    adr_projek P = searchProjek(LP, ID_projek);
    if (P == NULL) {
        cout << "Projek tidak ditemukan" << endl;
    } else {
        adr_karyawan K = firstKaryawanProjek(LP);
        if (K == NULL) {
            cout << "Karyawan Tidak Ada" << endl;
        }else {
            adr_karyawan tempK;
            tempK = K;
            prevKaryawan(K) = NULL;
            firstKaryawan(K) = nextKaryawan(K);
            nextKaryawan(tempK) = NULL;
        }
    }
}

int countKaryawanInProjek(int ID_projek) {
    int jumlahKaryawan = 0;
    adr_projek P = searchProjek(LP, ID_projek);
    if (P == NULL) {
        cout << "Projek dengan ID " << ID_projek << " tidak ditemukan." << endl;
        return 0;
    }
    adr_karyawan K = firstKaryawanProjek(P);
    while (K != NULL) {
        jumlahKaryawan++;
        K = nextKaryawan(K);
    }
    return jumlahKaryawan;
}
