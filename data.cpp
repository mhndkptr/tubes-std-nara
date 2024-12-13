#include "tubes.h"

void inisialisasi_data_perusahaan(listProjek &LP){
    adr_projek projek;
    adr_projek P;

    // Dummy data projek
    infotype_projek dataProjek;
    dataProjek.ID_projek = 1;
    dataProjek.nama_projek = "Website Development";
    dataProjek.kategori_projek = "Teknologi";
    dataProjek.tanggal_mulai_projek = "10-10-2023";
    dataProjek.tanggal_selesai_projek = "11-11-2023";
    P = searchProjek(LP, dataProjek.ID_projek);
    if(P == NULL) {
        projek = allocateProjek(dataProjek);
        insertFirstProjek(LP, projek);
    }

    dataProjek.ID_projek = 2;
    dataProjek.nama_projek = "Games Development";
    dataProjek.kategori_projek = "Teknologi";
    dataProjek.tanggal_mulai_projek = "04-10-2022";
    dataProjek.tanggal_selesai_projek = "11-01-2023";
    P = searchProjek(LP, dataProjek.ID_projek);
    if(P == NULL) {
        projek = allocateProjek(dataProjek);
        insertFirstProjek(LP, projek);
    }

    dataProjek.ID_projek = 3;
    dataProjek.nama_projek = "Data Research";
    dataProjek.kategori_projek = "Visualisation";
    dataProjek.tanggal_mulai_projek = "09-03-2024";
    dataProjek.tanggal_selesai_projek = "04-05-2024";
    P = searchProjek(LP, dataProjek.ID_projek);
    if(P == NULL) {
        projek = allocateProjek(dataProjek);
        insertFirstProjek(LP, projek);
    }


    // Dummy data karyawan
    infotype_karyawan dataKaryawan;
    dataKaryawan.ID_karyawan = 1;
    dataKaryawan.nama_karyawan = "Billy";
    dataKaryawan.tanggal_lahir = "10-01-1990";
    dataKaryawan.alamat_karyawan = "Jl.Chaonima";
    dataKaryawan.no_telp_karyawan = "081234567890";
    dataKaryawan.email_karyawan = "billy@karyawan.com";
    P = searchKaryawanInAllProjek(LP, dataKaryawan.ID_karyawan);
    if(P == NULL) {
        connectProjekToKaryawan(LP, 3, allocateKaryawan(dataKaryawan));
    }

    dataKaryawan.ID_karyawan = 2;
    dataKaryawan.nama_karyawan = "Azziz";
    dataKaryawan.tanggal_lahir = "15-02-1985";
    dataKaryawan.alamat_karyawan = "Jl.Cimaung_Banjir" ;
    dataKaryawan.no_telp_karyawan = "082345678901";
    dataKaryawan.email_karyawan = "azziz@karyawan.com";
    P = searchKaryawanInAllProjek(LP, dataKaryawan.ID_karyawan);
    if(P == NULL) {
        connectProjekToKaryawan(LP, 1, allocateKaryawan(dataKaryawan));
    }

    dataKaryawan.ID_karyawan = 3;
    dataKaryawan.nama_karyawan = "Calwa";
    dataKaryawan.tanggal_lahir = "20-03-1995";
    dataKaryawan.alamat_karyawan = "Jl.MotionIme";
    dataKaryawan.no_telp_karyawan = "083456789012";
    dataKaryawan.email_karyawan = "calwa@karyawan.com";
    P = searchKaryawanInAllProjek(LP, dataKaryawan.ID_karyawan);
    if(P == NULL) {
        connectProjekToKaryawan(LP, 1, allocateKaryawan(dataKaryawan));
    }

    dataKaryawan.ID_karyawan = 4;
    dataKaryawan.nama_karyawan = "Falah";
    dataKaryawan.tanggal_lahir = "25-04-1992";
    dataKaryawan.alamat_karyawan = "Jl.Bogor_No_9";
    dataKaryawan.no_telp_karyawan = "084567890123";
    dataKaryawan.email_karyawan = "falah@karyawan.com" ;
    P = searchKaryawanInAllProjek(LP, dataKaryawan.ID_karyawan);
    if(P == NULL) {
        connectProjekToKaryawan(LP, 2, allocateKaryawan(dataKaryawan));
    }

    dataKaryawan.ID_karyawan = 5;
    dataKaryawan.nama_karyawan = "Hilmi" ;
    dataKaryawan.tanggal_lahir = "30-05-1988" ;
    dataKaryawan.alamat_karyawan = "Jl.Garut" ;
    dataKaryawan.no_telp_karyawan = "085678901234" ;
    dataKaryawan.email_karyawan = "hilmi@karyawan.com" ;
    P = searchKaryawanInAllProjek(LP, dataKaryawan.ID_karyawan);
    if(P == NULL) {
        connectProjekToKaryawan(LP, 3, allocateKaryawan(dataKaryawan));
    }

    dataKaryawan.ID_karyawan = 6;
    dataKaryawan.nama_karyawan = "Irham" ;
    dataKaryawan.tanggal_lahir = "30-05-1988";
    dataKaryawan.alamat_karyawan = "Jl.Cisumdawu" ;
    dataKaryawan.no_telp_karyawan = "085678901234" ;
    dataKaryawan.email_karyawan = "irham@karyawan.com" ;
    P = searchKaryawanInAllProjek(LP, dataKaryawan.ID_karyawan);
    if(P == NULL) {
        connectProjekToKaryawan(LP, 3, allocateKaryawan(dataKaryawan));
    }
}
