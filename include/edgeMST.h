#ifndef EDGEMST
#define EDGEMST

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "graf.h"
#include <vector>
#include <tuple>

using namespace std;
using namespace cv;

#define v2f vector<Vec2f>
#define v6f vector<Vec6f>
#define v3f vector<Vec3f>
#define v4i vector<Vec4i>
#define v4f vector<Vec4f>
#define v2i vector<Vec2i>

class edgeMST
{
  private:
    bool isCurses;
    Mat gambar, gambarLAB, hasilMST;
    Graf G;
    vector<Vertice> VTemp;
    int epsilon, thresoldDistance, akurasi;

  public:
    edgeMST(int eps, int thrD, bool isCurs, int akur);
    ~edgeMST();
    //Init
    void initWindow();
    void initTrackbar();

    static void on_trackbar(int, void *);

    //Setter
    void setGambar(Mat temp);

    void getMST();
    Mat getEdge();

    void displayGambar();
};

#endif