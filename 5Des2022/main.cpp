#include <iostream>
using namespace std;
int kota[4][4];

int main () {
   for (int i = 0; i < 4; i++)
   {
        for (int j = 0; j < 4; j++)
        {
            cout << "Masukkan jarak dari kota " << i << " ke kota " << j << " : ";
            if (i == j)
            {
                kota[i][j] = 0;
                cout << kota[i][j] << endl;
            }
           else if (i > j)
           {
                kota[i][j] = kota[j][i];
                cout << kota [i][j] << endl;
           }
            else
                cin >> kota[i][j];
        }
   }
   
   for (int i = 0; i < 4; i++)
   {
       for (int j = 0; j < 4; j++)
       {
           cout << kota[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}