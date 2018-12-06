#ifndef GRAF_H
#define GRAF_H

#include <vector>
#include <tuple>

using namespace std;

struct Vertice
{
    int id;
    int idPasangan;
    long key;
    tuple<int, int> koordinat;
    bool operator < (const Vertice& V) const
    {
        return (key < V.key);
    }
};

bool isSameVertice(Vertice V1, Vertice V2);
//Mengecek apakah 2 Vertice sama

//Selektor
#define Id(V) (V).id
#define IdPas(V) (V).idPasangan
#define Key(V) (V).key
#define XVertice(V) get<0>((V).koordinat)
#define YVertice(V) get<1>((V).koordinat)

struct Edge
{
    //Edge tak berarah
    int V1; //id dari Vertice 1
    int V2; //id dari Vertice 2
    long int weight;

    bool operator < (const Edge& E) const
    {
        return (weight < E.weight);
    }
};

bool isSameEdge(Edge E1, Edge E2);
//Mengecek apakah 2 Edge sama

//Selektor
#define V1(E) (E).V1
#define V2(E) (E).V2
#define Weight(E) (E).weight


class Graf
{
private:
    vector<Vertice> V;
    vector<Edge> E;
public:
    Graf();
    ~Graf();


    //Getter
    vector<Vertice> getVecVertice();
    //Mereturn Vector V
    vector<Edge> getVecEdge();
    //Mereturn Vector E
    Vertice getVIdx(int idx);
    //Mereturn Vertice dengan index ke idx
    Edge getMinimumEdge();
    //Mereturn Edge dengan weight maksimum dari graph
    //Untuk kepentingan Minimum Spanning Tree
    //Prekondisi : Vector Edge tidak kosong dan sudah terurut

    void tambahVertice(Vertice Ve);
    //Menambahkan Vertice V kedalam Graf
    void tambahVertice(int id,int key, int X, int Y);
    //Menambah Vertice dengan komponen {id, {X,Y}} ke Graf
    void tambahVertice(int id, int idPasangan, int key, int X, int Y);
    //Menambah Vertice dengan komponen {id,idPasangan, key {X,Y}} ke Graf
    void hapusVertice(Vertice Ve);
    //Menghapus Vertice V dari Graf
    void tambahEdge(Vertice V1, Vertice V2, int W);
    //Menambah edge baru antara Vertice awal dan akhir dan weight dari edge = W
    void tambahEdge(int id1,int X1, int Y1, int id2, int X2, int Y2, int W);
    //Menabah edge baru antara Vertice berkomponen {id1, {X1,Y1}} dengan vertice {id2, {X2,Y2}}
    //dan weight W ke graf
    void hapusEdge(Vertice V1, Vertice V2);
    //Menghapus Edge antara V1 dan V2 jika ada didalam Graf,jika tidak maka Graf tetap

    void clearVertice();
    //Menghapus semua Vertice didalam Graf
    void clearEdge();
    //Menghapus semua Edge didalam Graf
    
    bool isVecEdgeEmpty();
    //Mengecek apakah Vector Edge kosong
    int adaVertice(Vertice Ve);
    //Mengecek apakah ada Vertice Ve di dalam Graf dan mereturn indexnya jika ada
    int adaVertice(int Id);
    //Mengecek apakah ada Vertice dengan id Id di dalam Graf dan mereturn indexnya jika ada
    int adaEdge(Edge Ed);
    //Mengecek apakah ada Edge E di dalam Graf dan mereturn indexnya jika ada
    int adaEdgeAntara(Vertice V1, Vertice V2);
    //Mengecek apakah ada Edge diantara V1 dan V2 dan mereturn indexnya jika ada

    void printVertice();
    //Mengeprint semua vertice pada Graf ke layar
    void printEdge();
    //Mengeprint semua edge pada Graf ke layar

    Graf MST();
    //Membuat MST dari Graf
};

#endif