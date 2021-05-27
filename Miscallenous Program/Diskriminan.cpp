#include <bits/stdc++.h>
 
using namespace std;
 
void discriminant(int a, int b, int c){
 
    int discriminant = (b*b) - (4*a*c);
    if(discriminant > 0){
        cout<<discriminant<<endl;
             
    }
    else if(discriminant == 0){
        cout<<discriminant<<endl;
        
    }
    else if(discriminant < 0){
        cout<<discriminant<<endl;
             
    }
}
 
// Driver Code
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
 
    // function call to print discriminant
    discriminant(a, b, c);
    return 0;
}
 
