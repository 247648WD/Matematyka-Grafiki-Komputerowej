#include <iostream>
#include <fstream>
#include "Wektory3D.h"
#include "Wektory2D.h"
#include "Macierz.h"
#include "Kwateriony.h"

#define M_PI 3.14159265358979323846 

using namespace std;

int main() {
    ////zad 1
    //Wektory3D v1 = Wektory3D(-2, 4, 0);
    //Wektory3D t1 = Wektory3D(3, 1, 5);

    //Wektory3D v2 = Wektory3D(-2, 4, 0);
    //Wektory3D t2 = Wektory3D(1, -5, 3);
    //Wektory3D punkt;
    //if (punkt.punktPrzeciecia(v1, t1, v2, t2)) {
    //    cout << "Punkt przeciecia: ";
    //    punkt.print();
    //}
    //else {
    //    cout << "Linie sie nie przecinaja." << endl;
    //}

    //zad 1
    Wektory3D v1 = Wektory3D(-2, 4, 0);
    Wektory3D t1 = Wektory3D(3, 1, 5);

    Wektory3D v2 = Wektory3D(-2, 4, 0);
    Wektory3D t2 = Wektory3D(1, -5, 3);
    Wektory3D punkt;
    if (punkt.punktPrzecieciaProstych(v1, t1, v2, t2)) {
        cout << "Punkt przeciecia: ";
        punkt.print();
    }
    

    //zad 2
    cout << endl;
    cout << "Kat miedzy prostymi w radianach: " << t1.katy(t2, 0) << endl;
    cout << "Kat miedzy prostymi w stopniach: " << t1.katy(t2, 1) << endl;
    
    //zad 3
    cout << endl;
    Wektory3D v3 = Wektory3D(-2, 2, -1);
    Wektory3D d = Wektory3D(3, -1, 2);
    Wektory3D n = Wektory3D(2, 3, 3);
    Wektory3D punkt2;
    if (punkt2.punktPrzecieciaZPlaszczyzna(v3, d, n, -8)) {
        cout << "Punkt przeciecia: ";
        punkt2.print();
    }
    else {
        cout << "Linie sie nie przecinaja." << endl;
    }

    //zad 4
    cout << endl;
    cout << "Kat miedzy prosta a plaszczyzna w radianach: " << 1 - d.katy(n, 0) << endl;
    cout << "Kat miedzy prosta a plaszczyzna w stopniach: " << 90 - d.katy(n, 1) << endl;

    //zad 5
    cout << endl;
    Wektory3D p1 = Wektory3D(2, -1, 1);
    Wektory3D p2 = Wektory3D(4, 3, 1);
    double d1 = -8;
    double d2 = 14;
    Wektory3D zad5;
    zad5.przecieciePlaszczyzn(p1, p2, d1, d2);
    cout << endl;
    //punkt4.print();


    //zad 6
    Wektory3D tempa, tempb;
    double kat6;
    tempa = p1.normalizacja();
    tempb = p2.normalizacja();
    kat6 = tempa.katy(tempb, true);
    cout << "Kat miedzy plaszczyznami: " << kat6 << endl;

    //zad 7
    cout << endl;
    Wektory3D A = Wektory3D(5, 5, 4);
    Wektory3D A_p = Wektory3D(10, 10, 6);

    Wektory3D B = Wektory3D(5, 5, 5);
    Wektory3D B_p = Wektory3D(10, 10, 3);

    Wektory3D punkt3;
    if (punkt3.punktPrzecieciaOdcinkow(A, A_p, B, B_p)) {
        cout << "Punkt przeciecia: ";
        punkt3.print();
    }


    
    /*Wektory3D test = A_temp.iloczyn_wektorowy(B_temp);
    test.print();

    test = A_temp.iloczyn_wektorowy(test);
    test.print();

    double T = A.iloczyn_skalarny(test);
    cout << T << endl;

    double X = B.iloczyn_skalarny(test);
    cout << X << endl;
    double wynik = B_temp.iloczyn_skalarny(test);
    cout << wynik << endl;

    double end = (T - X) / wynik;
    cout << end << endl;*/
    

    /*Wektory3D v1 = Wektory3D(0, 3, 0);
    Wektory3D v2 = Wektory3D(5, 5, 0);
    Wektory3D a_b = Wektory3D();
    Wektory3D b_a = Wektory3D();

    Wektory3D v3 = Wektory3D(4, 5, 1);
    Wektory3D v4 = Wektory3D(4, 1, 3);
    Wektory3D v5 = Wektory3D();

    // zad.2
    cout << "---------- zad.2 ----------" << endl;
    a_b = v1 + v2;
    a_b.print();

    b_a = v2 + v1;
    b_a.print();

    a_b.check(b_a);

    // zad.3
    cout << endl << "---------- zad.3 ----------" << endl;
    cout << "Kat w radianach: " << v1.katy(v2, 0) << endl;
    cout << "Kat w stopniach: " << v1.katy(v2, 1) << endl;

    // zad.4
    cout << endl << "---------- zad.4 ----------" << endl;
    v5 = v4.iloczyn_wektorowy(v3);
    v5.print();

    // zad.5
    cout << endl << "---------- zad.5 ----------" << endl;
    v5 = v5.normalizacja();
    cout << v5.length() << endl;
    v5.print();*/

    /*double pls[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double pls1[] = {2,1,4,3,4,1,2,1,1};
    double pls2[] = {1,0,0,1};
    double pls3[] = {-2,3,5,4,9,1,-2,1,6};
    double plsm1[] = {1,2,-3,0,-4,1,3,4,5};
    double plsm2[] = {1,2,6,0,5,7,1,0,7};
    //double plsy[] = { cos(M_PI ), 0,sin(M_PI ),0,0,1,0,0,-sin(M_PI ),0,-cos(M_PI ),0,0,0,0,1};
    double plsy[] = { 0, 0,1,0,0,1,0,0,-1,0,0,0,0,0,0,1 };
    Macierz m0 = Macierz(2, 2, false);
    Macierz m1 = Macierz(2, 2, true);
    Macierz m2 = Macierz(4,3,pls);
    Macierz m3 = Macierz(3, 3, pls1);
    Macierz m4 = Macierz();
    Macierz m5 = Macierz(3, 4, pls);
    Macierz m6 = Macierz(4, 3, pls3);
    Macierz my = Macierz(1, 4, pls2);
    Macierz mry = Macierz(4, 4, plsy);
    Macierz mm1 = Macierz(3, 3, plsm1);
    Macierz mm2 = Macierz(3, 3, plsm2);
    Macierz mm3 = Macierz();
    Macierz rotatex = Macierz();

    cout << "Macierz zerowa:" << endl;
    m0.print_matrix();
    cout << endl << "Macierz jednostkowa:" << endl;
    m1.print_matrix();
    cout << endl << "Macierz:" << endl;
    m2.print_matrix();
    cout << endl << "Dodawanie 3x3 macierzy:" << endl;
    m3.print_matrix();
    cout << endl;
    m4 = m3 + m3;
    m4.print_matrix();
    cout << endl << "Odejmowanie 3x3 macierzy:" << endl;
    m4 = m4 - m3;
    m4.print_matrix();
    cout << endl << "Mno¿enie macierzy przez skalar równy 2:" << endl;
    m4.print_matrix();
    cout << endl;
    m4 = m4 * 2;
    m4.print_matrix();
    cout << endl << "Transpozycja macierzy:" << endl;
    m4 = m2.transposition();
    cout << endl;
    m4.print_matrix();
    cout << endl << "Wyznacznik macierzy:" << endl;
    cout << m3.get_det();
    cout << endl << "Odwracanie macierzy:" << endl;
    m4 = m3.inverse();
    m4.print_matrix();
    cout << endl << "Mno¿enie macierzy:" << endl;
    mm1.print_matrix();
    cout << endl;
    mm2.print_matrix();
    cout << endl;
    mm3 = mm1.matrix_multi(mm2);
    mm3.print_matrix();
    cout << endl << "Odwrotne mno¿enie macierzy daje inny wynik:" << endl;
    mm2.print_matrix();
    cout << endl;
    mm1.print_matrix();
    cout << endl;
    mm3 = mm2.matrix_multi(mm1);
    mm3.print_matrix();
    cout << endl << "Obracanie wektora o 90 stopni wzglêdem osi Y:" << endl;
    my.print_matrix();
    cout << endl;
    mm3 = mm3.rotate_y(-1*M_PI/2);
    mm3 = my.matrix_multi(mm3);
    mm3.print_matrix();*/

    /*Kwateriony q1 = Kwateriony(1, 2, 3, 4);
    Kwateriony q2 = Kwateriony(1, 1, 1, 1);
    Kwateriony res = Kwateriony();
    Kwateriony rot = Kwateriony(0, 1, 0, 0);
    Kwateriony q3 = Kwateriony(0, 3, 3, 3);
    Kwateriony q4 = Kwateriony(0, -1, -1, -1);

    cout << "Dodawanie kwaterionow: " << endl;
    q1.print_quaterion();
    q2.print_quaterion();
    res = q1.addition(q2);
    cout << endl;
    res.print_quaterion();
    cout << endl << "Odejmowanie kwaterionow: " << endl;
    res.print_quaterion();
    q2.print_quaterion();
    res = res.substraction(q2);
    cout << endl;
    res.print_quaterion();
    cout << endl << "Mnozenie kwaterionow: " << endl;
    q1.print_quaterion();
    q2.print_quaterion();
    res = q1.multiplication(q2);
    cout << endl;
    res.print_quaterion();
    cout << endl << "Dzielenie kwaterionow: " << endl;
    q1.print_quaterion();
    q2.print_quaterion();
    res = q1.division(q2);
    cout << endl;
    res.print_quaterion();
    cout << endl << "Obracanie: " << endl;
    q3.print_quaterion();
    Wektory3D a = Wektory3D(q3.get_i(), q3.get_j(), q3.get_k());
    res = rot.rotation(180, a);
    cout << endl;
    res.print_quaterion();

    cout << endl << "Obracanie punktu [-1,-1,-1] o 270 stopni wokol osi X: " << endl;
    q4.print_quaterion();
    Wektory3D b = Wektory3D(q4.get_i(), q4.get_j(), q4.get_k());
    res = rot.rotation(270, b);
    cout << endl;
    res.print_quaterion();

    cout << endl << "Odwrotne mnozenie kwaterionow: " << endl;
    q2.print_quaterion();
    q1.print_quaterion();
    res = q2.multiplication(q1);
    cout << endl;
    res.print_quaterion();*/
    return 0;
}
