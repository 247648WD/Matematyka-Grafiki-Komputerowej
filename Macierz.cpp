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
	for (int i = 0; i < (size_x * size_y); i++) {
		wyrazy.push_back(is_unit ? (size_x == size_y ? 1 : 0) : 0);
	}
}

Macierz::Macierz(int size_x, int size_y) {
	this->set_size_x(size_x);
	this->set_size_y(size_y);
	double temp;
	for (int i = 0; i < (size_x * size_y); i++) {
		cin >> temp;
		wyrazy.push_back(temp);
	}
}

void Macierz::set_number(int number) {
	wyrazy.push_back(number);
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
	for (int i = 0; i < (size_x * size_y); i++) {
		cout << wyrazy.at(i) << " ";
	}
}