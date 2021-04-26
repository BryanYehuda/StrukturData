#include<iostream>
#include <list>
using namespace std;

class Graph
{
 	int M;
 	list<int> *adj; 
 	
 	public:
 	Graph(int M); 
	void addEdge(int m, int w); 
 	void BFS(int s); 
};

Graph::Graph(int M)
{
 	this->M = M;
 	adj = new list<int>[M];
}

void Graph::addEdge(int m, int w)
{
 	adj[m].push_back(w);
}

void Graph::BFS(int s)
{
 	bool *visited = new bool[M];
 	for(int i = 0; i < M; i++)
  	visited[i] = false;

 	list<int> queue;
 	visited[s] = true;
 	queue.push_back(s);

	list<int>::iterator i;

 	while(!queue.empty())
 	{
	  	s = queue.front();
	  	cout << s << " -> ";
	  	queue.pop_front();

  		for (i = adj[s].begin(); i != adj[s].end(); ++i)
  		{
   			if (!visited[*i])
   			{
    			visited[*i] = true;
    			queue.push_back(*i);
   			}
  		}
 	}
 	cout << "END";
}

int main()
{
 	int M, tc, n;
 	cin >> M;
 	cin >> tc;
 	Graph g(M);
 	while (tc--)
 	{
     	int a,b;
     	cin >> a >> b;
     	g.addEdge(a, b);
 	}
 	cin >> n;
 	g.BFS(n);

 return 0;
}
