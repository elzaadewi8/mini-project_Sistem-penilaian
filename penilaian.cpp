#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

enum Grade {A, B, C, D ,E};

struct mahasiswa {
    string nama;
    int NIM;
    float nilaiTugas;
    float UTS;
    float UAS;
    float nilaiAkhir;
    Grade grade;
};

float hitungNilaiAkhir(float tugas, float uts, float uas) {
    return 0.3 * tugas + 0.3 * uts + 0.4 * uas;
}

Grade tentukanGrade(float nilai) {
    if (nilai >= 80) return A;
    else if (nilai >= 70) return B;
    else if (nilai >= 60) return C;
    else if (nilai >= 50) return D;
    else return E;
}

string konversiGrade(Grade g) {
    switch(g) {
        case A: return "A";
        case B: return "B";
        case C: return "C";
        case D: return "D";
        case E: return "E";
    }
    return "";
}

int main (){

    int pilihan,jumlahMahasiswa;
    char ulangMenu = 'y';
    mahasiswa mhs[100];

    do {
    cout << "============= Program Sistem Penilaian Mahasiswa ===================\n";
    cout << "1. Masukkan Data dan Nilai Mahasiswa\n";
    cout << "2. Tampilkan Laporan Nilai Mahasiswa\n";
    cout << "3. Keluar Program\n";
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;

    if (pilihan == 1){
        cout << "Masukkan Jumlah Mahasiswa : ";
        cin >> jumlahMahasiswa;
        system("cls");
        for (int i=0; i<jumlahMahasiswa; i++){
        cout << "Masukkan Nama Mahasiswa " << i+1 << " : ";
        cin >> mhs[i].nama;
        cout << "Masukkan NIM Mahasiswa " << i+1 << " : ";
        cin >> mhs[i].NIM;
        cout << "Masukkan Nilai Tugas Mahasiswa " << i+1 << " : ";
        cin >> mhs[i].nilaiTugas;
        cout << "Masukkan Nilai UTS Mahasiswa " << i+1 << " : ";
        cin >> mhs[i].UTS;
        cout << "Masukkan Nilai UAS Mahasiswa " << i+1 << " : ";
        cin >> mhs[i].UAS;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(
        mhs[i].nilaiTugas,
        mhs[i].UTS,
        mhs[i].UAS
        );

        mhs[i].grade = tentukanGrade(mhs[i].nilaiAkhir);
        }
    }

    else if (pilihan == 2){
       cout << "\n=== LAPORAN NILAI MAHASISWA ===\n";
            for (int i = 0; i < jumlahMahasiswa; i++){
                cout << "\nNama : " << mhs[i].nama;
                cout << "\nNIM : " << mhs[i].NIM;
                cout << "\nNilai Akhir : " << mhs[i].nilaiAkhir;
                cout << "\nGrade : " << konversiGrade(mhs[i].grade);
                cout << "\n-----------------------------\n";

    }
    } else ("Terimakasih");

    } while (ulangMenu == 'y' || ulangMenu == 'Y');

    return 0;
}



