#include "../include/edgeMST.h"
#include <curses.h>

using namespace std;
using namespace cv;

edgeMST::edgeMST()
{
    epsilon = 170;
}

edgeMST::~edgeMST()
{
}

void edgeMST::on_trackbar(int, void *) {}

void edgeMST::initWindow()
{
    namedWindow("Asli");
    namedWindow("Edge");
    namedWindow("Properties");
}

void edgeMST::initTrackbar()
{
    createTrackbar("Epsilon", "Properties", &epsilon, 170, on_trackbar);
}

void edgeMST::setGambar(Mat temp)
{
    temp.copyTo(gambar);
    gambar.copyTo(hasilEdge);
    cvtColor(hasilEdge, hasilEdge, CV_BGR2Lab);
    graf.clear();
    for (int i = 1; i < hasilEdge.rows - 1; i++)
    {
        for (int j = 1; j < (hasilEdge.cols - 1) / 2; j += 2)
        {
            Vec3b pixelTengah = hasilEdge.at<Vec3b>(i, j);
            for (int x = j - 1; x <= j + 1; x++)
            {
                Vec3b pixelTemp = hasilEdge.at<Vec3b>(i, x);
                Vec3b selisih = Vec3b(pixelTemp[0] - pixelTengah[0], pixelTemp[1] - pixelTengah[1], pixelTemp[2] - pixelTengah[2]);
                double dist = sqrtf64(powf64(selisih[0], 2) + powf64(selisih[1], 2) + powf64(selisih[2], 2));
                if (dist > epsilon + 200)
                {
                    circle(gambar, Point(x, i), 1, Scalar(0, 0, 255), 2);
                    
                }
            }
        }
    }
}

void edgeMST::getEdge()
{
    gambar.copyTo(hasilEdge);
}

void edgeMST::displayGambar()
{
    imshow("Asli", gambar);
    imshow("Edge", hasilEdge);
}

void edgeMST::displayData()
{
    clear();
    mvprintw(1, 0, "===================================================");
    mvprintw(2, 15, "Data Edge Detector dengan MST");
    mvprintw(3, 0, "===================================================");

    refresh();
}
