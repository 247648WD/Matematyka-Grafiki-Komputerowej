#include <iostream>
#include "Wektory.h"

using namespace std;

void checkWektory(Wektory v1, Wektory v2);

int main() {
    Wektory v1 = Wektory(0, 3, 0);
    Wektory v2 = Wektory(5, 5, 0);
    Wektory a_b = Wektory();
    Wektory b_a = Wektory();

    Wektory v3 = Wektory(4, 5, 1);
    Wektory v4 = Wektory(4, 1, 3);
    Wektory v5 = Wektory();

    // zad.2
    cout << "---------- zad.2 ----------" << endl;
    a_b = v1 + v2;
    a_b.print();

    b_a = v2 + v1;
    b_a.print();

    checkWektory(a_b, b_a);

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
    v5.print();

    return 0;
}

void checkWektory(Wektory v1, Wektory v2) {
    if (v1.get_x() == v2.get_x() && 
        v1.get_y() == v2.get_y() && 
        v1.get_z() == v2.get_z())
        cout << "Wektory sa takie same" << endl;
    else
        cout << "Wektory sa rozne" << endl;
}
