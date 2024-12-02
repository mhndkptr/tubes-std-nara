#include "tubes.h"

void createListProjek(listProjek &LP) {
    firstProjek(LP) = NULL;
}

void createListKaryawan(listKaryawan &LK) {
    firstKaryawan(LK) = NULL;
    lastKaryawan(LK) = NULL;
}

adr_projek allocateProjek(infotype_projek dataProjek) {
    adr_projek P = new elmProjek;
    infoProjek(P) = dataProjek;
    nextProjek(P) = NULL;
    createListKaryawan(dataKaryawan(P));
    return P;
}

adr_karyawan allocateKaryawan(infotype_karyawan dataKaryawan) {
    adr_karyawan K = new elmKaryawan;
    infoKaryawan(K) = dataKaryawan;
    nextKaryawan(K) = NULL;
    prevKaryawan(K) = NULL;
    return K;
}

void insertFirstProjek(listProjek &LP, adr_projek P) {
    /*
    { I.S.: listProjek LP mungkin kosong, adr_projek P menunjuk ke
    elemen list yang akan ditambah
    F.S.: Data projek baru akan dimasukkan ke dalam list projek
    dan menjadi elemen pertama
    }
    */
    if (firstProjek(LP) == NULL) {
        firstProjek(LP) = P;
    } else {
        nextProjek(P) = firstProjek(LP);
        firstProjek(LP) = P;
    }
}

