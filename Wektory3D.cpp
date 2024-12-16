#include "Wektory3D.h"
#include <iostream>
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

bool Wektory3D::punktPrzeciecia(
    Wektory3D p1, Wektory3D d1,  // Punkt i wektor kierunkowy linii 1
    Wektory3D p2, Wektory3D d2,  // Punkt i wektor kierunkowy linii 2
    Wektory3D& wynik             // Punkt przeciêcia
) {

    Wektory3D deltaP = p2 - p1;

    double A1 = d1.get_x(), B1 = -d2.get_x(), C1 = deltaP.get_x();
    double A2 = d1.get_y(), B2 = -d2.get_y(), C2 = deltaP.get_y();
    double A3 = d1.get_z(), B3 = -d2.get_z(), C3 = deltaP.get_z();

    double det = A1 * B2 - A2 * B1;
    if (fabs(det) < 1e-6) {
        cout << "Linie s¹ równoleg³e lub skoœne - brak przeciêcia." << endl;
        return false;
    }

    double t = (C1 * B2 - C2 * B1) / det;
    double u = (A1 * C2 - A2 * C1) / det;

    double z1_check = p1.get_z() + t * d1.get_z();
    double z2_check = p2.get_z() + u * d2.get_z();
    if (fabs(z1_check - z2_check) > 1e-6) {
        cout << "Brak punktu przeciêcia - linie skoœne." << endl;
        return false;
    }

    wynik = p1 + d1 * t;
    return true;
}
