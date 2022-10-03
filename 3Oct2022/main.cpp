#include <iostream>
#include <string.h>
using namespace std;

struct Stack 
{
    int top;
    int front;
    int size;
    char *S;
};

void create (struct Stack *st)
{
    cout << "Enter the size of the stack : ";
    cin >> st->size;
    st->top = st->front = -1;
    st->S = new char [st->size]; 
}

void display (struct Stack st)
{
    int i;
    for (i = st.front; i <= st.top; i++)
    {
            cout << st.S[i] << " ";
    }
    cout << endl;
}

int peek (struct Stack st, int pos)
{
    int x {-1};
    if (st.top-pos+1 < 0)
        cout << "Position Invalid" << endl;
    else
        x = st.S[st.top-pos+1];
    return x;
}

int isEmpty (struct Stack st)
{
    if (st.top == -1 || st.top == st.front)
        return 1;
    return 0;
}

int isFull (struct Stack st)
{
    return st.top == st.size-1;
}

void push (struct Stack *st, char value)
{
    if (isFull(*st))
        cout << "Stack overflow" << endl;
    else
    {
        if (st->front == -1)
            st->front++;
        st->top++;
        st->S[st->top] = value;
    }
}

int pop (struct Stack *st)
{
    int x {-1};
    if (isEmpty(*st))
        cout << "Stack underflow" << endl;
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int dequeue (struct Stack *st)
{
    int x {-1};
    if (isEmpty(*st))
        cout << "Stack underflow" << endl;
    else
    {
        x = st->S[st->front++];
    }
    return x;
}

int stackTop (struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main () {
    
    struct Stack stack1;
    create(&stack1);
    char kata [100] = {"231W1i1L31O1Z21V1E1Y1O1U21K21U1"};
    
    for (int i = 0; kata[i] != '\0';i++)
    {
        if (kata[i] == '1')
        {
            cout << "Push data 1 : " << kata[++i] << endl;
            push(&stack1, kata[i]);
        }
        else if (kata[i] == '2')
        {
             cout << "Pop Data 2 " << endl;
             pop(&stack1);
        }
        else if (kata[i] == '3')
        {
            cout << "Dequeue Data 3  " << endl;
            dequeue(&stack1);
        }
    }
    
    cout << "\nSandi Rahasia : ";
    display(stack1);
    return 0;
}