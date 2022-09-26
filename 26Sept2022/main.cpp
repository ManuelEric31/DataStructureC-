#include <iostream>
using namespace std;

// Global Variable
int maxValue{3};
static int totalBarang{0};
static int i{0};

// Struct
struct antrianPasien
{
    string nama;
    char jkel;
    int umur;
    struct antrianPasien *pointer;
};
// Function Prototype
void pushNilai(struct antrianPasien *p);
void hapusData(struct antrianPasien *p, int index);
void popDataTerakhir(struct antrianPasien *p);
void displayNilai(struct antrianPasien display);
void move (struct antrianPasien *p);

// Function
void pushNilai(struct antrianPasien *p)
{

    if (i == 0)
    {
        p->pointer = new struct antrianPasien[maxValue];
    }
    cout << "Masukkan Nama Pasien : ";
    cin >> p->pointer[i].nama;
    cout << "Masukkan Jenis Kelamin Pasien : ";
    cin >> p->pointer[i].jkel;
    cout << "Masukkan Umur Pasien : ";
    cin >> p->pointer[i].umur;
    i++;
    totalBarang++;
}

void hapusData(struct antrianPasien *p, int index)
{
    if (index >= 0 && index < totalBarang)
    {
        for (int j = index; j < totalBarang - 1; j++)
            p->pointer[j] = p->pointer[j + 1];
        totalBarang--;
        i--;
    }
}

void dequeDataTerakhir(struct antrianPasien *p)
{
    totalBarang--;
    i--;
    move(p);
    displayNilai(*p);
}

void displayNilai(struct antrianPasien display)
{
    cout << "\nHasil data : " << endl;
        for (int j = 0; j < totalBarang; j++)
        {
            cout << "Data ke-" << j + 1 << "\n"
             << display.pointer[j].nama << " "
             << display.pointer[j].jkel << " "
             << display.pointer[j].umur << endl;
        }
}

void move (struct antrianPasien *p)
{
    if (totalBarang > 0)
    {
        for (int i = 1; i <= totalBarang; i++)
            p->pointer[i-1] = p->pointer[i];
    }
}

void hapusIndex (struct antrianPasien *p, int index)
{
    if  (index >= 0 && index < totalBarang)
    {
         for (int i = index; i < totalBarang-1; i++)
        {
            p->pointer[i] = p->pointer[i+1];
        }
        totalBarang--;
        i--;
    }
    else
        cout << "Queue is not valid" << endl;
}
int main()
{
    
    int pilih{}, indexHapus{};
    struct antrianPasien data;
    cout << "Limit Antrian Hanya : " << maxValue << endl;
    do
    {
        cout << "\n1. Masukkan Antrian : " << endl;
        cout << "2. Tampilkan Antrian : " << endl;
        cout << "3. Keluarkan Antrian : " << endl;
        cout << "4. Keluarkan berdasarkan Index : " << endl;
        cout << "5. Keluar Program : " << endl;

        cout << "\nMasukkan pilihan anda : ";
        cin >> pilih;

        if (pilih == 1)
        {
            if (totalBarang < maxValue)
                pushNilai(&data);
            else
                cout << "Antrian sudah penuh !!!" << endl;
        }
        else if (pilih == 2)
            displayNilai(data);
        else if (pilih == 3)
        {
            if (totalBarang != 0)
                dequeDataTerakhir(&data);
            else
                cout << "Antrian masih kosong!!!" << endl;
        }
        else if (pilih == 4)
        {
                if (totalBarang != 0)
                {
                    cout << "Masukkan index untuk dihapus : ";
                    cin >> indexHapus;
                    hapusIndex(&data,indexHapus);
                }
                else
                cout << "Antrian masih kosong!!!" << endl;
        }
        else
            exit(1);
    } while (pilih >= 1 || pilih <= 3);

    return 0;
}