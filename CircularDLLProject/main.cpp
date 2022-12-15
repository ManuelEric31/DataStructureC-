#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct TNode
{
    TNode *prev;
    string judulLagu;
    string artist;
    int rating;
    TNode *next;
} *head = NULL, *tail = NULL, *bantuan = NULL;

int countNodes(struct TNode *p)
{
    int count{};
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

int isEmpty()
{
    if (tail == NULL)
        return 1;
    else
        return 0;
}

 void cariData (string key1,string key2)
{
     string flag1{}, flag2{};
     struct TNode *bantu;
     bantu = head;
     do 
    {
        if (bantu->judulLagu == key1 && bantu->artist == key2)
        {
            flag1 = key1;
            flag2 = key2;
            cout << "Lagu ditemukan : " << flag1 << "(Judul) dan " << flag2 << "(Artist)\n";
            break;
        }
        bantu = bantu->next;
    }while (bantu != head);
 }
void insertDepan(string databaru1, string databaru2, int databaru3)
{
    TNode *baru;
    baru = new TNode;
    baru->prev = NULL;
    baru->judulLagu = databaru1;
    baru->artist = databaru2;
    baru->rating = databaru3;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
        tail->next = head;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Data masuk\n";
}

void insertBelakang(string databaru1, string databaru2, int databaru3)
{
    struct TNode *baru;
    baru = new struct TNode;
    baru->prev = NULL;
    baru->judulLagu = databaru1;
    baru->artist = databaru2;
    baru->rating = databaru3;
    baru->next = NULL;
    if (isEmpty())
    {
        head = tail = baru;
        tail->next = head;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Data masuk\n";
}

void insertTengahBefore(string databaru1, string databaru2, int databaru3)
{
    struct TNode *bantu = head;
    string cari1{}, cari2{};
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Masukkan Sebelum Judul Lagu : ";
    std::getline(std::cin, cari1);
    std::cout << "Masukkan Sebelum Nama Artist : ";
    std::getline(std::cin, cari2);
    if (!isEmpty())
    {
        struct TNode *baru;
        baru = new struct TNode;
        baru->prev = NULL;
        baru->judulLagu = databaru1;
        baru->artist = databaru2;
        baru->rating = databaru3;
        baru->next = NULL;
        
        do
        {
            if ((head == tail) && (head->judulLagu == cari1 && head->artist == cari2))
            {
                baru->next = head;
                head->prev = baru;
                head = baru;
                tail->next = head;
                head->prev = tail;
                break;
            }
            else if (bantu->next->judulLagu == cari1 && bantu->next->artist == cari2)
            {
                if (bantu -> next != head)
                {
                    baru->prev = bantu;
                    baru->next = bantu->next;
                    bantu->next = baru;
                    baru->next->prev = baru;
                    break;
                }
                else
                    cout << "Tidak Bisa Menambah Lagu Sebelum Data Pertama!\n";
            }
            bantu = bantu->next;
        } while (bantu != head);
    }
    else
        cout << "Data tidak ditemukan" << endl;
}

void hapusDepan()
{
    TNode *hapus;
    string delete1, delete2;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = head;
            delete1 = hapus->judulLagu;
            delete2 = hapus->artist;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete hapus;
        }
        else
        {
            delete1 = tail->judulLagu;
            delete2 = tail->artist;
            delete head;
            head = tail = NULL;
        }
        cout << delete1 << "(Judul) dan " << delete2 <<  "(Artist) " <<" Terhapus\n";
    }
    else
        cout << "Data Masih kosong\n";
}

