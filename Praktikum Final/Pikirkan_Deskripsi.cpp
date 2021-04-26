#include<bits/stdc++.h> 
#include <deque> 
using namespace std; 
typedef long long LL;

void KMax(LL arr[], LL x, LL y)
{
    deque<LL> De_que; 
    LL i;
    LL ans;
    
    for(i=0; i<y; i++) 
    {
        while(!De_que.empty() && arr[i]>=arr[De_que.back()])  
        {                                                    
            De_que.pop_back(); 
        }
        De_que.push_back(i); 
    }
    
    for(i=y; i<x; i++) 
    {
    	ans = ans + arr[De_que.front()];
        while(!De_que.empty() && De_que.front()<=i-y) 
        {
            De_que.pop_front(); 
        }
        while(!De_que.empty() && arr[i]>=arr[De_que.back()]) 
        {
            De_que.pop_back(); 
        }
        De_que.push_back(i); 
        
    }
    cout<<ans; 
}

int main()
{
    LL x,y;
    cin>>x>>y;
    LL i; 
    LL * arr=new LL [x]; 
    for(i=0;i<x;i++) 
    {
       	cin>>arr[i];
	}
    KMax(arr, x, y); 
    return 0;
}
