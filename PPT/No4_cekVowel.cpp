#include <bits/stdc++.h>
using namespace std;
int vowelKu = 0;
bool cek_apaVowel(int n){
    switch(n){
        case 97:
        case 105:
        case 117:
        case 101:
        case 111:
        case 65:
        case 73:
        case 85:
        case 69:
        case 79:
            return true;
                break;
        default:
            return false;
            break;
    }
}
void cariVowel(char *s, int panjang, int temp){
    if(panjang == 0) return;
    if(cek_apaVowel(s[temp-panjang])) vowelKu++;
    cariVowel(s, panjang-1, temp);
}
int main(){
    char input[100];
    cin >> input;
    int n = strlen(input);
    cariVowel(input, n, n);
    cout << vowelKu << endl;
    return 0;
}
