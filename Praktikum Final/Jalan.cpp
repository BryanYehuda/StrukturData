#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Edge
{
 public:
    LL src, dest, weight;
};

class Graph
{
 public:
    LL V, E;
    Edge* edge;
};

Graph* createGraph(LL V, LL E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    return graph;
}

class subset
{
 public:
    LL parent;
    LL rank;
};

LL find(subset subsets[], LL i)
{
    if (subsets[i].parent != i)
        subsets[i].parent
            = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(subset subsets[], LL x, LL y)
{
    LL xroot = find(subsets, x);
    LL yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
 {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph, LL total)
{
    LL V = graph->V;
    Edge result[V];
    LL e = 0;
    LL i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
          myComp);

    subset* subsets = new subset[(V * sizeof(subset))];

    for (LL v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];
        LL x = find(subsets, next_edge.src);
        LL y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    LL minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        minimumCost = minimumCost + result[i].weight;
    }
    cout << total - minimumCost;
}

int main()
{
    LL V; // Number of vertices in graph
    LL E; // Number of edges in graph
    LL A, B, C;
    LL total=0;
    cin>>V>>E;
    Graph* graph = createGraph(V, E);

  	for(LL i=0; i<E; i++)
  	{
   		cin>>A>>B>>C;
   		total = total+C;
   		graph->edge[i].src = A;
     	graph->edge[i].dest = B;
     	graph->edge[i].weight = C;
 	}
    KruskalMST(graph, total);

    return 0;
}
