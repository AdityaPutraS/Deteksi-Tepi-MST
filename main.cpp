#include "include/edgeMST.h"
#include "include/graf.h"
#include <curses.h>
#include <iostream>
using namespace std;

int main()
{
    char pilihan;
    cout << "Load gambar dari webcam ? (y/n) ";
    cin >> pilihan;
    if (pilihan == 'y')
    {
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
            edgeMST eMST(160, 200,true,2);
            eMST.initWindow();
            eMST.initTrackbar();
            for (;;)
            {
                cap >> gambar;
                resize(gambar,gambar,Size(360,240));
                eMST.setGambar(gambar);
                eMST.getMST();
                eMST.displayGambar();
                eMST.displayData();
                if (waitKey(40) == 27)
                    break;
                refresh();
            }
            endwin();
        }
    }
    else
    {
        string pathGambar;
        int eps, thrD;
        cout << "Path Gambar : ";
        cin >> pathGambar;
        cout << "Epsilon : ";
        cin >> eps;
        cout << "Thresold Jarak : ";
        cin >> thrD;
        Mat gambar = imread(pathGambar);
        cout << "Pakai resolusi asli ? (y/n) ";
        char resAsli;
        cin >> resAsli;
        if(resAsli == 'n')
        {
            int lebarBaru,tinggiBaru;
            cout << "Masukkan lebar : ";
            cin >> lebarBaru;
            cout << "Masukkan tinggi : ";
            cin >> tinggiBaru;
            resize(gambar,gambar,Size(lebarBaru, tinggiBaru));
        }
        int akurasi;
        cout << "Akurasi (1-10, 1 akurasi maksimal) : ";
        cin >> akurasi;
        edgeMST eMST(eps, thrD,false,akurasi);
        eMST.initWindow();
        cout << "Mengeset gambar" << endl;
        eMST.setGambar(gambar);
        cout << "Mencari MST"<<endl;
        eMST.getMST();
        cout << "Selesai cari MST"<<endl;
        eMST.displayGambar();
        //eMST.displayData();
        waitKey(0);
    }
    return 0;
    
    // int n, V;
    // cout << "Banyak Vertice : ";
    // cin >> V;
    // Graf G(V);
    // cout << "Banyak Edge : ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int id1, id2, w;
    //     cout << "Input id1 id2 weight : ";
    //     cin >> id1 >> id2 >> w;
    //     G.tambahEdge({id1,0,0},{id2,0,0}, w);
    // }
    // G.printVertice();
    // G.printEdge();
    // cout << "=============================" << endl;
    // cout << "MST" << endl;
    // G.MST();
    // G.printVertice();
    // G.printEdge();
}