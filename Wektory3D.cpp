#include "Wektory3D.h"
#include <iostream>
#include "Macierz.h"
#include <cmath>
#include <string>

#define M_PI 3.14159265358979323846

using namespace std;

Wektory3D::Wektory3D() {}

Wektory3D::Wektory3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Wektory3D::~Wektory3D() {}

double Wektory3D::get_x() {
    return this->x;
}

double Wektory3D::get_y() {
    return this->y;
}

double Wektory3D::get_z() {
    return this->z;
}

void Wektory3D::set_x(double x) {
    this->x = x;
}

void Wektory3D::set_y(double y) {
    this->y = y;
}

void Wektory3D::set_z(double z) {
    this->z = z;
}

void Wektory3D::print() {
    cout << this->x << ", " << this->y << ", " << this->z << endl;
}

Wektory3D Wektory3D::operator +(const Wektory3D& v1) {
    return Wektory3D(this->x + v1.x, this->y + v1.y, this->z + v1.z);
}

Wektory3D Wektory3D::operator -(const Wektory3D& v1) {
    return Wektory3D(this->x - v1.x, this->y - v1.y, this->z - v1.z);
}

Wektory3D Wektory3D::operator *(const double s) {
    return Wektory3D(this->x * s, this->y * s, this->z * s);
}

Wektory3D Wektory3D::operator /(const double s) {
    if (s != 0) {
        return Wektory3D(this->x / s, this->y / s, this->z / s);
    }
    else {
        cout << "Dzielnik nie moze byc rowny 0!" << endl;
        return Wektory3D(this->x, this->y, this->z);
    }
}

Wektory3D Wektory3D::operator +=(const Wektory3D& v1) {
    return Wektory3D(this->x + v1.x, this->y + v1.y, this->z + v1.z);
}

Wektory3D Wektory3D::operator -=(const Wektory3D& v1) {
    return Wektory3D(this->x - v1.x, this->y - v1.y, this->z - v1.z);
}

Wektory3D Wektory3D::operator *=(const double s) {
    return Wektory3D(this->x * s, this->y * s, this->z * s);
}

Wektory3D Wektory3D::operator /=(const double s) {
    if (s != 0) {
        return Wektory3D(this->x / s, this->y / s, this->z / s);
    }
    else {
        cout << "Dzielnik nie moze byc rowny 0!" << endl;
        return Wektory3D(this->x, this->y, this->z);
    }
}

double Wektory3D::length() {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Wektory3D Wektory3D::normalizacja() {
    double d = this->length();
    return Wektory3D(this->x / d, this->y / d, this->z / d);
}

double Wektory3D::iloczyn_skalarny(Wektory3D b) {
    return this->x * b.x + this->y * b.y + this->z * b.z;
}

Wektory3D Wektory3D::iloczyn_wektorowy(Wektory3D a) {
    return Wektory3D(this->y * a.z - this->z * a.y,
        this->z * a.x - this->x * a.z,
        this->x * a.y - this->y * a.x);
}

// rodzaj: 0 - radiany, 1 - stopnie
double Wektory3D::katy(Wektory3D v, bool rodzaj) {
    double sum = this->iloczyn_skalarny(v);
    double kat = acos(sum / (this->length() * v.length()));
    if (rodzaj == 0)
        return kat;
    else {
        return kat * 180 / M_PI;
    }
}

void Wektory3D::check(Wektory3D v1) {
    if (v1.get_x() == this->x && v1.get_y() == this->y && v1.get_z() == this->z)
        cout << "Wektory3D sa takie same" << endl;
    else
        cout << "Wektory3D sa rozne" << endl;
}

bool Wektory3D::punktPrzecieciaProstych(
    Wektory3D p1, Wektory3D d1,  // Punkt i wektor kierunkowy linii 1
    Wektory3D p2, Wektory3D d2  // Punkt i wektor kierunkowy linii 2
) {
    // Wektor prostopad³y do obu linii
    Wektory3D prostopadly = d1.iloczyn_wektorowy(d2);
    
    double check1 = prostopadly.iloczyn_skalarny(d1);
    double check2 = prostopadly.iloczyn_skalarny(d2);
    if (check1 != check2)
    {
        cout << "Linie sie nie przecinaja" << endl;
        return false;
    }

    prostopadly = d1.iloczyn_wektorowy(prostopadly);
    double c = p1.iloczyn_skalarny(prostopadly);
    double a = p2.iloczyn_skalarny(prostopadly);
    double b = d2.iloczyn_skalarny(prostopadly);
    double wynik = (a - c) / b;

    this->x = p1.get_x() + wynik * d1.get_x();
    this->y = p1.get_y() + wynik * d1.get_y();
    this->z = p1.get_z() + wynik * d1.get_z();
    return true;
}

bool Wektory3D::punktPrzecieciaZPlaszczyzna(
    Wektory3D p,        // Punkt na prostej
    Wektory3D d,        // Wektor kierunkowy prostej
    Wektory3D n,        // Wektor normalny
    double D
) {
    double denominator = n.get_x() * d.get_x() + n.get_y() * d.get_y() + n.get_z() * d.get_z();

    if (fabs(denominator) < 1e-6) {
        return false;
    }

    double t = -(n.get_x() * p.get_x() + n.get_y() * p.get_y() + n.get_z() * p.get_z() + D) / denominator;

    this->x = p.get_x() + t * d.get_x();
    this->y = p.get_y() + t * d.get_y();
    this->z = p.get_z() + t * d.get_z();

    return true;
}

bool Wektory3D::punktPrzecieciaOdcinkow(
    Wektory3D p1, Wektory3D p1_prim,  // Punkty linii 1
    Wektory3D p2, Wektory3D p2_prim   // Punkty linii 2
) {
    Wektory3D p1_temp = p1_prim - p1;
    Wektory3D p2_temp = p2_prim - p2;

    // Wektor prostopad³y do obu linii
    Wektory3D prostopadly = p1_temp.iloczyn_wektorowy(p2_temp);

    double check1 = prostopadly.iloczyn_skalarny(p1_temp);
    double check2 = prostopadly.iloczyn_skalarny(p2_temp);
    if (check1 != check2)
    {
        cout << "Linie sie nie przecinaja" << endl;
        return false;
    }

    prostopadly = p1_temp.iloczyn_wektorowy(prostopadly);
    double c = p1.iloczyn_skalarny(prostopadly);
    double a = p2.iloczyn_skalarny(prostopadly);
    double b = p2_temp.iloczyn_skalarny(prostopadly);
    double wynik = (c - a) / b;

    this->x = p1.get_x() + wynik * p1_temp.get_x();
    this->y = p1.get_y() + wynik * p1_temp.get_y();
    this->z = p1.get_z() + wynik * p1_temp.get_z();
    return true;
}

