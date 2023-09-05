//求解多元一次方程

#include <iostream>
#include "A5.h"

using namespace std;

int main()
{
	//利用数组准备数据
	double aArr[] = { 0, 1, -1, 1,1, 2, 3, 0, 2, -1, 1, 1,-3, 0, 2, -1 };
	double bArr[] = { 4, 3, 2, -9 };

	//以下添加代码：完成方程组求解

	//创建4 x 4的系数矩阵A（2分）
	Matrix<double> A(4, 4, aArr, 16);

	//创建4 x 1的常量项矩阵B（2分）
	Matrix<double> B(4, 1, bArr, 4);

	// 判断系数矩阵A是否满秩（3分）
	if (A.Rank() == 4)
	{
		//建立增广矩阵M（4分）
		Matrix<double> M = MergeMatrixHorizontal(A, B);

		//对增广矩阵进行初等行变换（4分）
		M.GaussianElimination();

		//提取增广矩阵的最后1列作为方程组的解矩阵X（4分）
		Matrix<double> X = M.Cut(0, 4, 4, 1);

		//输出方程组的解矩阵X（3分）
		cout << X << endl;

		//计算A*X的结果，输出以验证解是否正确（3分）
		cout << A * X << endl;

	}
	else
		cout << "该方程组解不唯一或无解" << endl;

	system("pause");
	return 0;
}
