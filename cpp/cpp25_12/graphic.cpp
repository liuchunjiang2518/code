#include <iostream>
#include <cmath>
#include "graphic.h"
using namespace std;

double Circle::calculateZC()
{
    return 2 * PI * R;
}

// pow会返回浮点型，会导致不准确，仅做参考
bool Circle::isOnCircle(Circle c,Point p)
{
    return std::pow(c.Center.X - p.X,2) + std::pow(c.Center.Y - p.Y,2) == std::pow(c.R,2);
}

void Cube::setL(int s_L)
{
    L = s_L;
}

int Cube::getL()
{
    return L;
}

void Cube::setW(int s_W)
{
    W = s_W;
}

int Cube::getW()
{
    return W;
}

void Cube::setH(int s_H)
{
    H = s_H;
}

int Cube::getH()
{
    return H;
}

int Cube::calculateS()
{
    return (L * W + L * H + W * H) * 2;
}

int Cube::calculateV()
{
    return L * W * H;
}

bool Cube::isSame(Cube c1,Cube c2)
{
    return c1.calculateS() == c2.calculateS() && c1.calculateV() == c2.calculateV();
}