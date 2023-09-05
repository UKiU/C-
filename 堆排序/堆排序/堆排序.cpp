#include <iostream>
using namespace std;

class Sqlist{
private:
	int* r;
	int length;
public:
	Sqlist(int n) {
		this->length = n;
		this->r = new int[n+1];
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			r[i] = a;
		}
	}
	~Sqlist() {
		delete[]this->r;
	}
	int Getr(int i) {
		return this->r[i];
	}
	friend void HeapAdjust(Sqlist& L, int s, int m);
	friend void CreatHeap(Sqlist& L);
	friend void HeapSort(Sqlist& L);
};
void HeapAdjust(Sqlist& L, int s, int m) {
	int rc = L.r[s];
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m && L.r[j] < L.r[j + 1])++j;
		if (rc >= L.r[j])break;
		L.r[s] = L.r[j]; s = j;
	}
	L.r[s] = rc;
}
void CreatHeap(Sqlist& L) {
	int n = L.length;
	for (int i = n / 2; i > 0; i--) {
		HeapAdjust(L, i, n);
	}
}
void HeapSort(Sqlist& L) {
	CreatHeap(L);
	for (int i = L.length; i > 1; --i) {
		int x = L.r[1];
		L.r[1] = L.r[i];
		L.r[i] = x;
		HeapAdjust(L, 1, i - 1);
	}
}
int main()
{
	Sqlist L(5);
	for (int i = 1; i <= 5; i++) {
		cout << L.Getr(i) << "  ";
	}
	cout << endl;
	HeapSort(L);
	for (int i = 1; i <= 5; i++) {
		cout << L.Getr(i)<<"  ";
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
