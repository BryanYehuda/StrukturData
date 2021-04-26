#include <bits/stdc++.h> 
#include <chrono> 

using namespace std; 
  
/* Function untuk melakukan Insertion Sort*/
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        
        /* Pindahkan element dari arr[0..i-1], yang lebih besar dari
		key, maka posisi akan lebih depan dari posisi saat ini */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  
// Print Array 
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  

int main()  
{  
    int arr[] = { 1,5,7,3,2,10,6,8,9,12 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
  	
  	auto start = std::chrono::high_resolution_clock::now();
    insertionSort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Durasi yang dibutuhkan " <<duration.count() << " microdetik"<< endl;
  
    return 0;  
}  
