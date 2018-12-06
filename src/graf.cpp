#include "../include/graf.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool isSameVertice(Vertice V1, Vertice V2)
{
    return Id(V1) == Id(V2);
}

bool isSameEdge(Edge E1, Edge E2)
{
    return (V1(E1) == V1(E2) && V2(E1) == V2(E2)) || (V1(E1) == V2(E2) && V2(E1) == V1(E2));
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
Vertice Graf::getVIdx(int idx)
{
    return V[idx];
}
//Mereturn Vertice dengan index ke idx
Edge Graf::getMinimumEdge()
{
    return E[0];
}
//Mereturn Edge dengan weight maksimum dari graph
//Untuk kepentingan Minimum Spanning Tree
//Prekondisi : Vector Edge tidak kosong dan sudah terurut
///////////////////////////////////////////////////////////
void Graf::tambahVertice(Vertice Ve)
{
    if (this->adaVertice(Ve) == -1)
    {
        V.push_back(Ve);
    }
}
//Menambahkan Vertice V kedalam Graf
void Graf::tambahVertice(int id, int key, int X, int Y)
{
    Vertice VTemp = {id,-1, 999999, {X, Y}};
    this->tambahVertice(VTemp);
}
//Menambah Vertice dengan komponen {id,-1, key {X,Y}} ke Graf
void Graf::tambahVertice(int id, int idPasangan, int key, int X, int Y)
{
    Vertice VTemp = {id,idPasangan, 999999, {X, Y}};
    this->tambahVertice(VTemp);
}
//Menambah Vertice dengan komponen {id,idPasangan, key {X,Y}} ke Graf
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
        V1(ETemp) = Id(V1);
        V2(ETemp) = Id(V2);
        Weight(ETemp) = W;
        E.push_back(ETemp);
    }
}
//Menabah edge baru antara Vertice berkomponen {id, {X,Y}} dengan V2 dan weight W ke graf
void Graf::tambahEdge(int id1, int X1, int Y1, int id2, int X2, int Y2, int W)
{
    Vertice VTemp1 = {id1,-1, 999999, {X1, Y1}};
    Vertice VTemp2 = {id2,-1, 999999, {X2, Y2}};
    this->tambahEdge(VTemp1, VTemp2, W);
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

bool Graf::isVecEdgeEmpty()
{
    return E.empty();
}
//Mengecek apakah Vector Edge kosong
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
int Graf::adaVertice(int Id)
{
    Vertice VTemp = {Id,-1, 0, {0, 0}};
    return adaVertice(VTemp);
}
//Mengecek apakah ada Vertice dengan id Id di dalam Graf dan mereturn indexnya jika ada
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
    Edge ETemp = {Id(V1), Id(V2), 0};
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
        cout << "Edge antara " << V1(*iter) << " dengan " << V2(*iter) << endl;
        cout << "    Weight : " << Weight(*iter) << endl;
        iter++;
    }
}
//Mengeprint semua edge pada Graf ke layar

Graf Graf::MST()
{
    //Algoritma Prim
    //Set Vertice 0 sebagai awal
    Key(*V.begin()) = 0;
    IdPas(*V.begin()) = -1;
    Graf MST;
    int targetJumlahVertices = V.size();
    int currJumlahVertices = 0;
    while (currJumlahVertices != targetJumlahVertices)
    {
        //Ambil Vertices dengan key paling kecil dan tidak ada di MST
        sort(V.begin(),V.end());
        Vertice MinVert = V[0];
        if(IdPas(MinVert) != -1)
        {
            Vertice pasangan = MST.getVIdx(MST.adaVertice(IdPas(MinVert)));
            MST.tambahEdge(pasangan,MinVert,Key(MinVert));
        }else{
            MST.tambahVertice(MinVert);
        }
        //Update key semua Vertices yang bertetanggaan dengan vertices tersebut
        vector<Edge>::iterator iter = E.begin();
        while (iter != E.end())
        {
            if (V1(*iter) == Id(MinVert))
            {
                //Update key V2
                int idxV2 = this->adaVertice(V2(*iter));
                if(Weight(*iter) < Key(V[idxV2]))
                {
                    Key(V[idxV2]) = Weight(*iter);
                    IdPas(V[idxV2]) = Id(MinVert);
                }
            }
            else if (V2(*iter) == Id(MinVert))
            {
                //Update key V1
                int idxV1 = this->adaVertice(V1(*iter));
                if(Weight(*iter) < Key(V[idxV1]))
                {
                    Key(V[idxV1]) = Weight(*iter);
                    IdPas(V[idxV1]) = Id(MinVert);
                }
            }
            iter++;
        }
        //Hapus Vertices tersebut dari Graf awal
        this->hapusVertice(MinVert);
        currJumlahVertices++;
    }
    return MST;
}
//Membuat MST dari Graf