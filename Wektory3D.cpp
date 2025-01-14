#include "Wektory3D.h"
#include "Wektory2D.h"
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

//bool Wektory3D::punktPrzeciecia(
//    Wektory3D p1, Wektory3D d1,  // Punkt i wektor kierunkowy linii 1
//    Wektory3D p2, Wektory3D d2  // Punkt i wektor kierunkowy linii 2
//) {
//
//    Wektory3D deltaP = p2 - p1;
//    
//    double A1 = d1.get_x(), B1 = -d2.get_x(), C1 = deltaP.get_x();
//    double A2 = d1.get_y(), B2 = -d2.get_y(), C2 = deltaP.get_y();
//    double A3 = d1.get_z(), B3 = -d2.get_z(), C3 = deltaP.get_z();
//
//    double det = A1 * B2 - A2 * B1;
//    if (fabs(det) < 1e-6) {
//        if (fabs(A3 * B2 - A2 * B3) > 1e-6)
//        {
//            return false;
//        }
//    }
//
//    double t = (C1 * B2 - C2 * B1) / det;
//    double u = (A1 * C2 - A2 * C1) / det;
//
//    double z1_check = p1.get_z() + t * d1.get_z();
//    double z2_check = p2.get_z() + u * d2.get_z();
//    if (fabs(z1_check - z2_check) > 1e-6) {
//        return false;
//    }
//
//    this->x = p1.get_x() + t * d1.get_x();
//    this->y = p1.get_y() + t * d1.get_y();
//    this->z = p1.get_z() + t * d1.get_z();
//    return true;
//}

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

bool Wektory3D::przecieciePlaszczyzn(Wektory3D m1, Wektory3D m2, double d1, double d2) {
    /*Macierz temp = Macierz(4, 2);
    Macierz res = Macierz(4, 1);
    temp.set_gut_number(0, 0, m1.get_x());
    temp.set_gut_number(1, 0, m1.get_y());
    temp.set_gut_number(2, 0, m1.get_z());
    temp.set_gut_number(3, 0, d1);
    temp.set_gut_number(0, 1, m2.get_x());
    temp.set_gut_number(1, 1, m2.get_y());
    temp.set_gut_number(2, 1, m2.get_z());
    temp.set_gut_number(3, 1, d2);
    double temp_a = temp.get_number(0,0);
    double temp_b = temp.get_number(0, 1);
    double sign = 0;

    temp_a * temp_b < 0 ? sign = -1 : sign = 1;

    for (int i = 0; i < 4; i++) {
        temp.set_gut_number(i, 0, ((temp.get_number(i, 0) / temp_a) * sign));
    }

    for (int i = 0; i < 4; i++) {
        temp.set_gut_number(i, 1, ((temp.get_number(i, 1) - temp.get_number(i, 0))));
    }

    double z;
    Wektory3D y;
    Wektory3D x;

    y.set_x(temp.get_number(1, 1));
    y.set_y(temp.get_number(2, 1));
    y.set_z(temp.get_number(3, 1));

    x.set_x(temp.get_number(1, 0));
    x.set_y(temp.get_number(2, 0));
    x.set_z(temp.get_number(3, 0));

    cout << "Równanie: x = " << (x.get_z() - (x.get_x() * (y.get_z() - (y.get_y() + y.get_x() * x.get_y()) / y.get_x()))) / y.get_x() << " y = " << (y.get_z() - y.get_y()) / y.get_x() << " z = " << "parametr t";*/

    //Wektory3D p1 = m1.normalizacja();
    //Wektory3D p2 = m2.normalizacja();
    Wektory3D temp, temp1, temp2;
    Wektory3D res;
    double l;
    temp = m1.iloczyn_wektorowy(m2);
    temp1 = temp.iloczyn_wektorowy(m2);
    temp2 = m1.iloczyn_wektorowy(temp);
    l = temp.length();
    temp1 = temp1 * d1;
    temp2 = temp2 * d2;
    res = temp1 + temp2;
    res = res / l;
    cout << "Wektor: ";
    temp.print();
    cout << "Punkt: ";
    res.print();
    return true;
}
