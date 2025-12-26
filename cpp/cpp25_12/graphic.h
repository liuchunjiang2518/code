#pragma once
#include <iostream>
#define PI 3.14
using namespace std;

class Point
{
    public:
        int X;
        int Y;
};

class Circle
{
    public:
        int R;
        Point Center;
        double calculateZC();
        bool isOnCircle(Circle c,Point p);
};

class Cube
{
    public:
        void setL(int s_L);
        int getL();
        void setW(int s_W);
        int getW();
        void setH(int s_H);
        int getH();
        int calculateS();
        int calculateV();
        bool isSame(Cube c1,Cube c2);
    private:
        int L;
        int W;
        int H;
};