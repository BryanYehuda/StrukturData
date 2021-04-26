#include<graphics.h>
#include <iostream>
#include <list>
#include <list>
#include <vector>
#include <cmath>
using namespace std;

class Coord{
	private:
		int x;
		int y;
		string name;
	public:
		Coord();
		Coord(int x, int y, string name);
		int getX();
		int getY();
		string getName();
};

//kosong set x dan y -1
Coord::Coord(){
	this->x=-1;
	this->y=-1;
	this->name="";
}

//set object coordinates
Coord::Coord(int x, int y, string name){
	this->x=x;
	this->y=y;
	this->name=name;
}

//get x dan y
int Coord::getX() {
	return x;
}

int Coord::getY() {
	return y;
}
string Coord::getName() {
    return name;
}
//class untuk menampung graph
class Graph{
	private:
		int V; //vertice
		//int max_X,max_Y; //untuk mengetahui ukuran matriks
		list<int> *adj;
		list<Coord> *coord;
	public:
		Graph (int v);
		void addVertice (int v, int x, int y, string name);
		void addEdge (int v, int w);
		bool connected (int v, int w);
		void printList();
		void printEdge();
		//void printGraph();
		void printCoord();
		void BFS(int s, int dest);
};
//constructor
Graph::Graph(int V){
	this->V=V; //set vertice
	//this->max_X=0; //constructor set ke 0
	//this->max_Y=0;
	adj = new list<int>[V]; //sisi=integer
	coord = new list<Coord>[V]; //kordinat
}
//tambah sudut
void Graph::addVertice(int v, int x, int y, string name){
	Coord p(x,y,name); //buat kordinat
	coord[v].push_back(p);
	//this->max_X=x > this->max_X ? x : this->max_X; //cek apakah koordinat lebih besar dari matrix
	//this->max_Y=y > this->max_Y ? y : this->max_Y;
}
//tambah jalan
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	//adj[w].push_back(v);
}
//fungsi bool untuk mengecek apakah terhubung
bool Graph::connected(int v, int w){
	list<int>::iterator j;//iterator

	for (j = adj[v].begin(); j != adj[v].end(); j++) {
        if (*j == w) return true;
    }

    for (j = adj[w].begin(); j != adj[w].end(); j++) {
        if (*j == v) return true;
    }
	//return false jika tidak terhubung
    return false;
}
//print list secara biasa
void Graph::printList(){
	list<int>::iterator i; //iterator
	//loop sampai 9 titik
	for (int v=0; v<V; v++){
		//cout << v;
		cout << coord[v].begin()->getName();
		for (i = adj[v].begin(); i != adj[v].end(); i++){
			cout << " -> " << coord[*i].begin()->getName();
			//cout << "->" << *i;
		}
		cout << endl;
	}
}

void Graph::printEdge() {
    list<Coord>::iterator i;
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
void Graph::printCoord() {
    list<Coord>::iterator i;
    for (int v = 0; v < V; v++) {
    	i = coord[v].begin();
        int point_x = i->getX();
        int point_y = i->getY();
        string name = i->getName();
        int n = name.length();
        char char_array[n + 1];
        strcpy(char_array, name.c_str());

        //print lingkaran dengan pusat sama dengan teks
        //radius 40
        circle(point_x, point_y, 40);
        outtextxy(point_x, point_y, char_array);
    }
}

void Graph::BFS(int s, int dest)
{
    // Menandai sudut yang belum dikunjungi
    bool *visited = new bool[V];
    int *d = new int[V]; //jarak setiap titik
    int *p = new int [V]; //parent
    for(int i = 0; i < V; i++){
        visited[i] = false;
        d[i]= INT_MAX;
        p[i]= -1;
    }
    // queue BFS
    list<int> queue;

    // menandai node sekarang = dikunjungi dan jarak=0
    visited[s] = true;
    d[s]=0;
    queue.push_back(s);

    // iterator 'i' digunakan untuk mendapatkan sudut
    // yang berhubungan
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " "; //print bfs
        queue.pop_front();
        // mendapatkan semua sudut yang berhubungan dengan s
        //jika sebelahnya belum visited, mark sebagai visited
        // dan enqueue
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                d[*i]=d[s]+1; //update jarak
                p[*i]=s; //update parent jadi titik sekarang
                queue.push_back(*i);
                if(*i == dest){
                    vector<int> path; //vector utk menyimpan jalur terpendek
                    int x=dest;
                    path.push_back(x);
                    //get semua parent
                    while(p[x]!=-1){
                        path.push_back(p[x]); //push ke vector
                        x = p[x]; //update parent
                    }
                    //iterator untuk coordinate
                    list<Coord>::iterator it;
                    //jalur terdekat
                    for (int idx=1; idx < (int)path.size(); ++idx){
                        it=coord[path[idx-1]].begin();
                        int x1=it->getX();
                        int y1=it->getY();
                        it=coord[path[idx]].begin();
                        int x2=it->getX();
                        int y2=it->getY();
                        //menggambar garis untuk setiap loop
                        line(x1,y1,x2,y2);
                    }
                }
            }
        }
    }
}

int main() {
    Graph g(9);
    int gd = DETECT, gm;
    //init graphics driver
    //initgraph(&gd, &gm, "");
    initwindow(1280, 720, "");
    // font style
    int font = 8;

    // font direction
    int direction = 0;

    // font size
    int font_size = 1;
    // for setting text style
    settextstyle(font, direction, font_size);
    settextjustify(1, 1);

    g.addVertice(0, 62, 54, "satpam");
    g.addVertice(1, 129+60, 62, "Tek.Lingkungan");
    g.addVertice(2, 217+60, 148, "Tek. Sipil");
    g.addVertice(3, 196+60, 204+60, "Bundaran");
    g.addVertice(4, 275+160, 204+60, "Parkir Arsitek");
    g.addVertice(5, 318+150, 165, "FADP Lama");
    g.addVertice(6, 335+250, 275+60, "Grab");
    g.addVertice(7, 251+120, 369+60, "Bundaran");
    g.addVertice(8, 172+60, 354+60, "Belakang Manarul");



    g.addEdge(0, 1);
    //g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 3);
    g.addEdge(6, 4);
    g.addEdge(6, 7);
    g.addEdge(7, 6);
    g.addEdge(7, 8);
    g.addEdge(8, 3);

     //print hubungan dan graph
    g.printList();
    g.printEdge();
    g.printCoord(); //print string dan lingkaran
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    setcolor(CYAN);
    g.BFS(2,8);
    getch();
    //g.printList();
    //g.printGraph();

    // closegraph function closes the graphics
	// mode and deallocates all memory allocated
	// by graphics system .
	closegraph();
    return 0;
}
