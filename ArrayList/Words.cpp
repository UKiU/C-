#include<iostream>
using namespace std;

class Node
{
public:
	virtual double Calculate() = 0;
};

class Operator : public Node
{
public:
	Node* left;
	char opt;
	Node* right;

	Operator(Node* l, char o, Node* r) :
		left(l), opt(o), right(r)
	{

	}

	double Calculate()
	{
		double n1 = left->Calculate();
		double n2 = right->Calculate();

		switch (opt)
		{
		case '+': return n1 + n2;
		case '*': return n1 * n2;
		default:
			cout << "¸ãÉ¶£¿" << endl;
			return 0;
		}
	}
};

class Number : public Node
{
public:
	double num;

	Number(double n) : num(n) {}

	double Calculate() { return num; }
};

void main()
{
	Number* n1 = new Number(3);
	Number* n2 = new Number(3);
	Number* n3 = new Number(3);

	Operator* o2 = new Operator(n2, '*', n3);
	Operator* o1 = new Operator(n1, '+', o2);

	cout << o1->Calculate() << endl;
}