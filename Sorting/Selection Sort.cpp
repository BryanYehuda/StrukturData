//Selection Sort 
#include <bits/stdc++.h> 
#include <algorithm> 
#include <chrono> 
#include <iostream> 
#include<vector> 
using namespace std; 
using namespace std::chrono; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    //Satu demi satu majukan batas dari subarray yang belum di sort 
    for (i = 0; i < n-1; i++)  
    {  
        //Cari elemen minimum yang ada di dalam array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        //Tukar elemen minimum yang ditemukan dengan elemen pertama  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  
  
//Fungsi untuk print Array
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
//Main Function 
int main()  
{  
    int arr[] = {1,5,7,3,2,10,6,8,9,12};  
    int n = sizeof(arr)/sizeof(arr[0]);
	auto start = std::chrono::high_resolution_clock::now();  
    selectionSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n); 
	auto stop = std::chrono::high_resolution_clock::now(); 
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); 
    cout << "Durasi yang dibutuhkan "
         << duration.count() << " microdetik" << endl; 
  
    return 0;  
}  
