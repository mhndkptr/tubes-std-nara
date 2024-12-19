#include "tubes.h"

void headerMenu(const string title, const string subtitle = "") {
    int width = 49;
    cout << string(width, '=') << endl;

    int titlePadding = (width - title.length() - 4) / 2;
    cout << "**" << string(titlePadding, ' ') << title << string(titlePadding + (width - title.length() - 4) % 2, ' ') << "**" << endl;

    if (!subtitle.empty()) {
        int subtitlePadding = (width - subtitle.length() - 4) / 2;
        cout << "**" << string(subtitlePadding, ' ') << subtitle << string(subtitlePadding + (width - subtitle.length() - 4) % 2, ' ') << "**" << endl;
    }

    cout << string(width, '=') << endl;
}

void menu(listProjek &LP) {
    int choice;
    do {
        clearScreen();
        headerMenu("Menu Utama");
        list_menu_utama();
        choice = intInput("Pilih: ");
        cout << endl;

        if (choice == 1) {
            menu_input_projek(LP);
        }
        else if (choice == 2) {
            clearScreen();
            headerMenu("List data projek");
            showAllProjek(LP);
            pause();
        }
        else if (choice == 3) {
            int id;
            deleteProjekDanKaryawan(LP);
            pause();
        }
        else if (choice == 4) {
            clearScreen();
            headerMenu("Cari Projek");
            cout << endl;
            int id;
            id = intInput("Masukkan ID Projek yang dicari: ");
            adr_projek P = searchProjek(LP, id);
            if (P != NULL) {
                cout << "Projek ditemukan.\n" << endl;
                cout << "ID Projek\t\t: " << infoProjek(P).ID_projek << endl;
                cout << "Nama Projek\t\t: " << infoProjek(P).nama_projek << endl;
                cout << "Kategori Projek\t\t: " << infoProjek(P).kategori_projek << endl;
                cout << "Tanggal Mulai Projek\t: " << infoProjek(P).tanggal_mulai_projek << endl;
                cout << "Tanggal Selesai Projek\t: " << infoProjek(P).tanggal_selesai_projek << endl;
            } else {
                cout << "Projek tidak ditemukan." << endl;
            }
            cout << endl;
            pause();
        }
        else if (choice == 5) {
            menu_input_karyawan(LP);
        }
        else if (choice == 6) {
            clearScreen();
            headerMenu("Data projek dan karyawannya");
            showAllProjekAndKaryawan(LP);
            pause();
        }
        else if (choice == 7) {
            clearScreen();
            headerMenu("Hitung Jumlah Karyawan di Projek");
            cout << endl;
            int id;
            id = intInput("Masukkan ID Projek: ");
            cout << endl;

            adr_projek p = searchProjek(LP, id);
            if(p == NULL) {
                cout << "Projek dengan id: " << id << " tidak ditemukan." << endl;
            } else {
                int totalKaryawan = countKaryawanInProjek(LP, id);
                if(totalKaryawan != -1) {
                    cout << "Total Karyawan di projek dengan ID " << id << " adalah " << totalKaryawan << endl;
                }
            }
            cout << endl;

            pause();
        }
        else if (choice == 8) {
            clearScreen();
            headerMenu("Cari Karyawan di Projek Tertentu");
            cout << endl;

            int ID_karyawan, ID_projek;
            ID_projek = intInput("Masukkan ID Projek: ");
            adr_projek P = searchProjek(LP, ID_projek);

            if(P != NULL) {
                ID_karyawan = intInput("Masukkan ID Karyawan: ");
                adr_karyawan K = searchKaryawan(dataKaryawan(P), ID_karyawan);
                if(K == NULL) {
                    cout << "Data karyawan dengan id: " << ID_karyawan << " pada projek ini tidak ditemukan" << endl;
                } else {
                    cout << endl;
                    cout << "Data karyawan ditemukan " << endl;
                    cout << endl;
                    cout << "ID Karyawan\t\t: " << infoKaryawan(K).ID_karyawan << endl;
                    cout << "Nama Karyawan\t\t: " << infoKaryawan(K).nama_karyawan << endl;
                    cout << "Tanggal Lahir Karyawan\t: " << infoKaryawan(K).tanggal_lahir << endl;
                    cout << "Alamat Karyawan\t\t: " << infoKaryawan(K).alamat_karyawan << endl;
                    cout << "No Telp Karyawan\t: " << infoKaryawan(K).no_telp_karyawan << endl;
                    cout << "Email Karyawan\t\t: " << infoKaryawan(K).email_karyawan << endl;
                }
            } else {
                cout << "Projek dengan id: " << ID_projek << " tidak ditemukan." << endl;
            }
            cout << endl;

            pause();
        }
        else if (choice == 9) {
            clearScreen();
            headerMenu("Hapus Karyawan Pertama di Projek");
            cout << endl;

            int ID_karyawan, ID_projek;
            ID_projek = intInput("Masukkan ID Projek: ");
            adr_projek P = searchProjek(LP, ID_projek);

            if (P == NULL) {
                cout << "Projek tidak ditemukan" << endl;
            } else {
                cout << endl;
                if(firstKaryawan(dataKaryawan(P)) != NULL) {
                    cout << "Karyawan pertama pada projek pertama (ID: " << ID_projek << ") berhasil di hapus" << endl;
                }
                deleteKaryawan(dataKaryawan(P));
            }
            cout << endl;

            pause();
        }
        else if (choice == 10) {
            inisialisasi_data_perusahaan(LP);
            cout << "Data berhasil diinisialisasi" << endl;
            pause();
        }
    } while (choice != 0);

}

