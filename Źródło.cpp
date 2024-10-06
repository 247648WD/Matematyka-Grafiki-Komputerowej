#include <iostream>

using namespace std;

class Wektory {
	double x;
	double y;
	double z;

	Wektory() {};
	Wektory(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	~Wektory() {};

	Wektory operator ++(Wektory& v1)
	{
		if ((this->x == v.x) && (this->y == v.y))
			return true;
		else
			return false;

	}

};

int main() {

	return 0;
}