#include<iostream>
using namespace std;

//Space�ඨ��
class Space {
	int Line;                  //ֱ����
	int Subspace;              //ֱ�߷ָ����������
public:
	Space(int line = 0, int subspace = 0) {
		Line = line;
		Subspace = subspace;
	};     //��Ĭ�ϲ���ֵ�Ĺ��캯��
	~Space() {}
	
	int Max=1;
	int MaxSubspace(int line,int& Max) {
		if (line > 0)MaxSubspace(line - 1,Max);
		Max += line;
		return Max;
	};         //ֱ�����ɷָ����������                
	
	bool judge() {
		if (Subspace > MaxSubspace(Line, Max))return 0;
		else return 1;
	};              //�ж�Space�����趨�Ƿ����
	void Setspace(int line, int subspace) { Line = line; Subspace = subspace; }
	void print() { cout << Line << "���� " << Subspace << "������" << endl; }
};

//������룺���幹�캯��                            ��7�֣�


//������룺���ڵ����㷨��������ָܷ������ƽ����  ��12�֣�


//������룺�ж�Space�����趨�Ƿ����             ��6�֣�
// ���Subspace > ����ӿռ�����˵���ö���ֱ������ָ����������ò���������ֵΪ0
// ���Subspace <= ����ӿռ�����˵���ö���ֱ������ָ������ú�������ֵΪ1

int main()
{

	Space s1;
	cout << "����s1��"; s1.print();
	s1.Setspace(3, 10);
	cout << "s1�ռ䣺"; s1.print();
	if (!s1.judge()) cout << "����s1ֱ������ָ����������ò�����";
	else cout << "����s1ֱ������ָ�����������ú���";
	return 0;
}
