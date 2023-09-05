//定义函数模板，找出一组数据的峰值数和谷值数

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//添加代码：定义函数模板，找出一维数组数据中峰值数、谷值数的个数   （10分）
template<typename T>
void Check(T* arr, int N, int& feng, int& gu) {
	feng = 0; gu = 0;
	for (int i = 1; i + 1 < N; ++i) {
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])feng++;
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])gu++;

	}
}


/* 主函数测试要求说明如下：
  （1）定义整型数组并初始化，初始化数据为：12,13,21,34,32,41,24,12,14,9
		定义字符串数组并初始化，初始化数据为："good","today","max","next","like","hello"   （2分）
  （2）调用函数模板，分别找出以上两组数据中各自峰值个数和谷值个数  （8分）
  （3）按题目中输出的格式要求，数组的数据及峰值数和谷值数      （5分）
*/
int main()
{
	//添加代码     （共计15分）  
	int feng, gu;
	int arr[10] = { 12,13,21,34,32,41,24,12,14,9 };
	for (int i = 0; i < 10; i++) {
		cout << setw(5) << arr[i];
	}
	cout << endl;
	Check<int>(arr, 10, feng, gu);
	cout << "峰值数:" << feng
		<< setw(10) << "谷值数:" << gu;

	cout << endl;

	string brr[6] = { "good","today","max","next","like","hello" };
	for (int i = 0; i < 6; i++) {
		cout << setw(10) << brr[i];
	}

	cout << endl;
	Check<string>(brr, 6, feng, gu);
	cout << "峰值数:" << feng
		<< setw(10) << "谷值数:" << gu;
	cout << endl;
	system("pause");
	return 0;
}
