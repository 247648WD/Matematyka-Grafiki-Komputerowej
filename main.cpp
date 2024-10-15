#include <iostream>
#include "Wektory3D.h"
#include "Wektory2D.h"

using namespace std;

int main() {
    Wektory3D v1 = Wektory3D(0, 3, 0);
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
    v5.print();

    Wektory2D a2d = Wektory2D(1, 2);
    Wektory2D b2d = Wektory2D(4, -1);
    Wektory3D c3d = Wektory3D();
    a2d.print();
    c3d = a2d.iloczyn_wektorowy(b2d);
    c3d.print();
    return 0;
}
