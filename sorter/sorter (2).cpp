#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int compareCount;
int swapCount;

class Point
{
public:
	double x;
	double y;

	double Mould() const
	{
		return sqrt(x * x + y * y);
	}
};

int inline CompareX(Point* arr, int i, int j)
{
	compareCount++;
	if (arr[i].x < arr[j].x) return -1;
	else if (arr[i].x > arr[j].x) return 1;
	else return 0;
}

int inline CompareX_DESC(Point* arr, int i, int j)
{
	compareCount++;
	if (arr[i].x < arr[j].x) return 1;
	else if (arr[i].x > arr[j].x) return -1;
	else return 0;
}

int inline CompareY(Point* arr, int i, int j)
{
	compareCount++;
	if (arr[i].y < arr[j].y) return -1;
	else if (arr[i].y > arr[j].y) return 1;
	else return 0;
}

ostream& operator<< (ostream& o, const Point& p)
{
	return o << "(" << p.x << ", " << p.y << ")";
}

bool operator < (const Point& p1, const Point& p2)
{
	return p1.Mould() < p2.Mould();
}

bool operator > (const Point& p1, const Point& p2)
{
	return p1.Mould() > p2.Mould();
}


void InitArrary(Point* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i].x = (rand() + rand() * 1.0 / RAND_MAX) * size * 2 / RAND_MAX;
		arr[i].y = (rand() + rand() * 1.0 / RAND_MAX) * size * 2 / RAND_MAX;
	}
}

void InitArrary(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = (rand() + rand() * 1.0 / RAND_MAX) * size * 2 / RAND_MAX;
}

void InitArrary(double* arr, int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = (rand() + rand() * 1.0 / RAND_MAX) * size * 2 / RAND_MAX;
}

template <typename T>
void PrintArrary(T* arr, int size, const char* info)
{
	cout << info << endl;
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl << endl;
}

template <typename T>
int inline Compare(T* arr, int i, int j)
{
	compareCount++;
	if (arr[i] < arr[j]) return -1;
	else if (arr[i] > arr[j]) return 1;
	else return 0;
}

template <typename T>
void inline Swap(T* arr, int i, int j)
{
	swapCount++;
	T t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

template <typename T>
void Sort(T* arr, int size, int compareMethod(T*, int, int) = nullptr)
{
	for (int step = size * 0.7; ; step *= 0.618)
	{
		if (step < 1) step = 1;
		bool swapped = false;
		for (int i = 0; i < size - step; ++i)
		{
			int compareResult;
			if (compareMethod != nullptr)
				compareResult = compareMethod(arr, i, i + step);
			else
				compareResult = Compare(arr, i, i + step);

			if (compareResult > 0)
			{
				Swap(arr, i, i + step);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

int main()
{
	srand(time(0));
	int N = 30;
	Point* arr = new Point[N];

	InitArrary(arr, N);
	PrintArrary(arr, N, "未排序数组：");
	Sort(arr, N, CompareX_DESC);
	PrintArrary(arr, N, "已排序数组：");

	printf("交换次数：%d\n比较次数：%d\n", swapCount, compareCount);

	delete[] arr;
	return 0;
}