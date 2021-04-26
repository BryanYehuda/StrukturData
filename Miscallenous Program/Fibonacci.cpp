#include<stdio.h>

int rFibNum(int a, int b, int n)
{
	if (n == 1)
	{
		return a;
	}
	else if (n == 2)
	{
		return b;
	}
	else
	{
		return rFibNum(a, b, n - 1) + rFibNum(a, b, n - 2);
	}
}

int main()
{
	int firstFibNum;
	int secondFibNum;
	int nth;
	printf("Masukkan bilangan Fibonacci Pertama : ");
	scanf("%d", &firstFibNum);
	printf("\n");
	printf("Masukkan bilangan Fibonacci Kedua : ");
	scanf("%d", &secondFibNum);
	printf("\n");
	printf("Masukkan bilangan posisi bilangan Fibonacci yang diinginkan : ");
	scanf("%d", &nth);
	printf("\n");
	printf("Bilangan Fibonacci di posisi %d adalah %d", nth,  rFibNum(firstFibNum, secondFibNum, nth));
	return 0;
}

