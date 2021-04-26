#include <stdio.h>
// Factorial
// Direct Rescursion, karena memanggil diri sendiri pada general case.


int fact(int num){
    if(num == 0) 
    // Base Case => permasalhan yang dapat langsung terselesaikan
        return 1;
    else 
    // General Case => permasalahan yang tidak dapat langsung dijawab, 
    // tapi dapat diekspresikan secara elegan dengan reskursif
        return num *fact(num-1);
}

int main(){
    printf("Faktorial dari 5 adalah : %d\n", fact(5));
    return 0;
}



