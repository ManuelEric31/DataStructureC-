                                                                                                                                                                                                                                                                                /* The, Manuel Eric Saputra
                                                                                                                                                                                                                                                                                * NIM : A11.2021.13250
                                                                                                                                                                                                                                                                                * Struktur Data : 4303 */
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct player   // Struct ini memuat 3 variable dengan tipe data string, int, dan pointer terhadap struct player itu sendiri
{
    string nama;
    int nilai;
    player *next;
};
player *head = NULL, *tail = NULL; // Deklarasi head dan tail awal mula adalah NULL, karena object struct belum dibuat (kosong)
int top=1;  // Variable ini digunakan untuk penerapan STACK, top pada stack dimulai dari 1
int maks=5; // Variable ini berguna untuk menyaring jumlah maksimal pada stack, karena yang diambil hanya 5 besar tertinggi saja

void tampil()
{
	player *bantu;  // Mendeklarasikan variable pointer dengan tipe data struct player
	int x=1;    // Mendeklarasikan dan menginisialisasi variable x berisi  
	bantu=head; // Pointer bantu akan dimulai dari head, karena kita ingin menampilkan data dimulai dari Node Object yang pertama
	do
	{
		cout<<x<<"."<<bantu->nama<<" - "<<bantu->nilai<<endl;   // Menampilkan nomor urutan, objek player yang memiliki atribut nama (string), objek player yang memiliki atribut nilai (int)    
		bantu=bantu->next;  // Mengupdate alamat pointer bantu menjadi alamat objek yang selanjutnya
		x++;    // Increment x
	}
	while(bantu!=NULL); // Kondisi Looping akan berhenti apabila pointer bantu = NULL (pointer bantu sudah melewati Object Terakhir)
	cout<<endl;
}

void nodebaru(string a, int b)  // Pembuatan Node, ketika kondisi Objek masih kosong 
{
	player *baru;   // Deklarasi variable pointer bernama baru dengan tipe data struct player
	baru=new player;    // Membuat object secara dinamis, kemudian alamat dari object baru tersebut akan di storing kedalam variable pointer baru
	baru->nama=a;   // Object baru dengan atribut nama akan diisi dengan value pada variable a (dari parameter fungsi)
	baru->nilai=b;  // Object baru dengan atribut nilai akan diisi dengan value pada variable b (dari parameter fungsi)
	baru->next=NULL;    // Object baru dengan atribut pointer next akan diisikan NULL, apabila tidak diinisialisasi dengan NULL maka pointer next bisa mengarah ke alamat manapun di memori kita
                                    // Bisa menyebabkan bad memory allocation dan crash pada program
	head=tail=baru; // pointer head dan tail yang sudah dideklarasikan secara global diisikan dengan alamat pada Object (Node) baru
}

void nodebelakang(string a, int b)  // Insert Node (Object baru) di posisi belakang Node
{
	player *baru;   // Deklarasi variable pointer bernama baru dengan tipe data struct player
	baru=new player;    // Membuat object secara dinamis, kemudian alamat dari object baru tersebut akan di storing kedalam variable pointer baru
	baru->nama=a;   // Object baru dengan atribut nama akan diisi dengan value pada variable a (dari parameter fungsi)
	baru->nilai=b;  // Object baru dengan atribut nilai akan diisi dengan value pada variable b (dari parameter fungsi)
	baru->next=NULL;  // Object baru dengan atribut pointer next akan diisikan NULL, apabila tidak diinisialisasi dengan NULL maka pointer next bisa mengarah ke alamat manapun di memori kita
                                    // Bisa menyebabkan bad memory allocation dan crash pada program
	tail->next=baru;    // Mengakases atribut next pada struct player melalui variable pointer tail, kemudian mengisikan alamat object baru ke pointer next
	tail=baru;  // Update alamat pada pointer tail dengan mengisikan alamat Object (Node) baru
                    // Tujuan storing alamat object baru ke tail adalah untuk menjaga tail selalu memiliki alamat objek urutan akhir
}

void nodedepan(string a, int b)
{
	player *baru;   // Deklarasi variable pointer bernama baru dengan tipe data struct player
	baru=new player;    // Membuat object secara dinamis, kemudian alamat dari object baru tersebut akan di storing kedalam variable pointer baru
	baru->nama=a;   // Object baru dengan atribut nama akan diisi dengan value pada variable a (dari parameter fungsi)
	baru->nilai=b;  // Object baru dengan atribut nilai akan diisi dengan value pada variable b (dari parameter fungsi)
	baru->next=head;    // Object baru dengan atribut pointer next akan diisi dengan alamat dari pointer head
	head=baru;  // Update alamat pada pointer head dengan mengisikan alamat Object (Node) baru
                        // Tujuan storing alamat object baru ke head adalah untuk menjaga head selalu memiliki alamat objek urutan awal
}

