#include<iostream>
using namespace std;

//Space类定义
class Space {
	int Line;                  //直线数
	int Subspace;              //直线分割出的区域数
public:
	Space(int line = 0, int subspace = 0) {
		Line = line;
		Subspace = subspace;
	};     //带默认参数值的构造函数
	~Space() {}
	
	int Max=1;
	int MaxSubspace(int line,int& Max) {
		if (line > 0)MaxSubspace(line - 1,Max);
		Max += line;
		return Max;
	};         //直线最多可分割出的区域数                
	
	bool judge() {
		if (Subspace > MaxSubspace(Line, Max))return 0;
		else return 1;
	};              //判断Space对象设定是否合理
	void Setspace(int line, int subspace) { Line = line; Subspace = subspace; }
	void print() { cout << Line << "条线 " << Subspace << "个区域" << endl; }
};

//补充代码：定义构造函数                            （7分）


//补充代码：基于递推算法计算最多能分割出的子平面数  （12分）


//补充代码：判断Space对象设定是否合理             （6分）
// 如果Subspace > 最大子空间数，说明该对象直线数与分割区域数设置不合理，返回值为0
// 如果Subspace <= 最大子空间数，说明该对象直线数与分割数设置合理，返回值为1

int main()
{

	Space s1;
	cout << "对象s1："; s1.print();
	s1.Setspace(3, 10);
	cout << "s1空间："; s1.print();
	if (!s1.judge()) cout << "对象s1直线数与分割区域数设置不合理";
	else cout << "对象s1直线数与分割的区域数设置合理";
	return 0;
}
