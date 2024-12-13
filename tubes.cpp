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
        cout << endl;

        vector<vector<string>> t;
        t.push_back({"NO","ID","NAMA", "KATEGORI", "TANGGAL MULAI", "TANGGAL SELESAI"});
        while(P != NULL) {
            t.push_back({to_string(i), to_string(infoProjek(P).ID_projek), infoProjek(P).nama_projek, infoProjek(P).kategori_projek, infoProjek(P).tanggal_mulai_projek, infoProjek(P).tanggal_selesai_projek});
            P = nextProjek(P);
            i++;
        }

        table(t);
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
        adr_projek prevP;
        if(nextProjek(P) == NULL) {
            prevP = NULL;
        } else {
            prevP = P;
            while (nextProjek(nextProjek(prevP)) != NULL) {
                prevP = nextProjek(prevP);
            }
            P = nextProjek(prevP);
        }

        adr_karyawan K = firstKaryawan(dataKaryawan(P));

        if (K == NULL) {
            cout << "Karyawan Tidak Ada" << endl;
        } else {
            while (firstKaryawan(dataKaryawan(P)) != NULL) {
                deleteKaryawan(dataKaryawan(P));
            }
        }

        if(prevP == NULL) {
            adr_projek tempP = P;
            firstProjek(LP) = NULL;
        } else {
            adr_projek tempP = P;
            nextProjek(prevP) = NULL;
        }
        cout << "Projek terakhir berhasil dihapus" << endl;
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
    cout << endl;
    while (P != NULL) {
        string projekKe = "Data projek ke-" + to_string(countProjek);
        headerMenu(projekKe, "");
        cout << "ID Projek\t\t: " << infoProjek(P).ID_projek << endl;
        cout << "Nama Projek\t\t: " << infoProjek(P).nama_projek << endl;
        cout << "Kategori Projek\t\t: " << infoProjek(P).kategori_projek << endl;
        cout << "Tanggal Mulai Projek\t: " << infoProjek(P).tanggal_mulai_projek << endl;
        cout << "Tanggal Selesai Projek\t: " << infoProjek(P).tanggal_selesai_projek << endl;
        cout << endl;
        cout << "Data Karyawan:" << endl;
        countProjek++;

        adr_karyawan K = firstKaryawan(dataKaryawan(P));
        if (K == NULL) {
            cout << "Tidak ada karyawan untuk projek ini." << endl;
        } else {
            int i = 1;
            vector<vector<string>> t;
            t.push_back({"NO","ID","NAMA", "TANGGAL LAHIR", "ALAMAT", "NO TELP", "EMAIL"});
            while (K != NULL) {
                t.push_back({to_string(i), to_string(infoKaryawan(K).ID_karyawan), infoKaryawan(K).nama_karyawan, infoKaryawan(K).tanggal_lahir, infoKaryawan(K).alamat_karyawan, infoKaryawan(K).no_telp_karyawan, infoKaryawan(K).email_karyawan});
                i++;
                K = nextKaryawan(K);
            }

            table(t);

        }
        P = nextProjek(P);

        cout << "=================================================" << endl;
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
        return NULL;
    } else {
        adr_karyawan K = firstKaryawan(LK);
        while(K != NULL && infoKaryawan(K).ID_karyawan != ID_karyawan) {
            K = nextKaryawan(K);
        }
        return K;
    }
}

adr_projek searchKaryawanInAllProjek(listProjek LP, int ID_karyawan) {
    if(firstProjek(LP) == NULL) {
        return NULL;
    } else {
        adr_projek P = firstProjek(LP);
        while(P != NULL) {
            adr_karyawan K = searchKaryawan(dataKaryawan(P), ID_karyawan);
            if(K != NULL) {
                return P;
            }
            P = nextProjek(P);
        }
        return NULL;
    }
}

void deleteKaryawan(listKaryawan &LK) {
    /*
    { I.S.: listProjek LP mungkin kosong
    F.S.: Data karyawan pertama terhapus pada data projek tertentu
    }
    */
    if (firstKaryawan(LK) == NULL) {
        cout << "Karyawan Tidak Ada" << endl;
    } else {
        adr_karyawan K = firstKaryawan(LK);
        adr_karyawan tempK = K;
        firstKaryawan(LK) = nextKaryawan(firstKaryawan(LK));
        nextKaryawan(tempK) = NULL;
        cout << "Data karyawan berhasil dihapus" << endl;
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
