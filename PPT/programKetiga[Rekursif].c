#include <stdio.h>
// Fibonacci Number
// Direct Rescursion, karena memanggil diri sendiri pada general case.

//Purwarupa fungsi
int rFibNum(int a, int b, int n);

int main(){
    int firstFiboNb, secondFiboNb, nth;
    
    printf("Enter the first Fibonacci number: \n");
    scanf("%d", &firstFiboNb);
    
    printf("Enter the second Fibonacci number: \n");
    scanf("%d", &secondFiboNb);
    
    printf("Enter the position of the desired Fibonacci number: \n");
    scanf("%d", &nth);
    
    printf("The Fibonacci number at position %d is : %d \n", nth, rFibNum(firstFiboNb, secondFiboNb, nth));
    
    return 0;
}

int rFibNum(int a, int b, int n){
    if(n==1)
    // Base Case => permasalhan yang dapat langsung terselesaikan
        return a;
    else if (n==2)
    // Base Case => permasalhan yang dapat langsung terselesaikan
        return b;
    else
    // General Case => permasalahan yang tidak dapat langsung dijawab, 
    // tapi dapat diekspresikan secara elegan dengan reskursif
        return rFibNum(a, b, n - 1) + rFibNum(a, b, n - 2);
}
