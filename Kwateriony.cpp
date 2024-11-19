#include "Kwateriony.h"
#include "cmath"

using namespace std;

#define M_PI 3.14159265358979323846

void Kwateriony::set_data(double r, double i, double j, double k) {
	this->data.set_gut_number(0, 0, r);
	this->data.set_gut_number(1, 0, i);
	this->data.set_gut_number(2, 0, j);
	this->data.set_gut_number(3, 0, k);
}

void Kwateriony::set_r(double r) {
	this->data.set_gut_number(0, 0, r);
}
void Kwateriony::set_i(double i) {
	this->data.set_gut_number(1, 0, i);
}
void Kwateriony::set_j(double j) {
	this->data.set_gut_number(2, 0, j);
}
void Kwateriony::set_k(double k) {
	this->data.set_gut_number(3, 0, k);
}

double Kwateriony::get_r() {
	return this->data.get_number(0, 0);
}
double Kwateriony::get_i() {
	return this->data.get_number(1, 0);
}
double Kwateriony::get_j() {
	return this->data.get_number(2, 0);
}
double Kwateriony::get_k() {
	return this->data.get_number(3, 0);
}

Kwateriony::Kwateriony() {
	this->data = Macierz(4, 1, false);
}
Kwateriony::Kwateriony(double r, double i, double j, double k) {
	this->data = Macierz(4, 1, false);
	set_data(r, i, j, k);
}
Kwateriony::Kwateriony(Macierz data) {
	this->data = Macierz(4, 1, false);
	set_data(data.get_number(0, 0), data.get_number(1, 0), data.get_number(2, 0), data.get_number(3, 0));
}
Kwateriony::~Kwateriony() {}

Kwateriony Kwateriony::addition(Kwateriony k1) {
	Kwateriony res = Kwateriony();
	res.set_data(this->get_r() + k1.get_r(), this->get_i() + k1.get_i(), this->get_j() + k1.get_j(), this->get_k() + k1.get_k());
	return res;
}

Kwateriony Kwateriony::substraction(Kwateriony k1) {
	Kwateriony res = Kwateriony();
	res.set_data(this->get_r() - k1.get_r(), this->get_i() - k1.get_i(), this->get_j() - k1.get_j(), this->get_k() - k1.get_k());
	return res;
}

Kwateriony Kwateriony::multiplication(Kwateriony k1) {
	Kwateriony res = Kwateriony();
	Wektory3D q1 = Wektory3D(this->get_i(), this->get_j(), this->get_k());
	Wektory3D q2 = Wektory3D(k1.get_i(), k1.get_j(), k1.get_k());

	Wektory3D temp = Wektory3D();
	Wektory3D im = Wektory3D();

	double re = (this->get_r() * k1.get_r()) - q1.iloczyn_skalarny(q2);

	temp = q1.iloczyn_wektorowy(q2);

	im.set_x(this->get_r() * q2.get_x() + k1.get_r() * q1.get_x() + temp.get_x());
	im.set_y(this->get_r() * q2.get_y() + k1.get_r() * q1.get_y() + temp.get_y());
	im.set_z(this->get_r() * q2.get_z() + k1.get_r() * q1.get_z() + temp.get_z());

	res.set_data(re, im.get_x(), im.get_y(), im.get_z());
	return res;
}

Kwateriony Kwateriony::division(Kwateriony k1) {
	Kwateriony res = Kwateriony();
	Wektory3D q1 = Wektory3D(this->get_i(), this->get_j(), this->get_k());
	Wektory3D q2 = Wektory3D(k1.get_i(), k1.get_j(), k1.get_k());

	Wektory3D temp = Wektory3D();
	Wektory3D im = Wektory3D();

	temp = q1.iloczyn_wektorowy(q2);
	//temp.print();

	double div = k1.get_r() * k1.get_r() + q2.iloczyn_skalarny(q2);

	if (div == 0) {
		throw std::invalid_argument("Operacja niemozliwa do wykonania (dzielenie przez 0)");
	}

	double re = ((this->get_r() * k1.get_r()) + q1.iloczyn_skalarny(q2)) / div;

	im.set_x((k1.get_r() * q1.get_x() - this->get_r() * q2.get_x() - temp.get_x()) / div);
	im.set_y((k1.get_r() * q1.get_y() - this->get_r() * q2.get_y() - temp.get_y()) / div);
	im.set_z((k1.get_r() * q1.get_z() - this->get_r() * q2.get_z() - temp.get_z()) / div);

	res.set_data(re, im.get_x(), im.get_y(), im.get_z());
	return res;
}

Kwateriony Kwateriony::rotation(double angle, Wektory3D point) {
	Kwateriony res = Kwateriony();
	Kwateriony temp = Kwateriony();
	Wektory3D new_point = Wektory3D(0, 0, 0);

	double radian = (angle / 180) * M_PI;

	double qsin = sin(radian / 2);
	double qcos = cos(radian / 2);

	temp.set_data(0, point.get_x(), point.get_y(), point.get_z());

	double norm = pow((this->get_i() * this->get_i()) + (this->get_j() * this->get_j()) + (this->get_k() * this->get_k()), 0.5);

	Kwateriony q = Kwateriony(qcos, (this->get_i() / norm) * qsin, (this->get_j() / norm) * qsin, (this->get_k() / norm) * qsin);

	Kwateriony rev_q = Kwateriony(qcos, -1 * (this->get_i() / norm) * qsin, -1 * (this->get_j() / norm) * qsin, -1 * (this->get_k() / norm) * qsin);

	res = q.multiplication(temp);
	res = res.multiplication(rev_q);

	return res;
}

void Kwateriony::print_quaterion() {
	cout << "Czesc rzeczywista: " << this->get_r() << " Czesc urojona: " << this->get_i() << "i " << this->get_j() << "j " << this->get_k() << "k " << endl;
}