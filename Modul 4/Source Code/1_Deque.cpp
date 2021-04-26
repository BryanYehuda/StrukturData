#include<bits/stdc++.h> 
#include <deque> 
using namespace std; 

//By  : Bryan Yehuda Mannuel
//NRP : 05311940000021

void KMax(int arr[], int x, int y)
{
    deque<int> De_que; //pemanggilan fungsi deque
    int i;
    
    for(i=0; i<y; i++) //lakukan perulangan untuk mengikat subarray
    {
        while(!De_que.empty() && arr[i]>=arr[De_que.back()]) //jika tidak kosong, deque dan index array yg akan 
        {                                                    //dimasukan lebih besar dari yang ada di belakang
            De_que.pop_back(); //hapus index belakang
        }
        De_que.push_back(i); //secara default jika kosong akan memasukan posisinya dibelakang 
                             //agar dapat dibandingkan dengan index array yang baru masuk ke deque
    }
    
    for(i=y; i<x; i++) //perulangan lanjutan untuk mendapatkan nilai tertinggi dari range subarray
    {
        cout<<arr[De_que.front()]<<" "; //print yang ada di depan karena paling besar
        while(!De_que.empty() && De_que.front()<=i-y) //apabila deque, isi dan nilai front deque itu kurang dari i-y
        {
            De_que.pop_front(); //akan menghapus posisi paling depan
        }
        while(!De_que.empty() && arr[i]>=arr[De_que.back()]) //jika deque isi dan nilai array index lanjutan itu 
        													 //lebih besar dari yang di back
        {
            De_que.pop_back(); //maka hapus yang di back
        }
        De_que.push_back(i); //secara default index array lanjutan akan ditaruh di belakang deque
        
    }
    cout<<arr[De_que.front()]<<endl; //tampilkan hasil semua yang terbesar dari tiap subarray
}

int main()
{

   int t;
   scanf("%d",&t);
   while(t--)
   {
      int x,y;//inisialisasi variable untuk menerima banyaknya array dan size subarraynya
      cin>>x>>y;
       int i; 
      int * arr=new int [x]; //inisialisasi pointer array 
       for(i=0;i<x;i++) //perulangan inputan user hingga memenuhi batas array yang telah didefinisikan
           cin>>arr[i];
       KMax(arr, x, y); //parsing array data, banyaknya range array, dan size sub arraynya.
       
     }
     return 0;
}
