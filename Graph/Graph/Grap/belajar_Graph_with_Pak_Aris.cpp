//#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <algorithm>

// #include <graphics.h> // harus download

using namespace std;

class Graph {
private:
    int V;                   // No. of vertices'
    //string nama;
    //int x,y;

    list<string>* nama;
    list<int>* x;
    list<int>* y;

    list<int>* adj;    // Pointer to an array containing adjacency listsList
public:
    // Constructor
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
        nama = new list<string>[V];
        x = new list<int>[V];
        y = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }


    void tampilList()  {
        list <int> la;
        list<int>::iterator i;

        for (int v = 0; v < V; v++)  {
               printf ("%d ", v);
               /*
               Titik awal adalah v
               Koordinat x = x[v] , Koordinat y = y[v]
               Nama titik nama = nama[v]
               */
               for (i = adj[v].begin(); i != adj[v].end(); ++i)  {
                     printf ("-> %d ", *i);
                     // Titik akhir adalah i
                    }
               printf ("\n");
               /*
               Buatlah garis dari (x,y).awal -> (x,y).akhir
               */
         }
    }

    void isi(int v, string s, int xx, int yy)
    {
        nama[v].push_back(s);
        x[v].push_back(xx);
        y[v].push_back(yy);
    }

};

int main(int argc, char** argv) {

    //MEMBUAT PROGRAM PENDEK MENAMPILKAN
    //LINGKARAN DAN GARIS

    //Nomor HP : 081331550105
    //Terkait aplikasi compiler C yang sudah support grafik

    //Cari compiler yang support library grafik (ex: graphic.h)

   Graph g(6); // Create a graph
   g.isi(5,"F",100,80); //ini memberi koordinat dan nama Vertice
   g.isi(0,"A",365,165);
   g.isi(4,"E",625,100);
   g.isi(2,"C",75,310);
   g.isi(3,"D",400,390);
   g.isi(1,"B",640,320);

   g.addEdge(5, 2);
   g.addEdge(5, 0);
   g.addEdge(4, 0);
   g.addEdge(4, 1);
   g.addEdge(2, 3);
   g.addEdge(3, 1);

   g.tampilList();

   /*

    Menampilkan Vertex di loop mulai dari awal - akhir
    untuk buat lingkaran, titik pusat (x,y) dengan radius R

    Menampilkan sisi/Edge memanfaatkan/modifikasi method tampilList()

    Ambil titik awal, ambil titik akhir
    Dapatkan koordinat titik awal & titik akhir
    Buat Garis dari koordinat titik awal - titik akhir

   */

   /*
// gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file
    int gd = DETECT, gm;

    // initgraph initializes the
    // graphics system by loading a
    // graphics driver from disk
    initgraph(&gd, &gm, "");

    // circle function
    circle(250, 200, 50);

    getch();

    // closegraph function closes the
    // graphics mode and deallocates
    // all memory allocated by
    // graphics system .
    closegraph();
    */
   return 0;
}
