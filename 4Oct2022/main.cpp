#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode{
    int data;
    TNode *next;
};

TNode *head, *tail;

void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail==NULL)
        return 1;
    else 
        return 0;
}

void insertDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    
    if(isEmpty()==1)
        head=tail=baru;
    else
    {
        baru->next = head;
        head=baru;
    }
    cout<<"Data masuk\n";
}

void tampil(){
    TNode *bantu;
    bantu=head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout<<bantu->data<<" ";
                bantu=bantu->next;
            }
        }
        else 
            cout <<"Data Masih kosong\n";
}

void hapusDepan()
{

    TNode *hapus;
    int d;
    if (isEmpty()==0)
    {
        if(head!=tail)
        {
            hapus=head;
            d=hapus->data;
            head=head->next;
            delete hapus;
        }
        else
        {
            d=tail->data;
            head=tail=NULL;
        }
    cout<<d<<" Terhapus";
    }
    else 
        cout<<"Data Masih kosong\n";
}

void insertBelakang (int data)
{
    struct TNode *baru;
    baru = new struct TNode;
    baru->data = data;
    baru->next = NULL;
    if (isEmpty())
        head = tail = baru;
    else
    {
        tail->next = baru;
        tail = baru;
    }
    cout<<"Data masuk\n";
}

void searchData (int key)
{
    int flag {-1}; 
    struct TNode *bantu;
    bantu = head;
    if (!isEmpty())
    {
        while (bantu != NULL)
        {
            if (bantu->data == key)
            {
                flag =  key;
                cout << "Data ditemukan : " << flag << endl;
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

void insertAfter (int data)
{
    struct TNode *bantu = head;
    int cari{};
    cout << "Insert data setelah nilai : ";
    cin >> cari;
    if (!isEmpty())
    {
        struct TNode *baru;
        baru = new struct TNode;
        baru->data = data;
        baru->next = NULL;
        
        while (bantu != NULL)
        {
            if (bantu->data == cari)
            {
                baru->next = bantu->next;
                bantu->next = baru;
            }
            bantu = bantu->next;
        }
    }
    else
        cout << "Data tidak ditemukan" << endl;
}
void clear()
{
    TNode *bantu, *hapus;
    bantu =head;
    while(bantu!=NULL)
    {
        hapus=bantu;
        bantu=bantu->next;
        delete hapus;
    }
    head = NULL;
    printf("clear");
}

int main()
{
    int pil{}, databaru{}, cari{};
    do
    {
        system("cls");
        cout<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM LINKED LIST    ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. Insert Depan          ="<<endl;
        cout<<" = 2. Insert Belakang       ="<<endl;
        cout<<" = 3. Insert After          ="<<endl;
        cout<<" = 4. Delete Depan          ="<<endl;
        cout<<" = 5. Tampil Data           ="<<endl;
        cout<<" = 6. Cari Data             ="<<endl;
        cout<<" = 7. Clear                 ="<<endl;
        cout<<" = 8. Exit                  ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
            case 1: system("cls");{
                cout<<"Masukan Data = ";
                cin>>databaru;
                insertDepan(databaru);
                break;
            }
            case 2: system("cls");{
                cout<<"Masukan Data = ";
                cin>>databaru;
                insertBelakang(databaru);
                break;
            }
            case 3: system("cls");{
                cout<<"Masukan Data = ";
                cin>>databaru;
                insertAfter(databaru);
                break;
            }
            case 4: system("cls");{
                hapusDepan();
                break;
            }
            case 5: system("cls");{
                tampil();
                break;
            }
            case 6: system("cls");
            {
                if (!isEmpty())
                {
                    cout<<"Cari Data = ";
                    cin>>databaru;
                    searchData(cari);
                }
                else
                    cout << "Data masih kosong" << endl;
                break;
            }
            case 7: system("cls");{
                clear();
                break;
            }
            case 8: system("cls");{
                return 0;
                break;
            }
            default : system("cls");
            {
                cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
            }
        }
        getch();
    }
    while (pil!=7);
    return 0;
}