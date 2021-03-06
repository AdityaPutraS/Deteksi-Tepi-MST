#include "../include/edgeMST.h"

using namespace std;
using namespace cv;

edgeMST::edgeMST(int eps, int thrD, bool isCurs, int akur)
{
    this->epsilon = eps;
    this->thresoldDistance = thrD;
    this->isCurses = isCurs;
    this->akurasi = akur;
}

edgeMST::~edgeMST()
{
}

void edgeMST::on_trackbar(int, void *) {}

void edgeMST::initWindow()
{
    namedWindow("Asli");
    namedWindow("MST");
}

double deltaColor(Vec3b C1, Vec3b C2)
{
    double L1 = C1[0]*100/255.0;
    double a1 = C1[1] - 128;
    double b1 = C1[2] - 128;
    double L2 = C2[0]*100/255.0;
    double a2 = C2[1] - 128;
    double b2 = C2[2] - 128;
    return(sqrtf64(powf64(L1-L2,2)+powf64(a1-a2,2)+powf64(b1-b2,2)));
}

void edgeMST::setGambar(Mat temp)
{
    temp.copyTo(gambar);
    gambar.copyTo(gambarLAB);
    gambar.copyTo(hasilMST);
    hasilMST.setTo(Scalar(0, 0, 0));
    cvtColor(gambarLAB, gambarLAB, CV_RGB2Lab);
    int idx = 0;
    for (int i = 1; i < gambarLAB.rows - 1; i += akurasi)
    {
        for (int j = 1; j < (gambarLAB.cols - 1); j += akurasi)
        {
            Vec3b pixelTengah = gambarLAB.at<Vec3b>(i, j);
            //Cek Horizontal
            bool sudahDimasukan = false;
            int x = j-1;
            while(!sudahDimasukan && (x <= j+1))
            {
                Vec3b pixelTemp = gambarLAB.at<Vec3b>(i, x);
                double dist = deltaColor(pixelTengah, pixelTemp);
                if (dist > epsilon)
                {
                    circle(gambar, Point(x, i), 1, Scalar(0, 0, 255), 1);
                    Vertice Ver1 = {idx, j, i};
                    VTemp.push_back(Ver1);
                    sudahDimasukan = true;
                    idx++;
                }
                //lompat ke pixel di kanan dari pixel tengah
                x += 2;
            }
            //Cek Vertikal
            int y = i-1;
            while(!sudahDimasukan && (y <= i+1))
            {
                Vec3b pixelTemp = gambarLAB.at<Vec3b>(y, j);
                double dist = deltaColor(pixelTengah, pixelTemp);
                if (dist > epsilon)
                {
                    circle(gambar, Point(j, y), 1, Scalar(0, 0, 255), 2);
                    Vertice Ver1 = {idx, j, i};
                    VTemp.push_back(Ver1);
                    sudahDimasukan = true;
                    idx++;
                }
                //lompat ke pixel di bawah dari pixel tengah
                y += 2;
            }
        }
    }
    cout << "Ketemu " << VTemp.size() << " Vertices" << endl;
}

void edgeMST::getMST()
{
    int ukuran = VTemp.size();
    G = Graf(ukuran);
    for (int i = 0; i < ukuran; i++)
    {
        for (int j = i + 1; j < ukuran; j++)
        {
            Vertice Ver1 = VTemp[i];
            Vertice Ver2 = VTemp[j];
            int Vx1 = Ver1.XPos, Vy1 = Ver1.YPos;
            int Vx2 = Ver2.XPos, Vy2 = Ver2.YPos;
            int manhattanDistance = abs(Vx1 - Vx2) + abs(Vy1 - Vy2);
            //Assign manhattan distance kedua vertice sebagai weight edge nya jika manhattan distancenya dibawah thresold
            if (manhattanDistance < thresoldDistance)
            {
                G.tambahEdge(Ver1, Ver2, abs(Vx1 - Vx2) + abs(Vy1 - Vy2));
            }
        }
    }
    int banyakEdge = G.getBanyakEdge();
    cout << "Banyak Edge sebelum MST : " << banyakEdge << endl;
    G.MST();
    banyakEdge = G.getBanyakEdge();
    cout << "Banyak Edge setelah MST : " << banyakEdge << endl;
    for (int i = 0; i < banyakEdge; i++)
    {
        Edge ETemp = G.getEdge(i);
        Titik V1 = G.getTitik(get(0, ETemp));
        Titik V2 = G.getTitik(get(1, ETemp));
        int Vx1 = get(0, V1), Vy1 = get(1, V1);
        int Vx2 = get(0, V2), Vy2 = get(1, V2);
        line(hasilMST, Point(Vx1, Vy1), Point(Vx2, Vy2), Scalar(255, 255, 255));
    }
}

Mat edgeMST::getEdge()
{
    return hasilMST;
}

void edgeMST::displayGambar()
{
    imshow("Asli", gambar);
    imshow("MST", hasilMST);
}
