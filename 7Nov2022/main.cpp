#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    string nama;
    int nilai;
    struct Stack *next;
} *head = NULL, *tail = NULL;

void init (struct Stack *st)
{
    st->top = 0;
}

int countNodes (struct Stack *bantu)
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
int isEmpty ()
{
    if (head == NULL)
        return 1;
    return 0;
}

int isFullStack (struct Stack *st)
{
    if (st->top == st->size)
        return 1;
    return 0;
}

int isEmptyStack (struct Stack *st)
{
    if (st->top == 0)
        return 1;
    return 0;
}
void insertBelakang (struct Stack *st, string nama, int nilai)
{
    struct Stack *newNode;
    newNode = new struct Stack;
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

void hapusBelakang (struct Stack *st)
{
    Stack *bantu = tail;
    Stack *hapus = head;
    string delete1; 
    int delete2;
    if (isEmpty() == 0)
    {
        for (int i = 0; i < countNodes(head) - 2; i++)
            hapus = hapus->next;
        if (hapus->next != NULL)
        {
            delete1 = tail->nama;
            delete2 = tail->nilai;
            tail = hapus;
            tail->next = NULL;
            st->top--;
            delete bantu;
        }
        else
        {
            delete1 = tail->nama;
            delete2 = tail->nilai;
            delete bantu;
            st->top--;
            head = tail = NULL;
        }
        cout << delete1 << " dan " << delete2 << " Terhapus\n";
    }
    else
        cout << "Data Masih kosong\n";
}

void reverseLink ()
{
    struct Stack *p=head, *q=NULL, *r=NULL;
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
void display ()
{
    struct Stack *bantu;
    bantu = head;
    if (!isEmpty())
    {
        cout << "\n\nVisualisasi pada Stack : " << endl;
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
int main () {
    int pilih {}, nilai{};
    string nama;
    struct Stack *newObj;
    newObj = new struct Stack;
    init(newObj);
    cout << "Masukkan size pada stack linked list : ";
    cin >> newObj->size;
    
    do
    {
        cout << "\n1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Masukkan Pilihan anda [1-3] : ";
        cin >> pilih;
        
        if (pilih == 1)
        {
            // Menjalankan : Tambah Node di //
            if (!isFullStack(newObj))
            {
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan nilai : ";
                cin >> nilai;
                insertBelakang(newObj, nama, nilai);
            }
           else
               cout << "Stack is Full!" << endl;
        }
        if (pilih == 2)
        {
            if (!isEmptyStack(newObj))
                hapusBelakang(newObj);
            else
                cout << "Stack is empty!" << endl;
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