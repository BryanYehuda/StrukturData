#include <stdio.h>
// Tower of Hanoi
// Direct Rescursion, karena memanggil diri sendiri pada general case.

//Prototipe Fungsi
void moveDisks(int count, int needle1, int needle3, int needle2);

int main(){
    int count = 3; // Banyaknya cakram yang akan dipindah
    moveDisks(count, 1, 3, 2); // 1, 3, dan 2 merupakan banyaknya rod
    return 0;
}

void moveDisks(int count, int needle1, int needle3, int needle2){
    if(count > 0){
    // General Case => permasalahan yang tidak dapat langsung dijawab, 
    // tapi dapat diekspresikan secara elegan dengan reskursif
        moveDisks(count - 1, needle1, needle2, needle3);
        printf("Move disk %d from %d to %d . \n", count, needle1, needle3);

        moveDisks(count - 1, needle2, needle3, needle1);
    }
}