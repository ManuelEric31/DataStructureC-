#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct TNode
{
    int NilaiX;
    int NilaiY;
    TNode *next;
};

TNode *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

int countNodes(struct TNode *p)
{
    int count{};
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int isEmpty()
{
    if (tail == NULL)
        return 1;
    else
        return 0;
}

void insertDepan(int databaru1, int databaru2)
{
    TNode *baru;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->next = NULL;

    if (isEmpty() == 1)
        head = tail = baru;
    else
    {
        baru->next = head;
        head = baru;
    }
    cout << "Data masuk\n";
}

void tampil()
{
    TNode *bantu;
    bantu = head;
    if (isEmpty() == 0)
    {
        while (bantu != NULL)
        {
            cout << bantu->NilaiX << " " << bantu->NilaiY << endl;
            bantu = bantu->next;
        }
    }
    else
        cout << "Data Masih kosong\n";
}

void hapusDepan()
{
    TNode *hapus;
    int delete1, delete2;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = head;
            delete1 = hapus->NilaiX;
            delete2 = hapus->NilaiY;
            head = head->next;
            delete hapus;
        }
        else
        {
            delete1 = tail->NilaiX;
            delete2 = tail->NilaiY;
            head = tail = NULL;
        }
        cout << delete1 << " dan " << delete2 << " Terhapus";
    }
    else
        cout << "Data Masih kosong\n";
}

void hapusBelakang()
{
    TNode *bantu = tail;
    TNode *hapus = head;
    int delete1, delete2;
    if (isEmpty() == 0)
    {
        for (int i = 0; i < countNodes(head) - 2; i++)
            hapus = hapus->next;
        if (hapus->next != NULL)
        {
            delete1 = tail->NilaiX;
            delete2 = tail->NilaiY;
            tail = hapus;
            tail->next = NULL;
            delete bantu;
        }
        else
        {
            delete1 = tail->NilaiX;
            delete2 = tail->NilaiY;
            delete bantu;
            head = tail = NULL;
        }
        cout << delete1 << " dan " << delete2 << " Terhapus";
    }
    else
        cout << "Data Masih kosong\n";
}
void insertBelakang(int data1, int data2)
{
    struct TNode *baru;
    baru = new struct TNode;
    baru->NilaiX = data1;
    baru->NilaiY = data2;
    baru->next = NULL;
    if (isEmpty())
        head = tail = baru;
    else
    {
        tail->next = baru;
        tail = baru;
    }
    cout << "Data masuk\n";
}

void searchData(int key1, int key2)
{
    int flag1{-1};
    int flag2{-1};
    struct TNode *bantu;
    bantu = head;
    if (!isEmpty())
    {
        while (bantu != NULL)
        {
            if (bantu->NilaiX == key1 && bantu->NilaiY == key2)
            {
                flag1 = key1;
                flag2 = key2;
                cout << "Data ditemukan : " << flag1 << " dan " << flag2 << endl;
                break;
            }
            else
                cout << "Data tidak ditemukan" << endl;
            bantu = bantu->next;
        }
    }
    else
        cout << "Linked List masih kosong" << endl;
}

void insertAfter(int data1, int data2)
{
    struct TNode *bantu = head;
    int cari1{}, cari2{};
    cout << "Insert data setelah nilai : ";
    cin >> cari1 >> cari2;
    if (!isEmpty())
    {
        struct TNode *baru;
        baru = new struct TNode;
        baru->NilaiX = data1;
        baru->NilaiY = data2;
        baru->next = NULL;

        while (bantu != NULL)
        {
            if (bantu->NilaiX == cari1 && bantu->NilaiY == cari2)
            {
                if (bantu->next != NULL)
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                else
                {
                    bantu->next = baru;
                    tail = baru;
                }
                break;
            }
            bantu = bantu->next;
        }
    }
    else
        cout << "Data tidak ditemukan" << endl;
}

