#include <iostream>
#include <string> 
#include <cmath>

using namespace std;

class Wektory {
private:
	double x;
	double y;
	double z;

	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}
	void set_z(double z) {
		this->z = z;
	}
public:
	Wektory() {};
	Wektory(double x, double y, double z) {
		this->x = x;	
		this->y = y;
		this->z = z;
	}
	
	~Wektory() {};

	double get_x() {
		return this->x;
	}
	double get_y() {
		return this->y;
	}
	double get_z() {
		return this->z;
	}

	void print() {
		string str1 = to_string(this->x);
		string str2 = to_string(this->y);
		string str3 = to_string(this->z);
		cout << str1 + " " + str2 + " " + str3 << endl;
	}

	Wektory operator +(const Wektory& v1)
	{
		return Wektory(this->x + v1.x, this->y + v1.y, this->z + v1.z);
	}

	Wektory operator -(const Wektory& v1)
	{
		return Wektory(this->x - v1.x, this->y - v1.y, this->z - v1.z);
	}

	Wektory operator *(const double s)
	{

		return Wektory(this->x * s, this->y * s, this->z * s);
	}

	Wektory operator /(const double s)
	{
		if (s != 0) {
			return Wektory(this->x / s, this->y / s, this->z / s);
		}
		else {
			cout << "Dzielnik nie mo¿e byæ równy 0!" << endl;
			return Wektory(this->x, this->y, this->z);
		}
	}

	Wektory operator +=(const Wektory& v1)
	{
		return Wektory(this->x + v1.x, this->y + v1.y, this->z + v1.z);
	}

	Wektory operator -=(const Wektory& v1)
	{
		return Wektory(this->x - v1.x, this->y - v1.y, this->z - v1.z);
	}

	Wektory operator *=(const double s)
	{
		return Wektory(this->x * s, this->y * s, this->z * s);
	}

	Wektory operator /=(const double s)
	{
		if (s != 0) {
			return Wektory(this->x / s, this->y / s, this->z / s);
		}
		else {
			cout << "Dzielnik nie mo¿e byæ równy 0!" << endl;
			return Wektory(this->x, this->y, this->z);
		}
	}

	double length() {
		double d;
		d = pow((this->x * this->x) + (this->y * this->y) + (this->z * this->z), 0.5);
		return d;
	}

	Wektory normalizacja() {
		Wektory v = Wektory();
		double d = this->length();
		v.set_x(this->get_x() / d);
		v.set_y(this->get_y() / d);
		v.set_z(this->get_z() / d);
		return v;
	}

	double iloczyn_skalarny(Wektory b) {
		double n;
		n = this->x * b.x + this->y * b.y + this->z * b.z;
		return n;
	}

	Wektory iloczyn_wektorowy(Wektory a) {
		return Wektory(this->y * a.z - this->z * a.y,
					   this->z * a.x - this->x * a.z,
					   this->x * a.y - this->y * a.x);
	}

	double katy(Wektory v) {
		double sum = this->iloczyn_skalarny(v);
		double katy = acos(sum / (this->length() * v.length()));
		return katy;
	}

};

int main() {
	Wektory v1 = Wektory(0, 3, 0);
	Wektory v2 = Wektory(5, 5, 0);
	Wektory a_b = Wektory();
	Wektory b_a = Wektory();

	Wektory v3 = Wektory(4, 5, 1);
	Wektory v4 = Wektory(4, 1, 3);
	Wektory v5 = Wektory();

	//Wektory v3 = Wektory();

	/*double a = 2;
	double b = 0;
	v3 = v1 - v2;
	v3.print();
	v3 = v3 * 5;
	v3.print();
	v3 = v3 /= a;
	v3.print();
	v3 = v3 /= b;
	v3.print();
	cout << v3.length() << endl;
	v3 = v3.normalizacja();
	cout << v3.length() << endl;
	v1.iloczyn_skalarny(v2);
	v1 = v1.iloczyn_wektorowy(v2);
	v1.print();*/

	//zad.2
	a_b = v1 + v2;
	a_b.print();

	b_a = v2 + v2;
	b_a.print();

	if (a_b.get_x() == b_a.get_x() & a_b.get_y() == b_a.get_y() & a_b.get_z() == b_a.get_z())
		cout << "Wektory sa takie same" << endl;
	else
		cout << "Wektory sa rozne" << endl;

	//zad.3
	cout << v1.katy(v2) << endl;

	//zad.4
	v5 = v4.iloczyn_wektorowy(v3);
	v5.print();
	
	//zad.5
	v5 = v5.normalizacja();
	v5.print();
	//delete &v1, &v2;
	return 0;
}