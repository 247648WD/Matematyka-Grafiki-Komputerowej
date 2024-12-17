#pragma once

#ifndef WEKTORY3D_H
#define WEKTORY3D_H

class Wektory3D {
private:
    double x;
    double y;
    double z;

    
public:
    Wektory3D();
    Wektory3D(double x, double y, double z);
    ~Wektory3D();

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);

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
    bool punktPrzecieciaProstych(
        Wektory3D p1, Wektory3D d1,  // Punkt i wektor kierunkowy linii 1
        Wektory3D p2, Wektory3D d2   // Punkt i wektor kierunkowy linii 2
    );

    bool punktPrzecieciaZPlaszczyzna(
        Wektory3D p1,        // Punkt na prostej
        Wektory3D d1,        // Wektor kierunkowy prostej
        Wektory3D p2, 
        double D  
    );

    bool punktPrzecieciaOdcinkow(
        Wektory3D p1, Wektory3D p1_prim,  // Punkty linii 1
        Wektory3D p2, Wektory3D p2_prim   // Punkty linii 2
    );

    void punktPrzecieciaSfera(
        Wektory3D p1, Wektory3D p2, // Punkty prostej
        Wektory3D center, double r // Œrodek i promieñ sfery
    );

    bool prostaPrzecieciaPlaszczyzn(
        Wektory3D n1, double D1, // Wektor normalny i sta³a dla pierwszej p³aszczyzny
        Wektory3D n2, double D2, // Wektor normalny i sta³a dla drugiej p³aszczyzny
        Wektory3D punkt,        // Punkt na przeciêciu (wyjœcie)
        Wektory3D kierunek      // Wektor kierunkowy prostej (wyjœcie)
    );
};

#endif // !WEKTORY3D_H