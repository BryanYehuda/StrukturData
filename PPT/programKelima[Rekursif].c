#include <stdio.h> 
// Decimal to binary conversion 
// Direct Rescursion, karena memanggil diri sendiri pada general case.

// using recursion 
int decToBin(int decNum) 
{ 
	if (decNum == 0) 
    // Base Case
		return 0; 
	else
    //General Case
		return (decNum % 2 + 10 * 
				decToBin(decNum / 2)); 
} 

// Driver code 
int main() 
{ 
	int decNum;
	printf("Please input your decimal to be convert to binary: ");
	scanf("%d", &decNum);
	printf("your decimal after convert to binary is %d", decToBin(decNum)); 
	return 0; 
} 
