#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<Windows.h>
using namespace std;
#define N 1000000000

void InitArr(int* arr, int n) {
	for (int i = 0; i < n ; i++) {
		arr[i] = ((rand() <<15) + rand()) % (n  * 2);
	}
}

int Check1(int* arr, int n) {
	long long code = 0;
	for (int i = 0; i < n; i++) {
		code += arr[i];
	}
	return code;
}
int mmm(int* arr, int left, int right) {
	int  mid = arr[left];
	while (left < right) {
		while (left < right && arr[right] >= mid) {
			right--;
		}
		arr[left] = arr[right];
		while (left < right && arr[left] <= mid) {
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = mid;
	return left;
}

void Sort(int * &arr,int left,int right) {
	if (left < right) {
		int index = mmm(arr,left,right);
		Sort(arr,left, index-1);
		Sort(arr, index+1, right);
	}
	
}

bool Check2(int* arr, int n, int code) {
	for (int i = 0; i < n-1; i++) {
		if (arr[i] > arr[i + 1])return 0;
	}
	long long c = Check1(arr, n);
	if (c != code)return 0;
	return 1;

}

int main() {
	srand(time(0));
	int * arr = new int[N];
	InitArr(arr, N);

	long long code = Check1(arr, N);
	
	int t1 = GetTickCount();
	int left = 0; int right = N - 1;
	Sort(arr,left,right);
	int t2 = GetTickCount();
	
	bool OK = Check2(arr, N, code);
	if (OK)cout << "ture" << endl;
	else cout << "false" << endl;
	
	double t = (t2 - t1) / 1000.0;
	cout << "time = " << t << "s" << endl;
	cout << N << endl;
	delete []arr;
	
	return 0;
}
