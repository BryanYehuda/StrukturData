#include <iostream>
#include <list>
#include <cmath>
#include <graphics.h>
using namespace std;

class Point {
    private:
        int x, y;
        string name;
    public:
        Point();
        Point(int x, int y, string name);
        int getX();
        int getY();
        string getName();
};

//default
Point::Point() {
    this->x = -1;
    this->y = -1;
    this->name = "";
}

//constructor titik
Point::Point(int x, int y, string name) {
    this->x = x;
    this->y = y;
    this->name = name;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

string Point::getName() {
    return name;
}

//class untuk menampung graph
class Graph {
    private:
        int V;
        list<int> *adj; //list hubungan antar titik
        list<Point> *coord; //list koordinat dan nama titik
    public:
        Graph(int v);
        void addVertice(int v, int x, int y, string name);
        void addEdge(int v, int w);
        bool connected(int v, int w);
        void printList();
        void printEdge();
        void printPoint();
        void BFS(int s);
};

//constructor graph
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    coord = new list<Point>[V];
}

//menambahkan titik dan update ukuran matriks
void Graph::addVertice(int v,int x,int y, string name) {
    Point p(x, y, name);
    coord[v].push_back(p);

}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

//mengecek apakah dua titik terhubung
bool Graph::connected(int v, int w) {
    list<int>::iterator j;

    for (j = adj[v].begin(); j != adj[v].end(); j++) {
        if (*j == w) return true;
    }

    for (j = adj[w].begin(); j != adj[w].end(); j++) {
        if (*j == v) return true;
    }

    return false;
}

//print hubungan dari setiap titik
void Graph::printList() {
    list<int>::iterator i;
    for (int v = 0; v < V; v++) {
        cout << coord[v].begin()->getName();
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            cout << " -> " << coord[*i].begin()->getName();
        }
        cout << endl;
    }
}

void Graph::printEdge() {
    list<Point>::iterator i;
	for (int v = 0; v < V; v++) {
	    for (int val = v + 1; val < V; val++) {
	            if (!connected(v, val)) continue;

	            i = coord[v].begin();
	            int x1 = i->getX();
	            int y1 = i->getY();

	            i = coord[val].begin();
	            int x2 = i->getX();
	            int y2 = i->getY();

	            line(x1, y1, x2, y2);
		}
	}
}

void Graph::printPoint() {
    list<Point>::iterator i;
    for (int v = 0; v < V; v++) {
    	i = coord[v].begin();
        int point_x = i->getX();
        int point_y = i->getY();
        string name = i->getName();
        int n = name.length();
        char char_array[n + 1];
        strcpy(char_array, name.c_str());

        outtextxy(point_x, point_y, char_array);
    }
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {
    //membuat objek graph
    Graph g(9);
    int gd = DETECT, gm;

	// initgraph initializes the graphics system
	// by loading a graphics driver from disk
	initwindow(1920,1080);

	// font style
    int font = 8;

    // font direction
    int direction = 0;

    // font size
    int font_size = 1;

    // for setting text style
    settextstyle(font, direction, font_size);
    settextjustify(1, 1);
    //menambahkan titik dengan namanya
    g.addVertice(0, 100, 100, "Teknik Sipil");
    g.addVertice(1, 225, 200, "Arsitektur");
    g.addVertice(2, 100, 300, "Manarul Ilmi");
    g.addVertice(3, 350, 250, "Rektorat");
    g.addVertice(4, 200, 400, "SCC ITS");
    g.addVertice(5, 400, 350, "Plaza DR Angka");
    g.addVertice(6, 100, 550, "Lapangan Basket");
    g.addVertice(7, 300, 550, "Menara Sains");
    g.addVertice(8, 200, 700, "K1 Mart");
    //menambahkan hubungan titik
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(4, 7);
    g.addEdge(5, 3);
    g.addEdge(5, 4);
    g.addEdge(6, 4);
    g.addEdge(7, 8);
    g.addEdge(8, 6);
    //print hubungan dan graph
    g.printList();
    g.printEdge();
    g.printPoint();

    cout << "\n"
         << "Following is Breadth First Search "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    cout << "\n";

    getch();

	// closegraph function closes the graphics
	// mode and deallocates all memory allocated
	// by graphics system .
	closegraph();
    return 0;
}
