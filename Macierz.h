#ifndef MACIERZE_H
#define MACIERZE_H

#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "Wektory3D.h"

class Macierz
{
private:
	int size_x;
	int size_y;
	std::vector <double> wyrazy;
	void set_number(int number);
	void set_size_x(int size_x);
	void set_size_y(int size_y);
public:
	Macierz();
	Macierz(int size_x, int size_y, bool is_unit);
	Macierz(int size_x, int size_y);
	Macierz(int size_x, int size_y, double numbers[]);
	Macierz operator +(const Macierz& m1);
	Macierz operator -(const Macierz& m1);
	Macierz operator *(const double a);
	~Macierz();

	Macierz matrix_multi(Macierz& m1);
	Macierz transposition();
	Macierz inverse();

	void translation(Wektory3D v1);
	void scale(Wektory3D v1);
	void rotate(Wektory3D v1);

	void reset();
	double get_number(int pos_x, int pos_y);
	void set_gut_number(int pos_x, int pos_y, double number);
	int get_size_x();
	int get_size_y();
	double get_det();

	void print_matrix();
};

#endif