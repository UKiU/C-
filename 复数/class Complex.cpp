#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
	double R;
	double I;

public:
	double GetR() const { return R; }
	void SetR(double r) { R = r; }
	double GetI() const { return I; }
	void SetI(double i) { I = i; }

	Complex() { R = I = 0; }
	Complex(double r) { R = r; I = 0; }
	Complex(double r, double i) { R = r; I = i; }
	~Complex() {}

	double GetModelSquare() const
	{
		return R * R + I * I;
	}

	double GetModel() const
	{
		return sqrt(GetModelSquare());
	}

	//成员重载
	bool operator == (const Complex& another) const
	{
		return this->R == another.R &&
			this->I == another.I;
	}

	Complex& operator = (const Complex& another)
	{
		this->R = another.R;
		this->I = another.I;

		return *this;
	}

	double operator[](int i) const
	{
		if (i == 0) return R;
		if (i == 1) return I;
		return 0;
	}
	double& operator[](int i)
	{
		if (i == 0) return R;
		if (i == 1) return I;
	}

	Complex& operator++()
	{
		++R;
		return *this;
	}

	Complex operator++(int)
	{
		Complex c = *this;
		++R;
		return c;
	}

	//友元全局重载
	friend Complex operator *(const Complex& c1, const  Complex& c2) //友元
	{
		double R = c1.R * c2.R -
			c1.GetI() * c2.GetI();
		double I = c1.GetR() * c2.GetI() +
			c1.GetI() * c2.GetR();
		return Complex(R, I);
	}

	friend bool operator != (const Complex& c1, const  Complex& c2);
};

//全局重载
bool operator != (const Complex& c1, const Complex& c2)
{
	return c1.R != c2.R || c1.I != c2.I;
}

Complex& operator--(Complex& c)
{
	c.SetR(c.GetR() - 1);
	return c;
}

Complex operator--(Complex& c, int)
{
	Complex oc = c;
	c.SetR(c.GetR() - 1);
	return oc;
}

Complex i(0, 1);

//Complex operator *(Complex& c1, Complex& c2)


Complex operator +(const Complex& c1, const Complex& c2)
{
	double R = c1.GetR() + c2.GetR();
	double I = c1.GetI() + c2.GetI();
	return Complex(R, I);
}
Complex operator -(const Complex& c1, const Complex& c2)
{
	double R = c1.GetR() - c2.GetR();
	double I = c1.GetI() - c2.GetI();
	return Complex(R, I);
}
Complex operator /(Complex& c1, Complex& c2)
{
	double M = c2.GetModelSquare();
	double R = c1.GetR() * c2.GetR() +
		c1.GetI() * c2.GetI();
	double I = c1.GetI() * c2.GetR() -
		c1.GetR() * c2.GetI();
	return Complex(R / M, I / M);
}

//Complex operator ^(Complex c, double k)
//{
//
//}

ostream& operator << (ostream& o, const Complex& c)
{
	if (c.GetR() == 0 && c.GetI() == 0)
		o << "0";
	else if (c[0] == 0)
		o << c[1] << "i";
	else if (c.GetI() == 0)
		o << c.GetR();
	else
		o << c.GetR()
		<< (c.GetI() > 0 ? " + " : " - ")
		<< fabs(c.GetI()) << "i";
	return o;
}



int main()
{
	Complex c1 = 1 + 2 * i;
	Complex c2 = 3 + 4 * i;
	Complex c3 = c1 * c2 - (2 - i);

	(c1 + c2) + c3;

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;

	Complex c4 = --c3;
	cout << "c4 = --c3" << endl;
	cout << "c3 = " << c3 << endl;
	cout << "c4 = " << c4 << endl;
}