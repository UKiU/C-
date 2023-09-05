#include <iostream> 
#include <ctime>
#include <windows.h>
#include "A6.h" 

using namespace std;

int main()
{
	int N = 10000;			//���鳤��,   ��Ϊ���Գ��򷽱㣬�ڵ���ʱ�ɸ�Ϊ�� int N = 1000;��
	int x = time(0);		//�������
	Array<int> arr(N);		//���������װ����


	Sorter<Array<int >>* sorters[5];	//����ָ�������������ָ������

	for (int i = 0; i < 5; ++i)			//�ֱ𴴽��������������
	{
		switch (i)
		{
			//����ð��������
		case 0:  
			sorters[i] = new BubbleSorter<Array<int>>(arr);
			break;

			//��Ӵ��룺���δ���������������ѡ����������ϣ����������������������8�֣�
		case 1:
			sorters[i] = new InsertSorter<Array<int>>(arr);
			break;
		case 2:
			sorters[i] = new SelectSorter<Array<int>>(arr);
			break;
		case 3:
			sorters[i] = new ShellSorter<Array<int>>(arr);
			break;
		case 4:
			sorters[i] = new QuickSorter<Array<int>>(arr);
			break;
		default: sorters[i] = nullptr;
		}
	}


	//��ʼ�����������
	for (int i = 0; i < 5; ++i)
	{
		if (sorters[i] == nullptr)			//������������
			continue;

		srand(x);							//����������ӣ�ÿ����������ͬ������
		for (int i = 0; i < N; i++)		
			arr[i] = rand() % (N * 5);		//�����������ʼ��������

		cout << "��" << sorters[i]->GetSorterName() << "��" << endl;	//���������������

		//��Ӵ��룺����Ŀ��ʾ�����ʽ�����ԭʼ�������ݡ����������Ƚϴ����������������Լ������ʱ��12�֣�
		
		cout << "ԭʼ����: "<<arr[i] << endl;
		int t1 = GetTickCount();
		sorters[i]->Sort();
		int t2= GetTickCount();
		int t3 = (t2 - t1)*1.0/1000.0;
		cout << "������: "<<arr[i]  << endl;
		cout << "�Ƚϴ���: " << sorters[i]->GetSwapCount() << endl;
		cout << "��������: " << sorters[i]->GetCompareCount() << endl;
		cout << "����ʱ��: " << t3 <<"��" << endl;


	}

	//��Ӵ��룺�ͷ��ڴ棨5�֣�
	for (int i = 0; i < 5; i++) {
		delete sorters[i];
	}
	return 0;
}

