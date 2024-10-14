#include "Wektory.h"
#include <iostream>
#include <cmath>
#include <string>

#define M_PI 3.14159265358979323846

using namespace std;

Wektory::Wektory() {}

Wektory::Wektory(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Wektory::~Wektory() {}

double Wektory::get_x() {
    return this->x;
}

double Wektory::get_y() {
    return this->y;
}

double Wektory::get_z() {
    return this->z;
}

void Wektory::set_x(double x) {
    this->x = x;
}

void Wektory::set_y(double y) {
    this->y = y;
}

void Wektory::set_z(double z) {
    this->z = z;
}

void Wektory::print() {
    cout << this->x << ", " << this->y << ", " << this->z << endl;
}

Wektory Wektory::operator +(const Wektory& v1) {
    return Wektory(this->x + v1.x, this->y + v1.y, this->z + v1.z);
}

Wektory Wektory::operator -(const Wektory& v1) {
    return Wektory(this->x - v1.x, this->y - v1.y, this->z - v1.z);
}

Wektory Wektory::operator *(const double s) {
    return Wektory(this->x * s, this->y * s, this->z * s);
}

Wektory Wektory::operator /(const double s) {
    if (s != 0) {
        return Wektory(this->x / s, this->y / s, this->z / s);
    }
    else {
        cout << "Dzielnik nie moze byc rowny 0!" << endl;
        return Wektory(this->x, this->y, this->z);
    }
}

Wektory Wektory::operator +=(const Wektory& v1) {
    return Wektory(this->x + v1.x, this->y + v1.y, this->z + v1.z);
}

Wektory Wektory::operator -=(const Wektory& v1) {
    return Wektory(this->x - v1.x, this->y - v1.y, this->z - v1.z);
}

Wektory Wektory::operator *=(const double s) {
    return Wektory(this->x * s, this->y * s, this->z * s);
}

Wektory Wektory::operator /=(const double s) {
    if (s != 0) {
        return Wektory(this->x / s, this->y / s, this->z / s);
    }
    else {
        cout << "Dzielnik nie moze byc rowny 0!" << endl;
        return Wektory(this->x, this->y, this->z);
    }
}

double Wektory::length() {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Wektory Wektory::normalizacja() {
    double d = this->length();
    return Wektory(this->x / d, this->y / d, this->z / d);
}

double Wektory::iloczyn_skalarny(Wektory b) {
    return this->x * b.x + this->y * b.y + this->z * b.z;
}

Wektory Wektory::iloczyn_wektorowy(Wektory a) {
    return Wektory(this->y * a.z - this->z * a.y,
        this->z * a.x - this->x * a.z,
        this->x * a.y - this->y * a.x);
}

// rodzaj: 0 - radiany, 1 - stopnie
double Wektory::katy(Wektory v, bool rodzaj) {
    double sum = this->iloczyn_skalarny(v);
    double kat = acos(sum / (this->length() * v.length()));
    if (rodzaj == 0)
        return kat;
    else {
        return kat * 180 / M_PI;
    }
    
}
