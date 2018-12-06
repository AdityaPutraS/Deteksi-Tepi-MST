#include "../include/graf.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool isSameVertice(Vertice V1, Vertice V2)
{
    return Id(V1) == Id(V2) && XVertice(V1) == XVertice(V2) && YVertice(V1) == YVertice(V2);
}

bool isSameEdge(Edge E1, Edge E2)
{
    return (isSameVertice(V1(E1), V1(E2)) && isSameVertice(V2(E1), V2(E2))) || (isSameVertice(V1(E1), V2(E2)) && isSameVertice(V2(E1), V1(E2)));
}

Graf::Graf()
{
    V.clear();
    E.clear();
}

Graf::~Graf()
{
}

//Getter
vector<Vertice> Graf::getVecVertice()
{
    return V;
}
//Mereturn Vector V
vector<Edge> Graf::getVecEdge()
{
    return E;
}
//Mereturn Vector E

void Graf::tambahVertice(Vertice Ve)
{
    if (this->adaVertice(Ve) == -1)
    {
        V.push_back(Ve);
    }
}
//Menambahkan Vertice V kedalam Graf
void Graf::tambahVertice(int id, int X, int Y)
{
    Vertice VTemp = {id, {X,Y}};
    this->tambahVertice(VTemp);
}
//Menambah Vertice dengan komponen {id, {X,Y}} ke Graf
void Graf::hapusVertice(Vertice Ve)
{
    int idxHapus = this->adaVertice(Ve);
    if (idxHapus != -1)
    {
        V.erase(V.begin() + idxHapus);
    }
}
//Menghapus Vertice V dari Graf
void Graf::tambahEdge(Vertice V1, Vertice V2, int W)
{
    if (this->adaVertice(V1) == -1)
    {
        this->tambahVertice(V1);
    }
    if (this->adaVertice(V2) == -1)
    {
        this->tambahVertice(V2);
    }
    if (this->adaEdgeAntara(V1, V2) == -1)
    {
        Edge ETemp;
        V1(ETemp) = V1;
        V2(ETemp) = V2;
        Weight(ETemp) = W;
        E.push_back(ETemp);
    }
}
//Menambah edge baru antara Vertice awal dan akhir dan weight dari edge = W
void Graf::tambahEdge(int id, int X, int Y, Vertice V2, int W)
{
    Vertice VTemp = {id, {X,Y}};
    this->tambahEdge(VTemp,V2,W);
}
//Menabah edge baru antara Vertice berkomponen {id, {X,Y}} dengan V2 dan weight W ke graf
void Graf::tambahEdge(int id1,int X1, int Y1, int id2, int X2, int Y2, int W)
{
    Vertice VTemp = {id2, {X2,Y2}};
    this->tambahEdge(id1, X1, Y1, VTemp,W);
}
//Menabah edge baru antara Vertice berkomponen {id1, {X1,Y1}} dengan vertice {id2, {X2,Y2}}
//dan weight W ke graf
void Graf::hapusEdge(Vertice V1, Vertice V2)
{
    int idxHapus = this->adaEdgeAntara(V1, V2);
    if (idxHapus != -1)
    {
        E.erase(E.begin() + idxHapus);
    }
}
//Menghapus Edge antara V1 dan V2 jika ada didalam Graf,jika tidak maka Graf tetap

void Graf::clearVertice()
{
    V.clear();
}
//Menghapus semua Vertice didalam Graf
void Graf::clearEdge()
{
    E.clear();
}
//Menghapus semua Edge didalam Graf
void Graf::sortEdge()
{
    sort(E.begin(),E.end());
}
//Mengsort semua Edge didalam Graf berdasarkan bobotnya
int Graf::adaVertice(Vertice Ve)
{
    bool ketemu = false;
    int idx = 0;
    vector<Vertice>::iterator iterHapus = V.begin();
    while (iterHapus != V.end() && !ketemu)
    {
        if (isSameVertice(Ve, *iterHapus))
        {
            ketemu = true;
        }
        else
        {
            iterHapus++;
            idx++;
        }
    }
    if (!ketemu)
    {
        idx = -1;
    }
    return idx;
}
//Mengecek apakah ada Vertice V di dalam Graf dan mereturn indexnya jika ada
int Graf::adaEdge(Edge Ed)
{
    bool ketemu = false;
    int idx = 0;
    vector<Edge>::iterator iterHapus = E.begin();
    while (iterHapus != E.end() && !ketemu)
    {
        if (isSameEdge(Ed, *iterHapus))
        {
            ketemu = true;
        }
        else
        {
            iterHapus++;
            idx++;
        }
    }
    if (!ketemu)
    {
        idx = -1;
    }
    return idx;
}
//Mengecek apakah ada Edge E di dalam Graf dan mereturn indexnya jika ada
int Graf::adaEdgeAntara(Vertice V1, Vertice V2)
{
    Edge ETemp = {V1, V2, 0};
    return this->adaEdge(ETemp);
}
//Mengecek apakah ada Edge diantara V1 dan V2 dan mereturn indexnya jika ada

void Graf::printVertice()
{
    vector<Vertice>::iterator iter = V.begin();
    while (iter != V.end())
    {
        cout << "Node : " << Id(*iter) << endl;
        cout << "   Koordinat : (" << XVertice(*iter) << ", " << YVertice(*iter) << ")" << endl;
        iter++;
    }
}
//Mengeprint semua vertice pada Graf ke layar
void Graf::printEdge()
{
    vector<Edge>::iterator iter = E.begin();
    while (iter != E.end())
    {
        cout << "Edge antara " << Id(V1(*iter)) << " dengan " << Id(V2(*iter)) << endl;
        cout << "    Weight : " << Weight(*iter) << endl;
        iter++;
    }
}
//Mengeprint semua edge pada Graf ke layar

Graf MST(Graf G)
{
}
//Membuat minimum spanning tree dari graf G