void hapusBelakang()
{
    TNode *hapus;
    string delete1, delete2;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = tail;
            delete1 = hapus->judulLagu;
            delete2 = hapus->artist;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete hapus;
        }
        else
        {
            delete1 = tail->judulLagu;
            delete2 = tail->artist;
            delete head;
            head = tail = NULL;
        }
        cout << delete1 << "(Judul) dan " << delete2 <<  "(Artist) " <<" Terhapus\n";
    }
    else
        cout << "Data Masih kosong\n";
}

 void hapusTengah(string key1, string key2)
 {
     struct TNode *bantu, *hapus;
     string delete1{}, delete2{};
     bantu = head;
         do 
        {
             if ((head == tail) && (head->judulLagu == key1 && head->artist == key2))
            {
                 delete1 = head->judulLagu;
                 delete2 = head->artist;
                 delete bantu;
                 head = tail = NULL;
                 break;
            }
             else if ((bantu->judulLagu == key1 && bantu->artist == key2) && countNodes(head) == 2)
             {
                 cout << "Data pertama dan terakhir tidak boleh dihapus" << endl;
                 break;
             }
             else if (bantu->next->judulLagu == key1 && bantu->next->artist == key2)
            {
                delete1 = bantu->next->judulLagu;
                delete2 = bantu->next->artist;
                hapus = bantu->next;
                bantu->next = hapus->next;
                hapus->next->prev = bantu;
                delete hapus;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);
         cout << delete1 << "(Judul) dan " << delete2 << "(Artist) terhapus " << endl;
 }
void tampil()
{
    struct TNode *bantu;
    int i{1};
    string headerPlaylist{"Playlist Lagu Spotifyku"};
    bantu = head;
    if (isEmpty())
        cout << "Playlist Lagu Masih Kosong!" << endl;
    else
    {
        cout << setw(45) << std::right << headerPlaylist  << endl;
        cout  << setw(64) << setfill('=') << "" << endl;
        cout << setfill(' ');
        do
        {
            cout << setw(10) << std::left << i << std::setw(20) << std::left <<bantu->judulLagu
            << std::setw(30) << std::left << bantu->artist
            << std::setw(2) << std::left << bantu->rating <<endl;
            bantu = bantu->next;
            i++;
        } while (bantu != head);
        cout << setfill(' ');
        cout  << setw(64) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
}

void tampilBelakang()
{
    struct TNode *bantu;
    int i{1};
    string headerPlaylist{"Playlist Lagu Spotifyku"};
    bantu = tail;
   if (isEmpty())
        cout << "Playlist Lagu Masih Kosong!" << endl;
    else
    {
        cout << setw(45) << std::right << headerPlaylist  << endl;
        cout  << setw(64) << setfill('=') << "" << endl;
        cout << setfill(' ');
        do
        {
            cout << setw(10) << std::left << i << std::setw(20) << std::left <<bantu->judulLagu
            << std::setw(30) << std::left << bantu->artist
            << std::setw(2) << std::left << bantu->rating <<endl;
            bantu = bantu->prev;
            i++;
        } while (bantu != tail);
        cout << setfill(' ');
        cout  << setw(64) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
}

void playFirstSong ()
{
    bantuan = head;
    if (!isEmpty())
    {
        cout << setw(40) << std::right << "Memainkan Musik Pertama"  << endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
        cout << std::setw(20) << std::left << bantuan->judulLagu
        << std::setw(30) << std::left <<  bantuan->artist
        << std::setw(2) << std::left << bantuan->rating <<endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
    else
        cout << "Playlist Lagu Masih Kosong!" << endl;
}
void playNextSong ()
{
    if (bantuan == NULL)
    {
        playFirstSong();
        return;
    }
    if (!isEmpty())
    {
         if (bantuan != NULL)
            bantuan = bantuan->next;
        cout << setw(40) << std::right << "Memainkan Musik Selanjutnya"  << endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
        cout << std::setw(20) << std::left << bantuan->judulLagu
        << std::setw(30) << std::left <<  bantuan->artist
        << std::setw(2) << std::left << bantuan->rating <<endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
    else
        cout << "Playlist Lagu Masih Kosong!" << endl;
}
void playPrevSong ()
{
    if (bantuan == NULL)
    {
        playFirstSong();
        return;
    }
    if (!isEmpty())
    {
        if (bantuan != NULL)
            bantuan = bantuan->prev;
        cout << setw(40) << std::right << "Memainkan Musik Sebelumnya"  << endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
        cout << std::setw(20) << std::left << bantuan->judulLagu
        << std::setw(30) << std::left <<  bantuan->artist
        << std::setw(2) << std::left << bantuan->rating <<endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
    else
        cout << "Playlist Lagu Masih Kosong!" << endl;
}
int main()
{
    system("Color 0B");
    string judul{}, artist{}, key1{}, key2{};
    int pil{}, rating{};
    do
    {
        cout << endl;
        cout << " ================================" << endl;
        cout << " =      MENU PLAYLIST LAGU      =" << endl;
        cout << " ================================" << endl;
        cout << " = 1. Insert Lagu dari Depan    =" << endl;
        cout << " = 2. Insert Lagu dari Tengah   =" << endl;
        cout << " = 3. Tambah Lagu dari Belakang =" << endl;
        cout << " = 4. Hapus Lagu di Depan       =" << endl;
        cout << " = 5. Hapus Lagu di Tengah      =" << endl;
        cout << " = 6. Hapus Lagu di Belakang    =" << endl;
        cout << " = 7. Tampil Lagu dari Depan    =" << endl;
        cout << " = 8. Tampil Lagu dari Belakang =" << endl;
        cout << " = 9. Cari Lagu                 =" << endl;
        cout << " = 10. Mainkan Lagu Terawal     =" << endl;
        cout << " = 11. Mainkan Lagu Selanjutnya =" << endl;
        cout << " = 12. Mainkan Lagu Sebelumnya  =" << endl;
        cout << " = 13.Selesai                   =" << endl;
        cout << " ================================" << endl;
        cout << " Masukan Pilihan : ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            system("cls");
            {
                std::cout << "Tambahkan Lagu Baru ke Playlist" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Masukkan Judul Lagu : ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan Nama Artist : ";
                std::getline(std::cin, artist);
                std::cout << "Masukkan Rating (1-5): ";
                std::cin >> rating;
                insertDepan(judul,artist, rating);
                break;
            }
        case 2:
            system("cls");
            {
                std::cout << "Tambahkan Lagu Baru ke Playlist" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Masukkan Judul Lagu : ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan Nama Artist: ";
                std::getline(std::cin, artist);
                std::cout << "Masukkan Rating (1-5): ";
                std::cin >> rating;
                insertTengahBefore(judul,artist,rating);
                break;
            }
        case 3:
            system("cls");
            {
                std::cout << "Tambahkan Lagu Baru ke Playlist" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Masukkan Judul Lagu : ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan Nama Artist : ";
                std::getline(std::cin, artist);
                std::cout << "Masukkan Rating (1-5): ";
                std::cin >> rating;
                insertBelakang(judul, artist, rating);
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
                 if (!isEmpty())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Masukkan Judul Lagu : ";
                    std::getline(std::cin, judul);
                    std::cout << "Masukkan Nama Artist : ";
                    std::getline(std::cin, artist);
                    hapusTengah(judul, artist);
                }
                else
                    cout << "Playlist Lagu Masih Kosong!\n";
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
                if (!isEmpty())
                {
                    std::cout << "Cari Lagu dari Playlist" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Masukkan Judul Lagu : ";
                    std::getline(std::cin, judul);
                    std::cout << "Masukkan Nama Artist : ";
                    std::getline(std::cin, artist);
                    cariData(judul, artist);
                }
                else
                    cout << "Playlist Lagu Masih Kosong!" << endl;
                break;
            }
            case 10:
            system("cls");
            {
                playFirstSong();
                break;
            }
            case 11:
            system("cls");
            {
                playNextSong();
                break;
            }
            case 12:
            system("cls");
            {
                playPrevSong();
                break;
            }
            case 13 :
            system("cls");
            {
                exit(1);
                break;
            }
        }
        getch();
    } while (pil != 13);
    return 0;
}   