#pragma once

#ifndef WEKTORY3D_H
#define WEKTORY3D_H

class Wektory3D {
private:
    double x;
    double y;
    double z;

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);
public:
    Wektory3D();
    Wektory3D(double x, double y, double z);
    ~Wektory3D();

    double get_x();
    double get_y();
    double get_z();

    void print();

    Wektory3D operator +(const Wektory3D& v1);
    Wektory3D operator -(const Wektory3D& v1);
    Wektory3D operator *(const double s);
    Wektory3D operator /(const double s);
    Wektory3D operator +=(const Wektory3D& v1);
    Wektory3D operator -=(const Wektory3D& v1);
    Wektory3D operator *=(const double s);
    Wektory3D operator /=(const double s);

    double length();
    Wektory3D normalizacja();
    double iloczyn_skalarny(Wektory3D b);
    Wektory3D iloczyn_wektorowy(Wektory3D a);
    double katy(Wektory3D v, bool rodzaj);
    void check(Wektory3D v1);
};

#endif // !WEKTORY3D_H