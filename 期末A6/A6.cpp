#include <iostream> 
#include <ctime>
#include <windows.h>
#include "A6.h" 

using namespace std;

int main()
{
	int N = 10000;			//数组长度,   （为调试程序方便，在调试时可改为： int N = 1000;）
	int x = time(0);		//随机种子
	Array<int> arr(N);		//创建数组封装对象


	Sorter<Array<int >>* sorters[5];	//创建指向五个排序器的指针数组

	for (int i = 0; i < 5; ++i)			//分别创建五个排序器数组
	{
		switch (i)
		{
			//创建冒泡排序器
		case 0:  
			sorters[i] = new BubbleSorter<Array<int>>(arr);
			break;

			//添加代码：依次创建插入排序器、选择排序器、希尔排序器、快速排序器（8分）
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


	//开始进行排序测试
	for (int i = 0; i < 5; ++i)
	{
		if (sorters[i] == nullptr)			//跳过空排序器
			continue;

		srand(x);							//设置随机种子，每次排序都是相同的数据
		for (int i = 0; i < N; i++)		
			arr[i] = rand() % (N * 5);		//利用随机数初始化的数组

		cout << "【" << sorters[i]->GetSorterName() << "】" << endl;	//输出排序器的名称

		//添加代码：按题目所示输出格式，输出原始数组内容、排序结果、比较次数、交换次数，以及排序耗时（12分）
		
		cout << "原始数组: "<<arr[i] << endl;
		int t1 = GetTickCount();
		sorters[i]->Sort();
		int t2= GetTickCount();
		int t3 = (t2 - t1)*1.0/1000.0;
		cout << "排序结果: "<<arr[i]  << endl;
		cout << "比较次数: " << sorters[i]->GetSwapCount() << endl;
		cout << "交换次数: " << sorters[i]->GetCompareCount() << endl;
		cout << "排序时间: " << t3 <<"秒" << endl;


	}

	//添加代码：释放内存（5分）
	for (int i = 0; i < 5; i++) {
		delete sorters[i];
	}
	return 0;
}

