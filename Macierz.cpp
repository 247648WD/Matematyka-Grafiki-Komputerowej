#include "Macierz.h"

using namespace std;

Macierz::Macierz() {}

Macierz::Macierz(int size_x, int size_y, double numbers[]) {
	this->set_size_x(size_x);
	this->set_size_y(size_y);
	for (int i = 0; i < (size_x * size_y); i++) {
		wyrazy.push_back(numbers[i]);
	}
}

Macierz::Macierz(int size_x, int size_y, bool is_unit) {
	this->set_size_x(size_x);
	this->set_size_y(size_y);
	for (int i = 0; i < get_size_x(); i++) {
		for (int j = 0; j < get_size_y(); j++) {
			if (is_unit) {
				if (i == j) {
					wyrazy.push_back(1);
				}
				else {
					wyrazy.push_back(0);
				}
			}
			else {
				wyrazy.push_back(0);
			}
		}
	}
}

Macierz::Macierz(int size_x, int size_y) {
	this->set_size_x(size_x);
	this->set_size_y(size_y);
	/*double temp;
	for (int i = 0; i < (size_x * size_y); i++) {
		cin >> temp;
		wyrazy.push_back(temp);
	}*/
}

void Macierz::set_number(int number) {
	wyrazy.push_back(number);
}

double Macierz::get_number(int pos_x, int pos_y) {
	return wyrazy.at(pos_x * get_size_y() + pos_y);
}

void Macierz::set_gut_number(int pos_x, int pos_y, double number) {
	wyrazy.at(pos_x * get_size_y() + pos_y) = number;
}

Macierz::~Macierz() {}

int Macierz::get_size_x() {
	return this->size_x;
}

int Macierz::get_size_y() {
	return this->size_y;
}

void Macierz::set_size_x(int size_x) {
	this->size_x = size_x;
}

void Macierz::set_size_y(int size_y) {
	this->size_y = size_y;
}

void Macierz::print_matrix() {
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			cout << wyrazy.at(i * size_y + j) << " ";
		}
		cout << endl;
	}
}

Macierz Macierz::operator +(const Macierz& m1) {
	
	if (this->size_x != m1.size_x || this->size_y != m1.size_y) {
		throw std::invalid_argument("Macierze nie maja takich samych wymiarow.");
	}

	Macierz wynik(this->size_x, this->size_y);

	for (int i = 0; i < (size_x * size_y); i++) {
		wynik.wyrazy.push_back(this->wyrazy[i] + m1.wyrazy[i]);
	}

	return wynik;
}

Macierz Macierz::operator -(const Macierz& m1) {

	if (this->size_x != m1.size_x || this->size_y != m1.size_y) {
		throw std::invalid_argument("Macierze nie maja takich samych wymiarow.");
	}

	Macierz wynik(this->size_x, this->size_y);

	for (int i = 0; i < (size_x * size_y); i++) {
		wynik.wyrazy.push_back(this->wyrazy[i] - m1.wyrazy[i]);
	}

	return wynik;
}

Macierz Macierz::operator *(const double a) {

	Macierz wynik(this->size_x, this->size_y);

	for (int i = 0; i < (size_x * size_y); i++) {
		wynik.wyrazy.push_back(this->wyrazy[i] * a);
	}

	return wynik;
}

Macierz Macierz::matrix_multi (Macierz& m1) {

	if (this->size_y != m1.size_x) {
		throw std::invalid_argument("Macierze musz¹ mieæ odpowiednie wymiary do mno¿enie.");
	}

	Macierz wynik(this->size_x, m1.size_y);

	for (int i = 0; i < this->size_x; i++) {
		for (int j = 0; j < m1.size_y; j++) {
			double temp = 0;
			for (int k = 0; k < this->size_y; k++) {
				temp += (this->get_number(i, k) * m1.get_number(k, j));
			}
			wynik.wyrazy.push_back(temp);
		}
	}

	return wynik;
}

double Macierz::get_det() {
	if (this->size_x != this->size_y) {
		throw std::invalid_argument("Macierz musi byæ kwadratowa.");
	}
	double wynik = 0;
	for (int i = 0; i < this->size_x - 1; i++) {
		double temp = 1;
		for (int j = 0; j < this->size_x; j++) {
			temp *= this->get_number(j + i, j + i);
		}
		wynik += temp;
	}
	return wynik;
}


Macierz Macierz::transposition() {
	Macierz wynik(this->size_y, this->size_x);
	for (int i = 0; i < (size_x * size_y); i++) {
		wynik.wyrazy.push_back(0);
	}
	
	double temp;

	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			temp = this->get_number(i, j);
			wynik.set_gut_number(j, i, temp);
		}
	}

	return wynik;
}