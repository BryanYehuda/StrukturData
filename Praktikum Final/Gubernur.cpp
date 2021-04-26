#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const LL MOD = 1e9 + 7;

vector< pair<LL,LL> > adj[100010];
LL SubTree[100010];
LL ans;
LL n,m;

LL Plus(LL x,LL y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

LL Multiply(LL x,LL y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

void DFS(LL u,LL prev)
{
    SubTree[u] = 1;
    for (auto it : adj[u]) if (it.first != prev)
    {
        DFS(it.first,u);
        SubTree[u] += SubTree[it.first];
        ans = Plus(ans,Multiply(Multiply(SubTree[it.first],n - SubTree[it.first]),it.second));
    }
}

int main()
{
    
    cin >> n >> m;
    for (LL i = 1 ; i <= m ; i++)
    {
        LL a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    DFS(1,-1);
    cout << ans << endl;
    return 0;
}
