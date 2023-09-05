







int main()
{
	Fraction f1(2, 5);
	Fraction f2 = -4;
	Fraction f3 = 0.5;

	cout << "STEP1" << endl;
	cout << "  f1 = " << f1 << endl;
	cout << "  f2 = " << f2 << endl;
	cout << "  f3 = " << f3 << endl;

	Fraction f4 = f1 + f2 << endl;
	Fraction f5 = f1 - f2 << endl;
	Fraction f6 = f1 * f2 << endl;
	Fraction f7 = f1 / f2 << endl;

	cout << "STEP2" << endl;
	cout << "  f4 = " << f4 << endl;
	cout << "  f5 = " << f5 << endl;
	cout << "  f6 = " << f6 << endl;
	cout << "  f7 = " << f7 << endl;

	Fraction f4 += f1;
	Fraction f5 -= f1;
	Fraction f6 *= f1;
	Fraction f7 /= f1;

	cout << "STEP3" << endl;
	cout << "  f4 = " << f4 << endl;
	cout << "  f5 = " << f5 << endl;
	cout << "  f6 = " << f6 << endl;
	cout << "  f7 = " << f7 << endl;

	f2 = 0.5;
	f4 = 0.4;
	f1 = f2++;
	f3 = ++f4;
	cout << "STEP4" << endl;
	cout << "  f1 = " << f1 << endl;
	cout << "  f2 = " << f2 << endl;
	cout << "  f3 = " << f3 << endl;
	cout << "  f4 = " << f4 << endl;

	cout << "STEP5" << endl;
	cout << "  f4[0] = " << f4[0] << endl;
	cout << "  f4[1] = " << f4[1] << endl;

}