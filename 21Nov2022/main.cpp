#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct TNode {
    TNode *prev;
    int NilaiX;
    int NilaiY;
    TNode *next;
}*head = NULL, *tail = NULL;

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

void cariData (int key1, int key2)
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
void insertDepan(int databaru1, int databaru2)
{
    TNode *baru;
    baru = new TNode;
    baru->prev = NULL;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->next = NULL;

    if (isEmpty())
        head = tail = baru;
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data masuk\n";
}

void insertBelakang (int databaru1, int databaru2)
{
    struct TNode *baru, *bantu;
    baru = new struct TNode;
    baru->prev = NULL;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->next = NULL;
    if (isEmpty())
        head = tail = baru;
    else
    {
        bantu = tail;
        tail->next = baru;
        baru->prev = bantu;
        tail = baru;
    }
    cout << "Data masuk\n";
}

void insertTengahBefore (int databaru1, int databaru2)
{
    struct TNode *bantu = head;
    int cari1{}, cari2{};
    cout << "Insert data sebelum nilai : ";
    cin >> cari1 >> cari2;
    if (!isEmpty())
    {
        struct TNode *baru;
        baru = new struct TNode;
        baru->prev = NULL;
        baru->NilaiX = databaru1;
        baru->NilaiY = databaru2;
        baru->next = NULL;

        while (bantu != NULL)
        {
            if ((head == tail) && (head->NilaiX == cari1 && head->NilaiY == cari2))
            {
                baru->next = head;
                head->prev = baru;
                head = baru;
                break;
            }
            if (bantu->next->NilaiX == cari1 && bantu->next->NilaiY == cari2)
            {
                baru->prev = bantu;
                baru->next = bantu->next;
                bantu->next = baru;
                baru->next->prev = baru;
                break;
            }
            bantu = bantu->next;
        }
    }
    else
        cout << "Data tidak ditemukan" << endl;
}

void hapusDepan ()
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
            head->prev = NULL;
            delete hapus;
        }
        else
        {
            delete1 = tail->NilaiX;
            delete2 = tail->NilaiY;
            delete head;
            head = tail = NULL;
        }
        cout << delete1 << " dan " << delete2 << " Terhapus";
    }
    else
        cout << "Data Masih kosong\n";
}

void hapusBelakang ()
{
    TNode *hapus;
    int delete1, delete2;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = tail;
            delete1 = hapus->NilaiX;
            delete2 = hapus->NilaiY;
            tail = tail->prev;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            delete1 = tail->NilaiX;
            delete2 = tail->NilaiY;
            delete head;
            head = tail = NULL;
        }
        cout << delete1 << " dan " << delete2 << " Terhapus";
    }
    else
        cout << "Data Masih kosong\n";
}

void hapusTengah (int key1, int key2)
{
    struct TNode *bantu, *hapus;
    int delete1{}, delete2{};
    bantu = head;
    if (!isEmpty())
    {
        while (bantu != NULL)
        {
            if ((head == tail) && (head->NilaiX == key1 && head->NilaiY == key2))
            {
                delete1 = head->NilaiX;
                delete2 = head->NilaiY;
                delete bantu;
                head = tail = NULL;
                break;
            }
            else if ((bantu->NilaiX == key1 && bantu->NilaiY == key2) && countNodes(head) == 2)
            {
                cout << "Data pertama dan terakhir tidak boleh dihapus" << endl;
                break;
            }
            else if (bantu->NilaiX == key1 && bantu->NilaiY == key2)
            {
                delete1 = bantu->NilaiX;
                delete2 = bantu->NilaiY;
                hapus = bantu->prev;
                bantu->prev->next = bantu->next;
                bantu->next->prev = hapus;
                delete bantu;
                break;
            }
            bantu = bantu->next;
        }
        cout << delete1 << " dan " << delete2 << " terhapus " << endl;
    }
    else
        cout << "Linked List Masih Kosong!" << endl;
}
void tampil ()
{
    struct TNode *bantu;
    bantu = head;
    if (isEmpty())
        cout << "Linked List Masih Kosong!" << endl;
    else
    {
        while (bantu != NULL)
        {
            cout << bantu->NilaiX << " " << bantu->NilaiY << endl;
            bantu = bantu->next;
        }
    }
}

void tampilBelakang ()
{
    struct TNode *bantu;
    bantu = tail;
    if (isEmpty())
        cout << "Linked List Masih Kosong!" << endl;
    else
    {
        while (bantu != NULL)
        {
            cout << bantu->NilaiX << " " << bantu->NilaiY << endl;
            bantu = bantu->prev;
        }
    }
}

int main () {
    int pil {}, databaru1{}, databaru2{}, key1{}, key2{};
    do
    {
        cout << endl;
        cout << " ================================" << endl;
        cout << " =      DOUBLY LINKED LIST      =" << endl;
        cout << " ================================" << endl;
        cout << " = 1. Insert Data dari Depan    =" << endl;
        cout << " = 2. Insert Data dari Tengah   =" << endl;
        cout << " = 3. Tambah Data dari Belakang =" << endl;
        cout << " = 4. Hapus Data di Depan       =" << endl;
        cout << " = 5. Hapus Data di Tengah      =" << endl;
        cout << " = 6. Hapus Data di Belakang    =" << endl;
        cout << " = 7. Tampil Data dari Depan    =" << endl;
        cout << " = 8. Tampil Data dari Belakang =" << endl;
        cout << " = 9. Cari Data                 =" << endl;
        cout << " = 10.Selesai                   =" << endl;
        cout << " ================================" << endl;
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
                insertTengahBefore(databaru1, databaru2);
                break;
            }
        case 3:
            system("cls");
            {
                cout << "Masukan Data = ";
                cin >> databaru1 >> databaru2;
                insertBelakang(databaru1, databaru2);
                break;
            }
        case 4:
            system("cls");
            {
                hapusDepan();
                break;
            }
        case 5:
            system("cls");
            {
                cout << "Masukkan data yang ingin dihapus : ";
                cin >> key1 >> key2;
                hapusTengah(key1, key2);
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
                tampilBelakang();
                break;
            }
        case 9:
            system("cls");
            {
                cout << "Cari Data : ";
                cin >> key1 >> key2;
                cariData(key1, key2);
                break;
            }
        }
       
    } while (pil != 10);
    return 0;
}