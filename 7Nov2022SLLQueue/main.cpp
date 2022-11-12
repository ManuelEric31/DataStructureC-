#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int top;
    string nama;
    int nilai;
    struct Queue *next;
} *head = NULL, *tail = NULL;

void init(struct Queue *st)
{
    st->top = 0;
}

int countNodes(struct Queue *bantu)
{
    int count{};
    bantu = head;
    if (bantu == NULL)
        cout << "Node is empty!" << endl;
    else
    {
        while (bantu != NULL)
        {
            count++;
            bantu = bantu->next;
        }
    }
    return count;
}
int isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}

int isFullQueue(struct Queue *st)
{
    if (st->top == st->size)
        return 1;
    return 0;
}

int isEmptyQueue(struct Queue *st)
{
    if (st->top == 0)
        return 1;
    return 0;
}
void insertBelakang(struct Queue *st, string nama, int nilai)
{
    struct Queue *newNode;
    newNode = new struct Queue;
    newNode->nama = nama;
    newNode->nilai = nilai;
    newNode->next = NULL;

    if (isEmpty())
    {
        head = tail = newNode;
        st->top++;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        st->top++;
    }
    cout << "Data masuk!" << endl;
}

void hapusDepan(struct Queue *st)
{
    Queue *hapus = head;
    string delete1;
    int delete2;
    if (isEmpty() == 0)
    {
        if (head == tail)
        {
            delete1 = tail->nama;
            delete2 = tail->nilai;
            st->top--;
            delete hapus;
            head = tail = NULL;
        }
        else
        {
            delete1 = tail->nama;
            delete2 = tail->nilai;
            head = head->next;
            st->top--;
            delete hapus;
        }
        cout << delete1 << " dan " << delete2 << " Terhapus\n";
    }
    else
        cout << "Data Masih kosong\n";
}

void reverseLink()
{
    struct Queue *p = head, *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    tail = head;
    head = q;
}

void display()
{
    struct Queue *bantu;
    bantu = head;
    if (!isEmpty())
    {
        cout << "\n\nVisualisasi pada Queue : " << endl;
        cout << "=========================" << endl;
        while (bantu != NULL)
        {
            cout << bantu->nama << " dan " << bantu->nilai << endl;
            cout << "=========================" << endl;
            bantu = bantu->next;
        }
    }
    else
        cout << "Data Linked List Kosong" << endl;
}
int main()
{
    int pilih{}, nilai{};
    string nama;
    struct Queue *newObj;
    newObj = new struct Queue;
    init(newObj);
    cout << "Masukkan size pada queue linked list : ";
    cin >> newObj->size;

    do
    {
        cout << "\n1. INQUEUE" << endl;
        cout << "2. DEQUEUE" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Masukkan Pilihan anda [1-3] : ";
        cin >> pilih;

        if (pilih == 1)
        {
            // Menjalankan : Tambah Node di //
            if (!isFullQueue(newObj))
            {
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan nilai : ";
                cin >> nilai;
                insertBelakang(newObj, nama, nilai);
            }
            else
                cout << "Queue is Full!" << endl;
        }
        if (pilih == 2)
        {
            if (!isEmptyQueue(newObj))
                hapusDepan(newObj);
            else
                cout << "Queue is empty!" << endl;
        }
        if (pilih == 3)
        {
            reverseLink();
            display();
        }
        if (pilih == 4)
        {
            delete newObj;
            exit(1);
        }

    } while (pilih != 4);

    return 0;
}