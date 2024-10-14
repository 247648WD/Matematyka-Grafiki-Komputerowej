#pragma once

#ifndef WEKTORY_H
#define WEKTORY_H

class Wektory {
private:
    double x;
    double y;
    double z;

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);
public:
    Wektory();
    Wektory(double x, double y, double z);
    ~Wektory();

    double get_x();
    double get_y();
    double get_z();

    void print();

    Wektory operator +(const Wektory& v1);
    Wektory operator -(const Wektory& v1);
    Wektory operator *(const double s);
    Wektory operator /(const double s);
    Wektory operator +=(const Wektory& v1);
    Wektory operator -=(const Wektory& v1);
    Wektory operator *=(const double s);
    Wektory operator /=(const double s);

    double length();
    Wektory normalizacja();
    double iloczyn_skalarny(Wektory b);
    Wektory iloczyn_wektorowy(Wektory a);
    double katy(Wektory v, bool rodzaj);
};

#endif // !WEKTORY_H