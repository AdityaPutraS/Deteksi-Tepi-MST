#include "include/edgeMST.h"
#include "include/graf.h"
#include <curses.h>

int main()
{
    /*
    VideoCapture cap;
    string namaVideo = "";
    if (!cap.open(0))
    {
        cout << "Gagal buka";
        return 0;
    }
    else
    {
        initscr();
        clear();
        refresh();
        Mat gambar;
        edgeMST eMST;
        eMST.initWindow();
        eMST.initTrackbar();
        for (;;)
        {
            cap >> gambar;
            eMST.setGambar(gambar);
            //eMST.getEdge();
            eMST.displayGambar();
            eMST.displayData();
            if (waitKey(40) == 27)
                break;
            refresh();
        }
        endwin();
    }
    */
    Graf G;
    Vertice t1 = {0, {1,2}};
    Vertice t2 = {1, {2,3}};
    Vertice t3 = {2, {4,1}};
    G.tambahEdge(t1,t2,5);
    G.printVertice();
    G.printEdge();
    cout<<"============================="<<endl;
    G.tambahEdge(t1,t3,10);
    G.printVertice();
    G.printEdge();
    cout<<"============================="<<endl;
    G.tambahEdge(t2,t3,7);
    G.printVertice();
    G.printEdge();
    cout<<"============================="<<endl;
    G.sortEdge();
    G.printVertice();
    G.printEdge();
}