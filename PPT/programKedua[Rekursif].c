#include <stdio.h>
//Largest element in array
// Direct Rescursion, karena memanggil diri sendiri pada general case.

//Purwarupa fungsi 
int largest (const int list[], int lowerIndex, int upperIndex);

int main(){
    int intArray[10] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8};

    printf("The largest element in intArray: %d \n", largest(intArray, 0, 9));

    return 0;
}

int largest (const int list[], int lowerIndex, int upperIndex){
    int max;
    if(lowerIndex == upperIndex) // ukuran dari sublist adalah 1
    // Base Case => permasalhan yang dapat langsung terselesaikan
        return list[lowerIndex];
    else{
    // General Case => permasalahan yang tidak dapat langsung dijawab, 
    // tapi dapat diekspresikan secara elegan dengan reskursif
        max = largest(list, lowerIndex + 1, upperIndex);

        if(list[lowerIndex] >= max)
            return list[lowerIndex];
        else
            return max;
    }         
}


