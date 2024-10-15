#include "Wektory2D.h"
#include <iostream>
#include <cmath>
#include <string>

#define M_PI 3.14159265358979323846

using namespace std;

Wektory2D::Wektory2D() {}

Wektory2D::Wektory2D(double x, double y) {
    this->x = x;
    this->y = y;
}

Wektory2D::~Wektory2D() {}

double Wektory2D::get_x() {
    return this->x;
}

double Wektory2D::get_y() {
    return this->y;
}

void Wektory2D::set_x(double x) {
    this->x = x;
}

void Wektory2D::set_y(double y) {
    this->y = y;
}

void Wektory2D::print() {
    cout << this->x << ", " << this->y << endl;
}

Wektory2D Wektory2D::operator +(const Wektory2D& v1) {
    return Wektory2D(this->x + v1.x, this->y + v1.y);
}

Wektory2D Wektory2D::operator -(const Wektory2D& v1) {
    return Wektory2D(this->x - v1.x, this->y - v1.y);
}

Wektory2D Wektory2D::operator *(const double s) {
    return Wektory2D(this->x * s, this->y * s);
}

Wektory2D Wektory2D::operator /(const double s) {
    if (s != 0) {
        return Wektory2D(this->x / s, this->y / s);
    }
    else {
        cout << "Dzielnik nie moze byc rowny 0!" << endl;
        return Wektory2D(this->x, this->y);
    }
}

Wektory2D Wektory2D::operator +=(const Wektory2D& v1) {
    return Wektory2D(this->x + v1.x, this->y + v1.y);
}

Wektory2D Wektory2D::operator -=(const Wektory2D& v1) {
    return Wektory2D(this->x - v1.x, this->y - v1.y);
}

Wektory2D Wektory2D::operator *=(const double s) {
    return Wektory2D(this->x * s, this->y * s);
}

Wektory2D Wektory2D::operator /=(const double s) {
    if (s != 0) {
        return Wektory2D(this->x / s, this->y / s);
    }
    else {
        cout << "Dzielnik nie moze byc rowny 0!" << endl;
        return Wektory2D(this->x, this->y);
    }
}

double Wektory2D::length() {
    return sqrt(this->x * this->x + this->y * this->y);
}

Wektory2D Wektory2D::normalizacja() {
    double d = this->length();
    return Wektory2D(this->x / d, this->y / d);
}

double Wektory2D::iloczyn_skalarny(Wektory2D b) {
    return this->x * b.x + this->y * b.y;
}

Wektory3D Wektory2D::iloczyn_wektorowy(Wektory2D a) {
    Wektory3D temp1 = Wektory3D(this->x, this->y, 0);
    Wektory3D temp2 = Wektory3D(a.get_x(), a.get_y(), 0);
    return Wektory3D(temp1.get_y() * temp2.get_z() - temp1.get_z() * temp2.get_y(),
        temp1.get_z() * temp2.get_x() - temp1.get_x() * temp2.get_z(),
        temp1.get_x() * temp2.get_y() - temp1.get_y() * temp2.get_x());
}

// rodzaj: 0 - radiany, 1 - stopnie
double Wektory2D::katy(Wektory2D v, bool rodzaj) {
    double sum = this->iloczyn_skalarny(v);
    double kat = acos(sum / (this->length() * v.length()));
    if (rodzaj == 0)
        return kat;
    else {
        return kat * 180 / M_PI;
    }

}

void Wektory2D::check(Wektory2D v1) {
    if (v1.get_x() == this->x && v1.get_y() == this->y)
        cout << "Wektory2D sa takie same" << endl;
    else
        cout << "Wektory2D sa rozne" << endl;
}
