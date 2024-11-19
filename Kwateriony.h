#pragma once

#ifndef KWATERIONY
#define KWATERIONY
#include "Wektory3D.h"
#include "Macierz.h"

class Kwateriony
{
private:
	Macierz	data;

	void set_data(double r, double i, double j, double k);
	void set_r(double r);
	void set_i(double r);
	void set_j(double r);
	void set_k(double r);
public:
	Kwateriony();
	Kwateriony(double r, double i, double j, double k);
	Kwateriony(Macierz data);
	~Kwateriony();

	double get_r();
	double get_i();
	double get_j();
	double get_k();

	Kwateriony addition(Kwateriony k1);
	Kwateriony substraction(Kwateriony k1);
	Kwateriony multiplication(Kwateriony k1);
	Kwateriony division(Kwateriony k1);

	Kwateriony rotation(double angle, Wektory3D point);

	void print_quaterion();
};

#endif //KWATERIONY

