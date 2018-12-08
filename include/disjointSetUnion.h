#ifndef DSU_H
#define DSU_H

#include<vector>

class DSU
{
    private:
        std::vector<int> parent, rank;
    public:
        DSU(int ukuran);
        ~DSU();

        int getParent(int x);
        //Melakukan teknik path compression untuk mendapatkan parent dari x

        bool unite(int x, int y);
        //Menggabung 2 set berdasar ranknya jika tidak ada subset diantara mereka
};

#endif