void showAllProjek(listProjek LP) {
    /*
    { I.S.: listProjek LP mungkin kosong
    F.S.: Menampilkan semua data projek dan atribut-atributnya
    }
    */
    if(firstProjek(LP) == NULL) {
        cout << "Projek Kosong" << endl;
        cout << endl;
    } else {
        adr_projek P = firstProjek(LP);
        int i = 1;
        cout << "Data Projek: " << endl;
        cout << endl;
        while(P != NULL) {
            cout << "Data projek ke-" << i << ": " << endl;
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

void deleteProjekDanKaryawan(listProjek &LP) {
    /*
    { I.S.: listProjek LP mungkin kosong
    F.S.: Data terakhir projek berdasarkan ID projek terhapus dan
    data karyawan berdasarkan ID karyawan terhapus
    }
    */
    if (firstProjek(LP) == NULL) {
        cout << "Projek Kosong" << endl;
    } else {
        adr_projek P = firstProjek(LP);
        while (nextProjek(P) != NULL) {
            P = nextProjek(P);
        }
        adr_karyawan K = firstKaryawan(dataKaryawan(P));
        if (K == NULL) {
            cout << "Karyawan Tidak Ada" << endl;
        } else {
            while (firstKaryawan(dataKaryawan(P)) != NULL) {
                deleteKaryawan(dataKaryawan(P));
            }
        }
        if (nextProjek(P) == NULL) {
            adr_projek tempP = P;
            firstProjek(LP) = NULL;
        } else {
            while(nextProjek(nextProjek(P)) != NULL) {
                P = nextProjek(P);
            }
            adr_projek tempP = P;
            nextProjek(P) = NULL;
        }
    }
    cout << endl;
}

adr_projek searchProjek(listProjek LP, int ID_projek) {
    /*
    { Mengembalikan nilai address projek dari
    data projek berdasarkan ID projek
    }
    */
    if(firstProjek(LP) == NULL) {
        cout << "Projek Kosong" << endl;
        return NULL;
    } else {
        adr_projek P = firstProjek(LP);
        while(P != NULL && infoProjek(P).ID_projek != ID_projek) {
            P = nextProjek(P);
        }
        return P;
    }
}

void insertLastKaryawan(listKaryawan &LK, adr_karyawan K) {
    /*
    { I.S.: listKaryawan LK mungkin kosong, adr_karyawan K menunjuk ke
    elemen list yang akan ditambah
    F.S.: Data karyawan baru akan dimasukkan ke dalam list karyawan
    dan menjadi elemen terakhir
    }
    */
    if (firstKaryawan(LK) == NULL) {
        firstKaryawan(LK) = K;
    }else {
        adr_karyawan Q = firstKaryawan(LK);
        while (nextKaryawan(Q) != NULL) {
            Q = nextKaryawan(Q);
        }
        nextKaryawan(Q) = K;
    }
}

void connectProjekToKaryawan(listProjek &LP, int ID_projek, adr_karyawan K) {
    /*
    { I.S.: listProjek LP dan listKaryawan LK mungkin kosong
    F.S.: Data projek dengan data karyawan terhubung berdasarkan
    listProjek dengan ID_projek
    }
    */
    /*
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
    */

    adr_projek P = searchProjek(LP, ID_projek);
    if (P != NULL) {
        insertLastKaryawan(dataKaryawan(P), K);
    } else {
        cout << "Projek tidak ditemukan." << endl;
    }
}

void showAllProjekAndKaryawan(listProjek LP) {
    /*
    { I.S.: listProjek LP mungkin kosong
    F.S.: Menampilkan semua data projek dan data karyawan
    }
    */
    adr_projek P = firstProjek(LP);
    int countProjek = 1;
    if(P == NULL) {
        cout << "Projek Kosong" << endl;
        cout << endl;
    }
    while (P != NULL) {
        cout << "Data projek ke-" << countProjek << ": " << endl;
        cout << "ID Projek: " << infoProjek(P).ID_projek << endl;
        cout << "Nama Projek: " << infoProjek(P).nama_projek << endl;
        cout << "Kategori Projek: " << infoProjek(P).kategori_projek << endl;
        cout << "Tanggal Mulai Projek: " << infoProjek(P).tanggal_mulai_projek << endl;
        cout << "Tanggal Selesai Projek: " << infoProjek(P).tanggal_selesai_projek << endl;
        cout << "Karyawan untuk Projek ID: " << infoProjek(P).ID_projek << endl;
        cout << endl;
        countProjek++;

        adr_karyawan K = firstKaryawan(dataKaryawan(P));
        if (K == NULL) {
            cout << "Tidak ada karyawan untuk projek ini." << endl;
            cout << endl;
        } else {
            int i = 1;
            while (K != NULL) {
                cout << "Data karyawan ke-" << i++ << ": " << endl;
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

adr_karyawan searchKaryawan(listKaryawan LK, int ID_karyawan) {
    /*
    { I.S.: listKaryawan LK dan listProjek LP mungkin kosong
    F.S.: Data karyawan yang ditemukan berdasarkan listProjek
    dan ID_projek akan ditampilkan
    }
    */
    if(firstKaryawan(LK) == NULL) {
        cout << "Data karyawan pada projek ini kosong" << endl;
        return NULL;
    } else {
        adr_karyawan K = firstKaryawan(LK);
        while(K != NULL && infoKaryawan(K).ID_karyawan != ID_karyawan) {
            K = nextKaryawan(K);
        }
        return K;
    }
}

void deleteKaryawan(listKaryawan &LK) {
    /*
    { I.S.: listProjek LP mungkin kosong
    F.S.: Data karyawan terakhir terhapus pada data projek tertentu
    }
    */
    if (firstKaryawan(LK) == NULL) {
        cout << "Karyawan Tidak Ada" << endl;
    } else {
        adr_karyawan K = firstKaryawan(LK);
        adr_karyawan tempK = K;
        firstKaryawan(LK) = nextKaryawan(firstKaryawan(LK));
        nextKaryawan(tempK) = NULL;
    }
}

int countKaryawanInProjek(listProjek LP, int ID_projek) {
    /*
    { Mengembalikan nilai jumlah data karyawan
    dari data projek tertentu }
    */
    int jumlahKaryawan = 0;
    adr_projek P = searchProjek(LP, ID_projek);
    if (P == NULL) {
        cout << "Projek dengan ID " << ID_projek << " tidak ditemukan." << endl;
        return -1;
    }
    adr_karyawan K = firstKaryawan(dataKaryawan(P));
    while (K != NULL) {
        jumlahKaryawan++;
        K = nextKaryawan(K);
    }
    return jumlahKaryawan;
}
