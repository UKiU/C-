//���庯��ģ�壬�ҳ�һ�����ݵķ�ֵ���͹�ֵ��

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//��Ӵ��룺���庯��ģ�壬�ҳ�һά���������з�ֵ������ֵ���ĸ���   ��10�֣�
template<typename T>
void Check(T* arr, int N, int& feng, int& gu) {
	feng = 0; gu = 0;
	for (int i = 1; i + 1 < N; ++i) {
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])feng++;
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])gu++;

	}
}


/* ����������Ҫ��˵�����£�
  ��1�������������鲢��ʼ������ʼ������Ϊ��12,13,21,34,32,41,24,12,14,9
		�����ַ������鲢��ʼ������ʼ������Ϊ��"good","today","max","next","like","hello"   ��2�֣�
  ��2�����ú���ģ�壬�ֱ��ҳ��������������и��Է�ֵ�����͹�ֵ����  ��8�֣�
  ��3������Ŀ������ĸ�ʽҪ����������ݼ���ֵ���͹�ֵ��      ��5�֣�
*/
int main()
{
	//��Ӵ���     ������15�֣�  
	int feng, gu;
	int arr[10] = { 12,13,21,34,32,41,24,12,14,9 };
	for (int i = 0; i < 10; i++) {
		cout << setw(5) << arr[i];
	}
	cout << endl;
	Check<int>(arr, 10, feng, gu);
	cout << "��ֵ��:" << feng
		<< setw(10) << "��ֵ��:" << gu;

	cout << endl;

	string brr[6] = { "good","today","max","next","like","hello" };
	for (int i = 0; i < 6; i++) {
		cout << setw(10) << brr[i];
	}

	cout << endl;
	Check<string>(brr, 6, feng, gu);
	cout << "��ֵ��:" << feng
		<< setw(10) << "��ֵ��:" << gu;
	cout << endl;
	system("pause");
	return 0;
}
