#include "tubes.h"

void menu(listProjek &LP) {
    int choice;
    do {
        cout << "==================== Menu ===================" << endl;
        cout << "1. Tambah Projek" << endl;
        cout << "2. Tampilkan Semua Projek" << endl;
        cout << "3. Hapus Projek Pertama dan Karyawannya" << endl;
        cout << "4. Cari Projek" << endl;
        cout << "5. Tambah Karyawan ke Projek" << endl;
        cout << "6. Tampilkan Semua Projek dan Karyawannya" << endl;
        cout << "7. Hitung Jumlah Karyawan di Projek" << endl;
        cout << "8. Cari Karyawan di Projek Tertentu" << endl;
        cout << "9. Hapus Karyawan Pertama di Projek" << endl;
        cout << "0. Keluar" << endl;
        cout << "=============================================" << endl;
        cout << "Pilih: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            cout << "Tambah Projek" << endl;
            infotype_projek data;
            cout << "ID Projek: ";
            cin >> data.ID_projek;
            cin.ignore();
            cout << "Nama Projek: ";
            getline(cin, data.nama_projek);
            cout << "Kategori Projek: ";
            getline(cin, data.kategori_projek);
            cout << "Tanggal Mulai: ";
            getline(cin, data.tanggal_mulai_projek);
            cout << "Tanggal Selesai: ";
            getline(cin, data.tanggal_selesai_projek);
            insertFirstProjek(LP, allocateProjek(data));
            cout << endl;
            cout << "Data berhasil ditambahkan\n" << endl;
        }
        else if (choice == 2) {
            showAllProjek(LP);
        }
        else if (choice == 3) {
            int id;
            deleteProjekDanKaryawan(LP);
            cout << endl;
        }
        else if (choice == 4) {
            int id;
            cout << "Masukkan ID Projek yang dicari: ";
            cin >> id;
            adr_projek P = searchProjek(LP, id);
            if (P) {
                cout << "Projek ditemukan: " << endl;
                cout << "ID Projek: " << infoProjek(P).ID_projek << endl;
                cout << "Nama Projek: " << infoProjek(P).nama_projek << endl;
                cout << "Kategori Projek: " << infoProjek(P).kategori_projek << endl;
                cout << "Tanggal Mulai Projek: " << infoProjek(P).tanggal_mulai_projek << endl;
                cout << "Tanggal Selesai Projek: " << infoProjek(P).tanggal_selesai_projek << endl;
            } else {
                cout << "Projek tidak ditemukan." << endl;
            }
            cout << endl;
        }
        else if (choice == 5) {
            int id_projek;
            cout << "Masukkan ID Projek: ";
            cin >> id_projek;

            infotype_karyawan data;
            cout << "ID Karyawan: ";
            cin >> data.ID_karyawan;
            cin.ignore();
            cout << "Nama Karyawan: ";
            getline(cin, data.nama_karyawan);
            cout << "Tanggal Lahir: ";
            getline(cin, data.tanggal_lahir);
            cout << "Alamat: ";
            getline(cin, data.alamat_karyawan);
            cout << "No. Telp: ";
            getline(cin, data.no_telp_karyawan);
            cout << "Email: ";
            getline(cin, data.email_karyawan);
            connectProjekToKaryawan(LP, id_projek, allocateKaryawan(data));
            cout << endl;
        }
        else if (choice == 6) {
            showAllProjekAndKaryawan(LP);
        }
        else if (choice == 7) {
            int id;
            cout << "Masukkan ID Projek: ";
            cin >> id;
            cout << endl;

            int totalKaryawan = countKaryawanInProjek(LP, id);
            if(totalKaryawan != -1) {
                cout << "Total Karyawan di projek dengan ID " << id << " adalah " << totalKaryawan << endl;
            }
            cout << endl;
        }
        else if (choice == 8) {
            int ID_karyawan, ID_projek;
            cout << "Masukkan ID Projek: ";
            cin >> ID_projek;
            adr_projek P = searchProjek(LP, ID_projek);
            if(P != NULL) {
                cout << "Masukkan ID Karyawan: ";
                cin >> ID_karyawan;
                adr_karyawan K = searchKaryawan(dataKaryawan(P), ID_karyawan);
                if(K == NULL) {
                    cout << "Data karyawan pada projek ini tidak ditemukan" << endl;
                } else {
                    cout << endl;
                    cout << "Data karyawan ditemukan: " << endl;
                    cout << "ID Karyawan: " << infoKaryawan(K).ID_karyawan << endl;
                    cout << "Nama Karyawan: " << infoKaryawan(K).nama_karyawan << endl;
                    cout << "Tanggal Lahir Karyawan: " << infoKaryawan(K).tanggal_lahir << endl;
                    cout << "Alamat Karyawan: " << infoKaryawan(K).alamat_karyawan << endl;
                    cout << "No Telp Karyawan: " << infoKaryawan(K).no_telp_karyawan << endl;
                    cout << "Email Karyawan: " << infoKaryawan(K).email_karyawan << endl;
                }
            }
            cout << endl;
        }
        else if (choice == 9) {
            int ID_karyawan, ID_projek;
            cout << "Masukkan ID Projek: ";
            cin >> ID_projek;
            adr_projek P = searchProjek(LP, ID_projek);
            if (P == NULL) {
                cout << "Projek tidak ditemukan" << endl;
            } else {
                cout << endl;
                deleteKaryawan(dataKaryawan(P));
                cout << "Data karyawan berhasil dihapus" << endl;
            }
            cout << endl;
        }
    } while (choice != 0);

}

void welcome() {
    cout << "=============================================" << endl;
    cout << "                Selamat Datang               " << endl;
    cout << "   Di Aplikasi Manajemen Projek & Karyawan   " << endl;
    cout << "                 By Kelompok 1               " << endl;
    cout << "    Muhammad Hendika Putra - 103012300116    " << endl;
    cout << "      Fazari Razka Davira - 10301230031      " << endl;
    cout << "=============================================" << endl;

    cout << endl;

    cout << "Masukkan (Ya) untuk melanjutkan" << endl;
}

int main()
{
    string input;
    welcome();
    cin >> input;

    if(input == "Ya" || input == "YA" || input == "ya") {
        cout << endl;
        listProjek LP;
        createListProjek(LP);

        menu(LP);
    }
    return 0;
}
