#include<iostream>
using namespace std;

void print(int n)
{
	if(n=0)
	{
		print(n+1);
	}else
	{
		for (int i=1; i<=n; i++)
		{
			cout << "*";
		}
		cout << endl;
		n--;
		print(n);
	}
}

int main()
{
	int n;
	cin >> n;
	print(n);
	return 0;
}
