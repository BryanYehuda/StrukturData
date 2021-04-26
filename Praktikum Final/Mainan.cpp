#include<bits/stdc++.h> 
#include<stdio.h> 
using namespace std; 

int largest(int arr[], int B, int C) 
{  
	int i;
    int max = arr[0]; 
    for (i = B; i <= C; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
  
    return max; 
} 
  
int main() 
{ 
	int N, Q;
	int arr[N];
	int A, B, C;
	
	cin >> N >> Q;
	
	for (int x=0; x<N; x++)
	{
		cin >> arr[x];
	}
	
	for (int y=0; y<Q; y++)
	{
		scanf("%d %d %d", &A, &B, &C);
		if(A==1)
		{
			arr[B-1] = C;
		}
		else
		{
			cout << largest(arr, B-1, C-1) << endl; 
		}
	}
	
    return 0;
}
