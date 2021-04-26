#include <iostream>
#include <list>

using namespace std;

class Point {
    private:
        int x, y;
    public:
        Point();
        Point(int x, int y);
        int getX();
        int getY();
};

Point::Point() {
    this->x = -1;
    this->y = -1;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

class Graph {
    private:
        int V, max_y, max_x;
        list<int> *adj;
        list<Point> *coord;
    public:
        Graph(int v);
        void addVertice(int v, int x, int y);
        void addEdge(int v, int w);
        bool connected(int v, int w);
        void printList();
        void printGraph();
};

Graph::Graph(int V) {
    this->V = V;
    this->max_x = 0;
    this->max_y = 0;
    adj = new list<int>[V];
    coord = new list<Point>[V];
}

void Graph::addVertice(int v, int x, int y) {
    Point p(x, y);
    coord[v].push_back(p);
    this->max_x = x > this->max_x ? x : this->max_x;
    this->max_y = y > this->max_y ? y : this->max_y;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

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

void Graph::printList() { //Fungsi untuk print adjacency list
    list<int>::iterator i;

    for (int v = 0; v < V; v++) {
        cout << v;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            cout << " -> " << *i;
        }
        cout << endl;
    }
}

void Graph::printGraph() { //Fungsi untuk print graph 2D
    int map[max_x+1][max_y+1];
    for (int x = 0; x < max_x + 1; x++) {
        for (int y = 0; y < max_y + 1; y++) {
            map[x][y] = 32;
        }
    }
    
    list<Point>::iterator i;
    list<int>::iterator j;

    for (int v = 0; v < V; v++) {
        i = coord[v].begin();
        int point_x = i->getX();
        int point_y = i->getY();

        map[point_x][point_y] = 48 + v;

        for (int val = v + 1; val < V; val++) {
            if (!connected(v, val)) continue;

            i = coord[v].begin();
            int x1 = i->getX();
            int y1 = i->getY();

            i = coord[val].begin();
            int x2 = i->getX();
            int y2 = i->getY();

            if (x1 == x2) {
                if (y1 < y2) {
                    for (int y = y1 + 1; y < y2; y++) {
                        if (map[x1][y] == 124) map[x1][y] = 43;
                        else map[x1][y] = 45;
                    }
                } else {
                    for (int y = y2 + 1; y < y1; y++) {
                        if (map[x1][y] == 124) map[x1][y] = 43;
                        else map[x1][y] = 45;
                    }
                }
            } else if (y1 == y2) {
                if (x1 < x2) {
                    for (int x = x1 + 1; x < x2; x++) {
                        if (map[x][y1] == 45) map[x][y1] = 43;
                        else map[x][y1] = 124;
                    }
                } else {
                    for (int x = x1 - 1; x > x2; x--) {
                        if (map[x][y1] == 45) map[x][y1] = 43;
                        else map[x][y1] = 124;
                    }
                }
            } else if (x1 < x2 && y1 < y2) {
                for (int x = x1 + 1, y = y1 + 1; x < x2; x++, y++) {
                    if (map[x][y] == 47) map[x][y] = 88;
                    else map[x][y] = 92;
                }
            } else if (x1 < x2 && y1 > y2) {
                for (int x = x1 + 1, y = y1 - 1; x < x2; x++, y--) {
                    if (map[x][y] == 92) map[x][y] = 88;
                    else map[x][y] = 47;
                }
            } else if (x1 > x2 && y1 > y2) {
                for (int x = x1 - 1, y = y1 - 1; x > x2; x--, y--) {
                    if (map[x][y] == 47) map[x][y] = 88;
                    else map[x][y] = 92;
                }
            } else if (x1 > x2 && y1 < y2) {
                for (int x = x1 - 1, y = y1 + 1; x > x2; x--, y++) {
                    if (map[x][y] == 92) map[x][y] = 88;
                    else map[x][y] = 47;
                }
            }
        }
    }
    for (int x = 0; x < max_x + 1; x++) {
        for (int y = 0; y < max_y + 1; y++) {
            cout << (char)map[x][y];
        }
        cout << endl;
    }
}

int main() { //Fungsi Main
    Graph g(9);

    g.addVertice(0, 0, 0);
    g.addVertice(1, 5, 5);
    g.addVertice(2, 10, 0);
    g.addVertice(3, 10, 10);
    g.addVertice(4, 15, 5);
    g.addVertice(5, 15, 15);
    g.addVertice(6, 20, 0);
    g.addVertice(7, 20, 10);
    g.addVertice(8, 25, 5);

    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
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

	cout << "Adjacency Matrix dari Graph adalah: "<< endl;
    g.printList();
    cout << endl << "Gambar dari Graph adalah: "<< endl;
    g.printGraph();

    return 0;
}
