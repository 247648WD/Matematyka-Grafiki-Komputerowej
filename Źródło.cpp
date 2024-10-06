#include <iostream>
#include <string> 

using namespace std;

class Wektory {
private:
	double x;
	double y;
	double z;
public:
	Wektory() {};
	Wektory(double x, double y, double z) {
		this->x = x;	
		this->y = y;
		this->z = z;
	}
	
	~Wektory() {};

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
		}
	}

};

int main() {
	Wektory v1 = Wektory(1, 2, 3);
	Wektory v2 = Wektory(2, 3, 4);
	Wektory v3 = Wektory();

	double a = 2;
	double b = 0;
	v3 = v1 - v2;
	v3.print();
	v3 = v3 * 5;
	v3.print();
	v3 /= a;
	v3.print();
	v3 /= b;
	v3.print();
		//delete &v1, &v2, &v3;
	return 0;
}