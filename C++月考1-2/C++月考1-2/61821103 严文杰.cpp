#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//返回a ~ b之间随机数（double类型），理论上a可达，b不可达，该函数可以用，可以不用
double rnd(double a, double b)
{
	return (b - a) * (rand() * 1.0 / RAND_MAX + rand() * 1.0 / RAND_MAX / RAND_MAX) + a;
}

//定义f(x)
double f(double x)
{
	return atan(x) + exp(x);
}

//本函数用于解方程，其中esp表示精度
double Solve(double esp)
{
		//请在这里完成解方程 f(x) = 0 的代码
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
	//打乱随机种子
	srand(time(0));
	//解方程
	double x = Solve(1E-8);
	//输出结果
	cout<<"方程的解为：" << x << endl;

	return 0;
}