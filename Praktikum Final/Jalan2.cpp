#include<bits/stdc++.h> 
using namespace std; 
typedef long long LL;
typedef  pair<LL, LL> iPair; 
  
struct Graph 
{ 
    LL V, E; 
    vector< pair<LL, iPair> > edges; 
	 
    Graph(LL V, LL E) 
    { 
        this->V = V; 
        this->E = E; 
    } 
   
    void addEdge(LL u, LL v, LL w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
    LL kruskalMST(); 
}; 
   
struct DisjointSets 
{ 
    LL*parent, *rnk; 
    LL n; 
  
    DisjointSets(LL n) 
    { 
        this->n = n; 
        parent = new LL[n+1]; 
        rnk = new LL[n+1]; 
   
        for (LL i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
  
    LL find(LL u) 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    void merge(LL x, LL y) 
    { 
        x = find(x), y = find(y); 
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else 
            parent[x] = y; 
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
  
LL Graph::kruskalMST() 
{ 
    LL mst_wt = 0;  
    sort(edges.begin(), edges.end()); 
    DisjointSets ds(V); 
  
    vector< pair<LL, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        LL u = it->second.first; 
        LL v = it->second.second; 
  
        LL set_u = ds.find(u); 
        LL set_v = ds.find(v); 
  
        if (set_u != set_v) 
        {  
            mst_wt += it->first; 
            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} 
  
int main() 
{ 
    LL V, E;
	cin >> V >> E; 
    Graph g(V, E); 
    LL A,B,C;
    LL total = 0;
  
    for (LL i=1; i<=E; i++)
    {
    	cin >> A >> B >> C;
    	g.addEdge(A,B,C); 
    	total = total+C;
	}
  
    LL mst_wt = total - g.kruskalMST();   
    cout << mst_wt; 
  
    return 0; 
} 