void menu_welcome() {
    cout << "=================================================" << endl;
    cout << "*                 Selamat Datang                *" << endl;
    cout << "*    Di Aplikasi Manajemen Projek & Karyawan    *" << endl;
    cout << "*                  By Kelompok 1                *" << endl;
    cout << "*     Muhammad Hendika Putra - 103012300116     *" << endl;
    cout << "*       Fazari Razka Davira - 103012300317      *" << endl;
    cout << "=================================================" << endl;

    cout << endl;

    cout << "Masukkan (Ya) untuk melanjutkan" << endl;
}

void list_menu_utama() {
    cout << "=================================================" << endl;
    cout << "1. Tambah Projek" << endl;
    cout << "2. Tampilkan Semua Projek" << endl;
    cout << "3. Hapus Projek Terakhir dan Karyawannya" << endl;
    cout << "4. Cari Projek" << endl;
    cout << "5. Tambah Karyawan ke Projek" << endl;
    cout << "6. Tampilkan Semua Projek dan Karyawannya" << endl;
    cout << "7. Hitung Jumlah Karyawan di Projek" << endl;
    cout << "8. Cari Karyawan di Projek Tertentu" << endl;
    cout << "9. Hapus Karyawan Pertama di Projek" << endl;
    cout << "10. Inisialisasi data" << endl;
    cout << "0. Keluar" << endl;
    cout << "=================================================" << endl;
}

void menu_input_projek(listProjek &LP) {
    clearScreen();
    headerMenu("Tambah data projek");
    cout << endl;

    infotype_projek data;
    int id_projek;

    id_projek = intInput("ID Projek\t: ");
    adr_projek p = searchProjek(LP, id_projek);
    if(p != NULL) {
        cout << "Projek dengan id: " << id_projek << " sudah ada." << endl;
    } else {
        data.ID_projek = id_projek;
        cin.ignore();
        cout << "Nama Projek\t: ";
        getline(cin, data.nama_projek);
        cout << "Kategori Projek\t: ";
        getline(cin, data.kategori_projek);
        cout << "Tanggal Mulai\t: ";
        getline(cin, data.tanggal_mulai_projek);
        cout << "Tanggal Selesai\t: ";
        getline(cin, data.tanggal_selesai_projek);
        insertFirstProjek(LP, allocateProjek(data));
        cout << endl;
        cout << "Data berhasil ditambahkan\n" << endl;
    }

    pause();
}

void menu_input_karyawan(listProjek &LP) {
    clearScreen();
    headerMenu("Tambah data karyawan");
    cout << endl;

    int id_projek;
    id_projek = intInput("Masukkan ID Projek: ");
    adr_projek p = searchProjek(LP, id_projek);

    if(p == NULL) {
        cout << "Projek dengan id: " << id_projek << " tidak ditemukan." << endl;
        pause();
    } else {
        infotype_karyawan data;
        int id_karyawan;
        id_karyawan = intInput("ID Karyawan\t: ");
        adr_karyawan k = searchKaryawan(dataKaryawan(p), id_karyawan);
        if(k != NULL) {
            cout << "Karyawan dengan id: " << id_karyawan << " sudah ada." << endl;
        } else {
            adr_projek projekKaryawan = searchKaryawanInAllProjek(LP, id_karyawan);
            if(projekKaryawan != NULL) {
                cout << "Data karyawan ditemukan pada projek dengan id: " << infoProjek(projekKaryawan).ID_projek << endl;
                k = searchKaryawan(dataKaryawan(projekKaryawan), id_karyawan);
                cout << endl;
                cout << "ID Karyawan\t\t: " << infoKaryawan(k).ID_karyawan << endl;
                cout << "Nama Karyawan\t\t: " << infoKaryawan(k).nama_karyawan << endl;
                cout << "Tanggal Lahir Karyawan\t: " << infoKaryawan(k).tanggal_lahir << endl;
                cout << "Alamat Karyawan\t\t: " << infoKaryawan(k).alamat_karyawan << endl;
                cout << "No Telp Karyawan\t: " << infoKaryawan(k).no_telp_karyawan << endl;
                cout << "Email Karyawan\t\t: " << infoKaryawan(k).email_karyawan << endl;
                cout << endl;
                cout << "Apakah anda ingin menambahkan karyawan ini ke dalam projek dengan id: " << id_projek << " ?" << endl;

                string input;
                cout << "Masukkan (Ya) untuk melanjutkan" << endl;
                cin >> input;
                if(input == "Ya" || input == "YA" || input == "ya") {
                    infotype_karyawan dataKaryawan = infoKaryawan(k);
                    connectProjekToKaryawan(LP, id_projek, allocateKaryawan(dataKaryawan));
                    cout << "Data berhasil ditambahkan" << endl;
                }
            } else {
                data.ID_karyawan = id_karyawan;
                cin.ignore();
                cout << "Nama Karyawan\t: ";
                getline(cin, data.nama_karyawan);
                cout << "Tanggal Lahir\t: ";
                getline(cin, data.tanggal_lahir);
                cout << "Alamat\t\t: ";
                getline(cin, data.alamat_karyawan);
                cout << "No. Telp\t: ";
                getline(cin, data.no_telp_karyawan);
                cout << "Email\t\t: ";
                getline(cin, data.email_karyawan);
                connectProjekToKaryawan(LP, id_projek, allocateKaryawan(data));
                cout << endl;
                cout << "Data berhasil ditambahkan\n" << endl;
            }
        }

        pause();
    }
}
