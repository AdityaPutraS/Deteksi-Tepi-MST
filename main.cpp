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
    int n;
    cout << "Banyak Edge : ";
    cin >> n;
    for(int i = 0;i < n ;i++)
    {
        int id1,id2,w;
        cout << "Input id1 id2 weight : ";
        cin >> id1 >> id2 >> w;
        G.tambahEdge(id1,0,0,id2,0,0,w);
    }
    G.printVertice();
    G.printEdge();
    cout<<"============================="<<endl;
    cout<<"MST"<<endl;
    Graf MSTGraf = G.MST();
    MSTGraf.printVertice();
    MSTGraf.printEdge();
}