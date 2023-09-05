//����Ԫһ�η���

#include <iostream>
#include "A5.h"

using namespace std;

int main()
{
	//��������׼������
	double aArr[] = { 0, 1, -1, 1,1, 2, 3, 0, 2, -1, 1, 1,-3, 0, 2, -1 };
	double bArr[] = { 4, 3, 2, -9 };

	//������Ӵ��룺��ɷ��������

	//����4 x 4��ϵ������A��2�֣�
	Matrix<double> A(4, 4, aArr, 16);

	//����4 x 1�ĳ��������B��2�֣�
	Matrix<double> B(4, 1, bArr, 4);

	// �ж�ϵ������A�Ƿ����ȣ�3�֣�
	if (A.Rank() == 4)
	{
		//�����������M��4�֣�
		Matrix<double> M = MergeMatrixHorizontal(A, B);

		//�����������г����б任��4�֣�
		M.GaussianElimination();

		//��ȡ�����������1����Ϊ������Ľ����X��4�֣�
		Matrix<double> X = M.Cut(0, 4, 4, 1);

		//���������Ľ����X��3�֣�
		cout << X << endl;

		//����A*X�Ľ�����������֤���Ƿ���ȷ��3�֣�
		cout << A * X << endl;

	}
	else
		cout << "�÷�����ⲻΨһ���޽�" << endl;

	system("pause");
	return 0;
}
