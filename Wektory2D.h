#pragma once


#ifndef WEKTORY2D_H
#define WEKTORY2D_H
#include "Wektory3D.h"

class Wektory2D {
private:
    double x;
    double y;

    void set_x(double x);
    void set_y(double y);
public:
    Wektory2D();
    Wektory2D(double x, double y);
    ~Wektory2D();

    double get_x();
    double get_y();

    void print();

    Wektory2D operator +(const Wektory2D& v1);
    Wektory2D operator -(const Wektory2D& v1);
    Wektory2D operator *(const double s);
    Wektory2D operator /(const double s);
    Wektory2D operator +=(const Wektory2D& v1);
    Wektory2D operator -=(const Wektory2D& v1);
    Wektory2D operator *=(const double s);
    Wektory2D operator /=(const double s);

    double length();
    Wektory2D normalizacja();
    double iloczyn_skalarny(Wektory2D b);
    Wektory3D iloczyn_wektorowy(Wektory2D a);
    double katy(Wektory2D v, bool rodzaj);
    void check(Wektory2D v1);
};

#endif // !WEKTORY2D_H
