//Bubble Sort  
#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
   
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
        
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
  
//Fungsi untuk print Array
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
//Main Function 
int main()  
{  
    int arr[] = {1,5,7,3,2,10,6,8,9,12};  
    int n = sizeof(arr)/sizeof(arr[0]);
	auto start = std::chrono::high_resolution_clock::now();  
    bubbleSort(arr, n);  
    cout<<"Sorted array: \n";  
    printArray(arr, n);
	auto stop = std::chrono::high_resolution_clock::now(); 
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); 
    cout << "Durasi yang dibutuhkan "
         << duration.count() << " microdetik" << endl;  
    return 0;  
}  
