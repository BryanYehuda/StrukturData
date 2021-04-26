#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//By  : Bryan Yehuda Mannuel
//NRP : 05311940000021

int main() {
    int x,y,a,b,c,size;
    cin>>x; 
    vector<int> z; //define vector
    for(y=0;y<x;y++)
        {
        int x;
        cin>>x;
        z.push_back(x);
        }
    cin>>a>>b>>c; //inputan a sebagai nilai mana yang akan dihapus index ke berapa 
                  //inputan b untuk sebagai penentu awal range yang kaan dihapus
                  //inputan c untuk sebagai penentu akhir dari range yang akan dihapus
    z.erase(z.begin()+a-1);  //eksekusi hapus pada suatu index tertentu
    z.erase(z.begin()+b-1,z.begin()+c-1); //eksekusi hapus pada suatu range
    
    size=z.size(); //menata ulang banyaknya angka yang tersisa
    
    cout<<size<<endl; //print jumlah total ada berapa angka saat ini
    for(y=0;y<size;y++) //perulangan untuk menghasilkan daftar angka yang tersedia
        cout<<z[y]<<" "; 
    return 0;
}
