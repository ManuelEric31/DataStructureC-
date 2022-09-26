#include <iostream>
using namespace std;

struct dataNilai
{
    string NIM;
    string nama;
    float nilaiUjian;
    int banyakSiswa;
    struct dataNilai *pointer;
};

void masukanNilai (struct dataNilai *pNilai)
{
    int i{};
    cout << "Masukkan jumlah mahasiswa untuk input nilai : ";
    cin >> pNilai->banyakSiswa;
    pNilai->pointer = new struct dataNilai [pNilai->banyakSiswa];
    
    for (i  = 0; i < pNilai->banyakSiswa; i++)
    {
        cout << "Masukkan NIM anak- " << i+1 << " : ";
        cin >> pNilai->pointer[i].NIM;
        cout << "Masukkan nama anak- " << i+1 << " : ";
        cin  >> pNilai->pointer[i].nama;
        cout << "Masukkan Nilai Ujian anak- " << i+1 << " : ";
        cin >> pNilai->pointer[i].nilaiUjian;
        cout << endl;
    }
    
}

void tampilkanData (struct dataNilai nilai)
{
    int i{};
    for (i = 0; i < nilai.banyakSiswa; i++)
    {
        cout << "Data mahasiswa : "  << i+1 << endl;
        cout << nilai.pointer[i].NIM << endl;
        cout << nilai.pointer[i].nama << endl;
        cout << nilai.pointer[i].nilaiUjian << endl << endl;
    }
    
    cout << endl;
}

float returnRerata (struct dataNilai *p1)
{
    int i{};
    float sum{};
    for (i = 0; i < p1->banyakSiswa; i++)
    {
        sum += p1->pointer[i].nilaiUjian;
    }
    
    float rataRata = sum / p1->banyakSiswa;
    return rataRata;
}

void cekNilai (struct dataNilai *cekNilai, float rataRata)
{
    int i{};
    cout << "Mahasiswa yang nilainya dibawah rata-rata : ";
    for (i = 0; i < cekNilai->banyakSiswa; i++)
    {
        if (cekNilai->pointer[i].nilaiUjian < rataRata)
        {
            cout << "\nData mahasiswa : "  << i+1 << endl;
            cout << cekNilai->pointer[i].NIM << endl;
            cout << cekNilai->pointer[i].nama << endl;
            cout << cekNilai->pointer[i].nilaiUjian << endl;    
        }
        cout << endl;
    }
    
}
int main () {
    
    struct dataNilai obj1;
    masukanNilai(&obj1);
    cout << endl;
    tampilkanData(obj1);
    cout << endl;
    float rataRata = returnRerata(&obj1);
    
    cout << "Rata rata nilai dalam kelas tersebut adalah : " << rataRata << endl; 
    cekNilai(&obj1, rataRata);
    return 0;
}