void insertBefore(int data1, int data2)
{
    struct TNode *bantu = head;
    int cari1{}, cari2{};
    cout << "Insert data sebelum nilai : ";
    cin >> cari1 >> cari2;
    if (!isEmpty())
    {
        struct TNode *baru;
        baru = new struct TNode;
        baru->NilaiX = data1;
        baru->NilaiY = data2;
        baru->next = NULL;

        while (bantu != NULL)
        {
            if (head == tail)
            {
                baru->next = head;
                head = baru;
                break;
            }
            if (bantu->next->NilaiX == cari1 && bantu->next->NilaiY == cari2)
            {
                baru->next = bantu->next;
                bantu->next = baru;
                break;
            }

            bantu = bantu->next;
        }
    }
    else
        cout << "Data tidak ditemukan" << endl;
}

void hapusTengah()
{
    struct TNode *hapus;
    int dimana1, dimana2;
    cin >> dimana1 >> dimana2;

    if (head == tail)
    {
        hapus = head;
        delete hapus;
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct TNode *bantu;
        bantu = head;
        while (bantu != NULL)
        {
            if (bantu->next->NilaiX == dimana1 && bantu->next->NilaiY == dimana2)
            {
                hapus = bantu->next;
                bantu->next = bantu->next->next;
                delete hapus;
                break;
            }
            else
            {
                cout << "Data Pertama dan Terakhir Tidak boleh dihapus" << endl;
                break;
            }
            bantu = bantu->next;
        }
    }
}
void clear()
{
    TNode *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = NULL;
    printf("clear");
}

int main()
{
    int pil{}, databaru1{}, databaru2{};
    string nama{"The, Manuel Eric Saputra"};
    string NIM{"A11.2021.13250"};
    do
    {
        system("cls");
        cout << setw(120) << std::right << nama << endl;
        cout << setw(120) << std::right << NIM << endl;
        cout << endl;
        cout << " ============================" << endl;
        cout << " =   PROGRAM LINKED LIST    =" << endl;
        cout << " ============================" << endl;
        cout << " = 1. Insert Depan          =" << endl;
        cout << " = 2. Insert Belakang       =" << endl;
        cout << " = 3. Insert After          =" << endl;
        cout << " = 4. Insert Before         =" << endl;
        cout << " = 5. Delete Depan          =" << endl;
        cout << " = 6. Delete Belakang       =" << endl;
        cout << " = 7. Tampil Data           =" << endl;
        cout << " = 8. Cari Data             =" << endl;
        cout << " = 9. Clear                 =" << endl;
        cout << " = 10. Hapus Tengah         =" << endl;
        cout << " = 11. Exit                 =" << endl;
        cout << " ============================" << endl;
        cout << " Masukan Pilihan : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            system("cls");
            {
                cout << "Masukan Data = ";
                cin >> databaru1 >> databaru2;
                insertDepan(databaru1, databaru2);
                break;
            }
        case 2:
            system("cls");
            {
                cout << "Masukan Data = ";
                cin >> databaru1 >> databaru2;
                insertBelakang(databaru1, databaru2);
                break;
            }
        case 3:
            system("cls");
            {
                cout << "Masukan Data = ";
                cin >> databaru1 >> databaru2;
                insertAfter(databaru1, databaru2);
                break;
            }
        case 4:
            system("cls");
            {
                cout << "Masukan Data = ";
                cin >> databaru1 >> databaru2;
                insertBefore(databaru1, databaru2);
                break;
            }
        case 5:
            system("cls");
            {
                hapusDepan();
                break;
            }
        case 6:
            system("cls");
            {
                hapusBelakang();
                break;
            }
        case 7:
            system("cls");
            {
                tampil();
                break;
            }
        case 8:
            system("cls");
            {
                if (!isEmpty())
                {
                    cout << "Cari Data = ";
                    cin >> databaru1 >> databaru2;
                    searchData(databaru1, databaru2);
                }
                else
                    cout << "Data masih kosong" << endl;
                break;
            }
        case 9:
            system("cls");
            {
                clear();
                break;
            }
        case 10:
            system("cls");
            {
                if (isEmpty())
                {
                    cout << "Data masih kosong" << endl;
                }
                else
                    hapusTengah();
                break;
            }
        case 11:
            system("cls");
            {
                return 0;
                break;
            }
        default:
            system("cls");
            {
                cout << "\n Maaf, Pilihan yang anda pilih tidak tersedia!";
            }
        }
        getch();
    } while (pil != 11);
    return 0;
}