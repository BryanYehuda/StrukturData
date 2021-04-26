#include <iostream>
#include <cmath>
using namespace std;

void binToDec(int binaryNumber, int& decimal, int& weight)
{
	int bit;
	if (binaryNumber > 0)	
	{
		bit = binaryNumber % 10;
		decimal = decimal + bit * static_cast<int>(pow(2.0, weight));
		binaryNumber = binaryNumber / 10;
		weight++;
		binToDec(binaryNumber, decimal, weight);
	}
}

int main()
{
	int decimalNum;
	int bitWeight;
	int binaryNum;
	decimalNum = 0;
	bitWeight = 0;
	cout << "Enter number in binary: ";
	cin >> binaryNum;
	cout << endl;
	binToDec(binaryNum, decimalNum, bitWeight);
	cout << "Binary " << binaryNum << " = " << decimalNum << " decimal" << endl;
	return 0;
}

