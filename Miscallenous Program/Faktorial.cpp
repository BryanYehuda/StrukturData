#include<stdio.h>

int fact(int num)
{
	if (num == 0)
	{
		return 1;
	}
	else
	{
		return num * fact(num - 1);
	}
}

int main()
{
	int x;
	scanf("%d", &x);
	x = fact(x);
	printf("%d\n", x);
	return 0;
}
