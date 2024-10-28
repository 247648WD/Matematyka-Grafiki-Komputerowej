#include <iostream>
#include "Wektory3D.h"
#include "Wektory2D.h"
#include "Macierz.h"

using namespace std;

int main() {
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
    double pls[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double pls1[] = { 1,0,0,0,8,0,0,0,9};
    Macierz m1 = Macierz(2, 2, true);
    Macierz m2 = Macierz(4,3,pls);
    Macierz m3 = Macierz(3, 3, pls1);
    Macierz m4 = Macierz();

    m1.print_matrix();
    cout << endl << endl;
    m2.print_matrix();
    /*cout << endl << endl;
    cout << endl;
    cout << m2.get_number(0, 2);
    cout << endl;
    m2.set_gut_number(0, 2, 15);
    cout << m2.get_number(0, 0);
    cout << endl;
    cout << endl;
    cout << endl;
    m2.print_matrix();*/
    /*m4 = m3.matrix_multi(m2);
    m4.print_matrix();
    cout << m2.get_number(0, 0);*/
    m4 = m2.transposition();
    cout << endl << endl;
    m4.print_matrix();
    double det = 0;
    cout << endl << m3.get_det();

    return 0;
}
