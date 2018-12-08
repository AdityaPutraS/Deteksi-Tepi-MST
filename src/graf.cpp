#include<bits/stdc++.h>
#include "../include/graf.h"

using namespace std;

Graf::Graf() 
{ 
    V.clear();
    E.clear();
} 

Graf::Graf(int ukuran) 
{ 
    this->banyakVertice = ukuran; 
    V.clear();
    E.clear();
    V.resize(ukuran,{-1,-1});
} 
  
Graf::~Graf(){}

void Graf::printEdge()
{
    for(Edge ETemp : E)
    {
        cout << "Ada Edge antara "<<get(0,ETemp)<<" dan "<<get(1,ETemp)<<" dengan bobot "<<get(2,ETemp)<<endl;
    }
}

int Graf::getBanyakEdge()
{
    return E.size();
}
int Graf::getBanyakVertice()
{
    return V.size();
}

Edge Graf::getEdge(int idx)
{
    return E[idx];
}
Titik Graf::getTitik(int idx)
{
    return V[idx];
}

void Graf::printVertice()
{
    for(int i = 0; i < banyakVertice; i++)
    {
        cout << "Vertice "<<i<<" dengan posisi : ("<<get(0,V[i])<<", "<<get(1,V[i])<<")"<<endl;
    }
}

void Graf::tambahEdge(Vertice V1, Vertice V2, int W) 
{ 
    V[V1.id] = Titik(V1.XPos,V1.YPos);
    V[V2.id] = Titik(V2.XPos,V2.YPos);
    E.push_back({V1.id,V2.id,W});
} 

bool CustomSort(Edge E1, Edge E2)
{
    return get(2,E1) < get(2,E2);
}

void Graf::MST()
{
    DSU d(this->banyakVertice);
    sort(E.begin(),E.end(),CustomSort);
    vector<Edge> EHasil;
    EHasil.resize(banyakVertice-1);
    int idx = 0;
    for(Edge ETemp : E)
    {
        int id1 = get(0,ETemp);
        int id2 = get(1,ETemp);
        if(d.unite(id1,id2))
        {
            EHasil[idx] = ETemp;
            idx++;
        }
    }
    E.swap(EHasil);
}
