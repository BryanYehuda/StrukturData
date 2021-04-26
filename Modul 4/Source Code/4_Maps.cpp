#include <iostream>
#include <map>
using namespace std;

//BY  : Bryan Yehuda
//NRP : 05311940000021

int main()
{
    map<string, int> m; //Inisialisasi map dengan tipe data string dan integer dengan nama m
    int q;
    cin >> q;

    while (q > 0)
    {
        int type;
        string x;
        cin >> type >> x;

        if (type == 1) //jika 1 maka akan memberikan tanda nilai Y terhadap siswa X
        {
            int y;
            cin >> y;

            if (m.find(x) == m.end()) //mencari index X terlebih dahulu
            {
                m.insert(make_pair(x, y)); //jika tidak ada maka buat index terlebih dahulu
            }
            else
            {
                int old_val; //jika ada, maka tambahkan value dari map sebelumnya
                old_val = m[x];
                m.erase(x);
                int new_val = old_val + y;
                m.insert(make_pair(x, new_val));
            }
        }
        else if (type == 2) //jika 2 maka akan menghapus nilai dari siswa X
        {
            m.erase(x); 
        }
        else if (type == 3) //jika 3 maka print value
        {
            cout << m[x] << '\n';
        }
        q--;
    }

    return (0);
}
