#include<iostream>
#include<cmath>
using namespace std;

class Complex 
{
	double R;
	double I;

public:
	double GetR() const { return R; };
	void SetR(double r) { R = r; }
	double GetI() const { return I; };
	void SetI(double i) { I = i; }

	Complex() { R = I = 0; }//构造函数
	Complex(double r) { R = r ; I = 0; }//如果既有重载又有默认值，调用单参时会报错
	Complex(double r, double i) {
		R = r;
		I = i;
	}
	~Complex(){}//析构函数，在对象被销毁时调用，释放内存

	
	double GetModelSquare() const {
		return R * R + I * I;
	}
	double GetModel() const {
		return sqrt(GetModelSquare());
	}
	
	bool operator == (Complex c1 ) const {
		return this->R == c1.R && this->I == c1.I;
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
	Complex& operator--()
	{
		--R;
		return *this;
	}
	Complex operator--(int)
	{
		Complex c = *this;
		--R;
		return c;
	}

	Complex& operator+=(const Complex& c1) {
		this->R += c1.R;
		this->I += c1.I;
		return *this;
	}
	Complex& operator-=(const Complex& c1) {
		this->R -= c1.R;
		this->I -= c1.I;
		return *this;
	}
	Complex& operator *=(const Complex& c1) {
		double r1 = this->R, i1 = this->I;
		this->R = c1.R * r1 - c1.I * i1;
		this->I = c1.I * r1 + c1.R * i1;
		return *this;
	}
	Complex& operator/=(const Complex& c1) {
		double M = c1.GetModel();
		double r1 = c1.GetR() * this->R + c1.GetI() * this->I;
		double i1 = this->I* c1.GetR() - this->R * c1.GetI();
		this->I = i1/M ;
		this->R = r1/M ;
		return *this;
	}

	friend bool operator != (const Complex& c1, const  Complex& c2);
	/*friend Complex operator *(const Complex& c1, const Complex& c2)//友元，使全局函数可以直接访问私有数据 */
};
bool operator != (const Complex& c1, const Complex& c2)
{
	return c1.R != c2.R || c1.I != c2.I;
}


Complex operator *(const Complex& c1,const Complex& c2) {//定义运算符函数
	double R = c1.GetR() * c2.GetR()-c1.GetI()*c2.GetI();
	double I = c1.GetI() * c2.GetR() + c1.GetR() * c2.GetI();
	return Complex(R, I);
}
Complex operator +(const Complex& c1, const Complex& c2) {
	double R = c1.GetR() + c2.GetR() ;
	double I = c1.GetI() + c2.GetI() ;
	return Complex(R, I);
}
Complex operator -(const Complex& c1, const Complex& c2) {
	double R = c1.GetR() - c2.GetR() ;
	double I = c1.GetI() - c2.GetI() ;
	return Complex(R, I);
}
Complex operator /(const Complex& c1, const Complex& c2) {
	double M = c1.GetModel();
	double R = c1.GetR() * c2.GetR() + c1.GetI() * c2.GetI();
	double I = c1.GetI() * c2.GetR() - c1.GetR() * c2.GetI();
	return Complex(R/M, I/M);
}
Complex operator ^(const Complex& c1, int a) {
	double R = c1.GetR();
	double I = c1.GetI();
	for (int j = a; j > 1; j --) {
		double r = R, double i= I;
		R = r * c1.GetR() - i * c1.GetI();
		I = i * c1.GetR() + r * c1.GetI();
	}
	return Complex(R, I);
}

const Complex i(0, 1);

ostream& operator <<(ostream& o, const Complex& c) {
	if (c.GetR() == 0 && c.GetI() == 0)o << "0";
	else if (c.GetR() == 0)o << c.GetI() << "i";
	else if (c.GetI() == 0)o << c.GetR();
	else o << c.GetR() 
		<< (c.GetI() > 0 ? " + " : " - ") 
		<< abs(c.GetI()) << "i";
	return o;
}

bool Iteration(const Complex& c,const Complex& c0) {
	if (c.GetModelSquare() > 100)return 0;
	//if ();   
	Iteration(((c ^ 2 )+ c0),c0);
}

int main() {
	int x = 1;
	int y(2);
	Complex c1;//不写构造时成立;或写缺省构造成立
	Complex c2(1);//写缺省构造时成立，赋给第一个，后一个要缺省；
	Complex c3（1，2）;//写构造时成立
	Complex c4 = 1 + 2 * i;//要定义i，乘法
	
	cout <<  Iteration(c2,1);
}