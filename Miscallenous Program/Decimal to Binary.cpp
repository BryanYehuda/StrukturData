#include <iostream>
using namespace std;

void decToBin(int num, int base)
{
	if (num > 0)
	{
		decToBin(num / base, base);
		cout << num % base;
	}
}

int main()
{
	int decimalNum;
	int base;
	base = 2;
	cout << "Enter number in decimal: ";
	cin >> decimalNum;
	cout << endl;
	cout << "Decimal " << decimalNum << " = ";
	decToBin(decimalNum, base);
	cout << " binary" << endl;
	return 0;
}

