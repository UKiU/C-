#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//����a ~ b֮���������double���ͣ���������a�ɴb���ɴ�ú��������ã����Բ���
double rnd(double a, double b)
{
	return (b - a) * (rand() * 1.0 / RAND_MAX + rand() * 1.0 / RAND_MAX / RAND_MAX) + a;
}

//����f(x)
double f(double x)
{
	return atan(x) + exp(x);
}

//���������ڽⷽ�̣�����esp��ʾ����
double Solve(double esp)
{
		//����������ɽⷽ�� f(x) = 0 �Ĵ���
	double a = -10.0, b = 0.0;
	for (;;) {
		double x = rnd(a,b);
		if (f(x)<= esp&&f(x)>=(-esp) ) {
			return x;
			break;
		}
		else {
			if (f(x) > esp)b = x;
			if(f(x)<(-esp))a = x;
		}
		continue;
	}
}

int main()
{
	//�����������
	srand(time(0));
	//�ⷽ��
	double x = Solve(1E-8);
	//������
	cout<<"���̵Ľ�Ϊ��" << x << endl;

	return 0;
}