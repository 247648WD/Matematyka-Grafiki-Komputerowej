#ifndef PRZECIECIA_H
#define PRZECIECIA_H

class Przeciêcia
{
private:
	double x_1;
	double x_2;
	double y_1;
	double y_2;
	double z_1;
	double z_2;
	double a_1;
	double a_2;
	double b_1;
	double b_2;
	double c_1;
	double c_2;
	double t;
	double m;

	void set_x_1(double x_1);
	void set_x_2(double x_2);
	void set_y_1(double y_1);
	void set_y_2(double y_2);
	void set_z_1(double z_1);
	void set_z_2(double z_2);
	void set_a_1(double a_1);
	void set_a_2(double a_2);
	void set_b_1(double b_1);
	void set_b_2(double b_2);
	void set_c_1(double c_1);
	void set_c_2(double c_2);
	void set_t(double t);
	void set_m(double m);
public:
	double get_x_1();
	double get_x_2();
	double get_y_1();
	double get_y_2();
	double get_z_1();
	double get_z_2();
	double get_a_1();
	double get_a_2();
	double get_b_1();
	double get_b_2();
	double get_c_1();
	double get_c_2();
	double get_t();
	double get_m();
};

#endif