void deletebelakang()
{
	player *bantu;  // Deklarasi variable pointer bernama baru dengan tipe data struct player
	bantu=head; // Pointer bantu akan dimulai dari head
	while(bantu!=NULL)  // Kondisi loop akan berhenti apabila pointer bantu menjadi NULL
	{
		if(bantu->next->nama==tail->nama)   // Hal ini tereksekusi apabila, pointer bantu sudah berada di posisi sebelum object terakhir (sebelum pointer tail)
		{
			bantu->next=NULL;   // Pointer bantu mengakses atribut pointer next dan diisikan NULL, apabila tidak diinisialisasi dengan NULL maka pointer next bisa mengarah ke alamat manapun di memori kita
                                                // Bisa menyebabkan bad memory allocation dan crash pada program
			delete tail;    //  Menghapus objek pada pointer tail secara dinamis 
			tail=bantu;	//  Pada tahap ini, pointer bantu akan berhenti sebelum objek yang terakhir, maka dari itu pointer tail diisikan dengan alamat pointer bantu
		}
		bantu=bantu->next; // Mengupdate alamat pointer bantu menjadi alamat objek yang selanjutnya
	}
}

void nodetengah(string a, int b)
{
	player *bantu, *baru;   // Deklarasi variable pointer bernama baru dan bantu dengan tipe data struct player
	baru=new player;    // Membuat object secara dinamis, kemudian alamat dari object baru tersebut akan di storing kedalam variable pointer baru
	baru->nama=a;   // Object baru dengan atribut nama akan diisi dengan value pada variable a (dari parameter fungsi)
	baru->nilai=b;  // Object baru dengan atribut nilai akan diisi dengan value pada variable b (dari parameter fungsi)
	baru->next=NULL;    // Object baru dengan atribut pointer next akan diisikan NULL, apabila tidak diinisialisasi dengan NULL maka pointer next bisa mengarah ke alamat manapun di memori kita
                                    // Bisa menyebabkan bad memory allocation dan crash pada program
	
	bantu=head; //Pointer bantu akan dimulai dari head, karena kita ingin menampilkan data dimulai dari Node Object yang pertama
	do
	{
		if((b < bantu->nilai) && (b > bantu->next->nilai))  // Tereksekusi apabila, atribut nilai pada object baru lebih kecil daripada atribut nilai yang diakses melalui pointer bantu
                                                                                          // dan lebih besar daripada atribut nilai yang diakses melalui pointer bantu next (object selanjutnya)
		{
			baru->next=bantu->next;     // Atribut pointer next yang diakses melalui pointer baru diiskan dengan alamat pointer next yang diakses melalui pointer bantu
			bantu->next=baru;   // Atribut pointer next yang diakses melalui pointer bantu diisikan dengan alamat pointer yang ditampung baru 
			break;  // Keluar dari loop
		}
		bantu=bantu->next;  // Mengupdate alamat pointer bantu menjadi alamat objek yang selanjutnya
	}
	while(bantu!=NULL); // Kondisi loop akan berhenti apabila pointer bantu menjadi NULL
}


int main()
{
    string nmplayer[11]={"Agus","Indah","Heru","Kiki","Bagus","Yuli","Budi","Carlie","Linda","Putri","Feri"};
    int point[11]={100,50,110,120,80,90,140,95,160,115,88};
    
    for(int a=0;a<=10;a++)
    {
        cout<<"Hasil Permainan Terakhir : "<<nmplayer[a]<<" "<<point[a]<<endl;
        //disini code utk mengatur (menyimpan/menghapus) nama player dan nilainya
        if(top==1) //jika stack masih kosong
        {
        	nodebaru(nmplayer[a],point[a]);//menyimpan node baru ke list/
         	top++;						   //top bertambah
  		}
		if((top<maks) && (tail->nilai>point[a])) //jika nilai player lebih kecil dari juara terakhir, syarat top<maks
		{
			nodebelakang(nmplayer[a],point[a]); //insert node di belakang
			top++;
		}
		if(point[a]>head->nilai) //jika nilai player lebih besar dari juara 1 nya
		{
			nodedepan(nmplayer[a],point[a]); //insert node di depan
			top++;
		}
		
		if((point[a] < head->nilai) && (point[a] > tail->nilai))//jika nilai player lebih besar dari juara terakhir dan lebih kecil dari juara pertama
		{
			nodetengah(nmplayer[a],point[a]);   //insert node di tengah
			top++;
		}
		
		if(top>maks+1) //jika ada node di nomor 6 maka otomatis data belakang dihapus
		{
			deletebelakang(); /* delete node paling akhir */
			top--;			  /* top berkurang */
		}
		tampil();
		getch();
	}

    return 0;
}
