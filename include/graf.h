#ifndef GRAF_H
#define GRAF_H

#include <bits/stdc++.h>
#include "disjointSetUnion.h"
using namespace std;

typedef tuple<long,long> Titik;
typedef tuple<int,int,int> Edge;

#define get(I, Tup) get<I>(Tup)

struct Vertice
{
  int id;
  int XPos;
  int YPos;

  //Operator
  bool operator==(const Vertice& V)
  {
    return this->id==V.id;
  }
  bool operator<(const Vertice& V)
  {
    return this->id < V.id;
  }
};

class Graf
{
  private:
    int banyakVertice;
    vector<Titik> V;
    vector<Edge> E;
  public:
    Graf();
    Graf(int ukuran);
    ~Graf();

    int getBanyakEdge();
    int getBanyakVertice();
    Edge getEdge(int idx);
    Titik getTitik(int idx);

    void printVertice();
    void printEdge();

    void tambahEdge(Vertice V1,Vertice V2, int W);
    //Menambah Edge antara Vertice V1 dan Vertice V2 dengan weight edge = W

    void MST();
    //Membuat MST dari Graf ini dengan Kruskal Algorithm
};

#endif