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
}

void Macierz::reset() {
	wyrazy.clear();
	wyrazy.resize(this->size_x * this->size_y, 0);
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
	int max_width = 6;

	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			cout << left << setprecision(2) << setw(max_width) << wyrazy.at(i * size_y + j);
		}
		cout << endl;
	}
	
	/*vector<int> max_len_per_column(size_y, 0);

	for (int j = 0; j < size_y; ++j) {
		int max_len = 0;
		for (int i = 0; i < size_x; ++i) {
			ostringstream strs;
			strs << wyrazy.at(i * size_y + j);
			int num_length = strs.str().size();
			max_len = max(max_len, num_length);
		}
		max_len_per_column[j] = max_len;
	}

	for (int i = 0; i < size_x; ++i) { 
		for (int j = 0; j < size_y; ++j) {
			cout << left << setw(max_len_per_column[j]) << wyrazy.at(i * size_y + j);
			if (j < size_y - 1) 
				cout << " ";
		}
		cout << endl;
	}*/
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
	if (this->size_x == 1) {
		return this->get_number(0, 0);
	}
	else if (this->size_x == 2) {
		return (this->get_number(0, 0) * this->get_number(1, 1)) - (this->get_number(0, 1) * this->get_number(1, 0));
	}

	double wynik = 0;
	for (int x = 0; x < this->size_x; x++) {
		Macierz temp(this->size_x - 1, this->size_y - 1);
		temp.reset();

		for (int i = 1; i < this->size_x; i++) {
			int subj = 0;
			for (int j = 0; j < this->size_y; j++) {
				if (j == x) 
					continue; 
				temp.set_gut_number(i - 1, subj, this->get_number(i, j));
				subj++;
			}
		}
		wynik += pow(-1, x) * this->get_number(0, x) * temp.get_det();
	}

	return wynik;
}

Macierz Macierz::transposition() {
	Macierz wynik(this->size_y, this->size_x);
	wynik.reset();
	
	double temp;

	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			temp = this->get_number(i, j);
			wynik.set_gut_number(j, i, temp);
		}
	}

	return wynik;
}

Macierz Macierz::inverse() {
	if (this->size_x != this->size_y) {
		throw std::invalid_argument("Macierz nie jest kwadratowa!");
	}

	double det = this->get_det();
	if (det == 0) {
		throw std::invalid_argument("Wyznacznik macierzy nie mo¿e byæ równy 0!");
	}

	Macierz cofactorMatrix(this->size_x, this->size_y);
	cofactorMatrix.reset();

	for (int i = 0; i < this->size_x; i++) {
		for (int j = 0; j < this->size_y; j++) {
			Macierz minorMatrix(this->size_x - 1, this->size_y - 1);
			minorMatrix.reset();
			int minorRow = 0;

			for (int mi = 0; mi < this->size_x; mi++) {
				if (mi == i) continue;

				int minorCol = 0;
				for (int mj = 0; mj < this->size_y; mj++) {
					if (mj == j) continue;
					minorMatrix.set_gut_number(minorRow, minorCol, this->get_number(mi, mj));
					minorCol++;
				}
				minorRow++;
			}
			double cofactor = pow(-1, i + j) * minorMatrix.get_det();
			cofactorMatrix.set_gut_number(i, j, cofactor);
		}
	}

	Macierz adjugateMatrix = cofactorMatrix.transposition();
	Macierz inverseMatrix = adjugateMatrix * (1.0 / det);

	return inverseMatrix;
}
