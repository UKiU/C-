#include<iostream>
using namespace std;

class complex
{
	double r, i;
public:
	/*complex(double rr, double ii)
	{
		r = rr;
		i = ii;
	}*/
	double getr() { return r; }
	double geti() { return i; }
	complex(double rr=0, double ii=0)
	{
		r = rr;
		i = ii;
	}

	double getmodelsquare()
	{
		return r * r + i * i;
	}

	double getmodel()
	{
		return sqrt(getmodelsquare());
	}
	//complex c1(1); = complex c1 =1;//
};

complex i(0, 1);

complex operator *(complex c1, complex c2)
{
	double r = c1.getr() * c2.getr() - c1.geti() * c2.geti();
	double i = c1.getr() * c2.geti() + c2.getr() * c1.geti();
	return complex(r, i);
}

complex operator +(complex c1, complex c2)
{
	double r = c1.getr() + c2.getr();
	double i = c2.geti() + c1.geti();
	return complex(r, i);
}

complex operator -(complex c1, complex c2)
{
	double r = c1.getr() - c2.getr();
	double i = c2.geti() - c1.geti();
	return complex(r, i);
}

complex operator /(complex c1, complex c2)
{
	double M = c2.getmodelsquare();
	double r = c1.getr() * c2.getr() + c1.geti() * c2.geti();
	double i = c2.getr() * c1.geti() - c1.getr() * c2.geti();
	return complex(r/M, i/M);
}

ostream& operator <<(ostream& o, complex c)
{
	if (c.getr() == 0 && c.geti() == 0) cout << '0' << endl;
	else if (c.getr() == 0) cout << c.geti() << 'i' << endl;
	else if (c.geti() == 0) cout << c.getr() << endl;
	else cout << c.getr() << (c.getr() > 0 ? '+' : '-') << fabs(c.geti()) << 'i' << endl;
	return o;
}

int main() 
{
	int x = 1;
	int y(2);
	complex c1;
	complex c2(1, 2);
	complex c3 = 1 + 2*i;

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	return 0;
}