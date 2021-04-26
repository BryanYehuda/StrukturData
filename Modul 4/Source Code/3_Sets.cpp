#include <iostream>
#include <set>
using namespace std;

//BY  : Bryan Yehuda Mannuel
//NRP : 05311940000021

int main()
{
    set<int> s; //deklarasi set dengan nama s value int
    int q;
    cin >> q;

    while (q > 0)
    {
        int y, x;
        cin >> y >> x; //masukan perintah tambahkan, hapus, atau display dan target nilai angkanya
        
        if (y == 1) //memfilter tiap query
        {
            s.insert(x); //inputkan angka
        }
        else if (y == 2)
        {
            s.erase(x); //hapus angka
        }
        else if (y == 3)
        {
            if (s.find(x) == s.end()) //mencari apakah value x ada atau tidak
            {
                cout << "No" << endl; //jika tidak ada
            }
            else
            {
                cout << "Yes" << endl; //jika ada
            }
        }
        q--;
    }
    return (0);
}
