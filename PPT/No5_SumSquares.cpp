#include <bits/stdc++.h>
using namespace std;

int sumSquares(int num){
    if(num==0) return 0;
        else
        return (pow(num,2) + sumSquares(num-1));
}

int main(){
    int n;
    cin >> n;
    
    int hasil = sumSquares(n);
    cout << hasil << endl;
    
    return 0;
}