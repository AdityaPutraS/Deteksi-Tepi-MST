#include "include/edgeMST.h"
#include "include/graf.h"
#include <iostream>
using namespace std;

int main()
{
    string namaGambar;
    int eps, thrD;
    cout << "Nama Gambar (harus ada di folder gambar) : ";
    cin >> namaGambar;
    Mat gambar = imread("gambar/"+namaGambar);
    if(gambar.empty()){
        cout << "Gambar tidak dapat dibuka"<<endl;
    }else{
        char saveGambar;
        cout << "Simpan gambar di file eksternal ? (y/n) ";
        cin >> saveGambar;
        //Input parameter dari user
        cout << "Epsilon : ";
        cin >> eps;
        cout << "Thresold Jarak : ";
        cin >> thrD;
        cout << "Pakai resolusi asli ? (y/n) ";
        char resAsli;
        cin >> resAsli;
        if(resAsli == 'n' || resAsli == 'N')
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
        if(saveGambar == 'Y' || saveGambar == 'y')
        {
            //Save ke file eksternal
            Mat simpan = eMST.getEdge();
            imwrite("hasil/"+namaGambar,simpan);
            cout << "Gambar sudah disave"<<endl;
        }
        waitKey(0);
    }
    return 0;
}