#include "../include/disjointSetUnion.h"
#include <bits/stdc++.h>

using namespace std;

DSU::DSU(int ukuran)
{
    parent.clear();
    rank.clear();
    for (int i = 0; i <= ukuran; i++)
    {
        parent.push_back(i);
        rank.push_back(i);
    }
}

DSU::~DSU() {}

int DSU::getParent(int x)
{
    //Lakukan teknik path compression
    if (parent[x] != x)
    {
        //Rekursif hingga ketemu set paling atas yang parentnya merupakan dirinya sendiri
        parent[x] = getParent(parent[x]);
    }
    return parent[x];
}

bool DSU::unite(int x, int y)
{
    //Cari parent dari x dan y
    x = getParent(x);
    y = getParent(y);
    //Cek apakah mereka berada di set yang sama
    if (x == y)
    {
        return 0;
    }
    else
    {
        //Mereka berdua disjoint
        //Cek ranknya
        if (rank[x] < rank[y])
        {
            rank[y] += rank[x];
            parent[x] = y;
        }
        else
        {
            rank[x] += rank[y];
            parent[y] = x;
        }
        return 1;
    }
}