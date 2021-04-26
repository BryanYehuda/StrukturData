#include <bits/stdc++.h>
using namespace std;

// link soal : https://www.hackerrank.com/contests/modul3-strukturdata/challenges/mudmud-libur

int main() {
    //deklarasi variabel
    string kata;

    //di soal sudah jelas untuk n,q
    int n, q;

    //input n
    scanf("%d",&n);

    //vector atau dynamic array untuk menyimpan string
    vector<string> vector_1;

    //looping untuk input string sebanyak n
    for (int i = 0; i < n; i++) {
        //input string
        cin >> kata;

        //memasukkan string ke vector
        vector_1.push_back(kata);
    }

    //input q
    scanf("%d",&q);

    //looping mencari query sebanyak q
    for (int i = 1; i <= q; i++) {
        //input string
        cin >> kata;

        //variabel untuk menyimpan banyak string
        //yang sama awalannya
        //keterangan di soal ada
        int hitung = 0;

        //vector kedua untuk menyimpan string yang sama tadi,
        //namun yang unique saja
        //keterangan di soal ada
        vector<string> vector_2;

        //looping sebanyak anggota vector_1
        //tiap looping di simpan di variabel string v
        for (string v: vector_1) {

            //mencari yang string yang mirip / mirip awalannya aja
            if (v.find(kata) == 0) {
                //tambah hitung
                hitung++;
                //kalau sama/mirip, tambahkan string itu di vector_2
                vector_2.push_back(v);
            }
        }

        //urutkan data yang ada di vectornya
        //karena waktu input itu tidak urut
        sort(vector_2.begin(), vector_2.end());

        //digunakan untuk menghapus data yang duplikat
        //jadi, hanya menyisakan data yang unique saja
        vector_2.erase( unique(vector_2.begin(),vector_2.end()) , vector_2.end() );

        //jika hitung > 0
        //berarti ada hasilnya
        if (hitung) {
            //cetak dengan format seperti di soal
            //hitung itu banyak string yang mirip
            printf("Kasus #%d: %d\n", i, hitung);

            //looping untuk menampilkan isi dari
            //vector_2 yang isinya string unique semua
            for(int i = 0; i < vector_2.size(); i++) cout << vector_2[i] << endl;
        } else {
            //kalau ga ada hasil, cetak ga ada
            printf("Kasus #%d: Tidak ada hasil\n", i);
        }
    }
    return 0;
}
