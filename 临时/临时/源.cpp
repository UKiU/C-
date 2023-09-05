#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;



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

int inline CompareX(const Point& a, const Point& b)
{
	if (a.x < b.x) return -1;
	else if (a.x > b.x) return 1;
	else return 0;
}

int inline CompareX_DESC(const Point& a, const Point& b)
{
	if (a.x < b.x) return 1;
	else if (a.x > b.x) return -1;
	else return 0;
}

int inline CompareY(const Point& a, const Point& b)
{
	if (a.y < b.y) return -1;
	else if (a.y > b.y) return 1;
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
class Sorter
{
private:
	T* arr;
	int size;
	int compareCount;
	int swapCount;
	bool sorted = false;

public:
	Sorter(T* arr, int size)
	{
		this->arr = arr;
		this->size = size;
	}

public:
	int inline Compare(const T& o1, const T& o2) const
	{
		if (o1 < o2) return -1;
		else if (o1 > o2) return 1;
		else return 0;
	}

	void inline Swap(T& o1, T& o2)
	{
		T t = o1;
		o1 = o2;
		o2 = t;
	}

	void Sort(int compareMethod(const T&, const T&) = nullptr)
	{
		compareCount = 0;
		swapCount = 0;
		for (int step = size * 0.7; ; step *= 0.618)
		{
			if (step < 1) step = 1;
			bool swapped = false;
			for (int i = 0; i < size - step; ++i)
			{
				int compareResult;
				if (compareMethod != nullptr)
					compareResult = compareMethod(arr[i], arr[i + step]);
				else
					compareResult = Compare(arr[i], arr[i + step]);
				++compareCount;

				if (compareResult > 0)
				{
					Swap(arr[i], arr[i + step]);
					++swapCount;
					swapped = true;
				}
			}
			if (!swapped && step == 1) break;
		}
		sorted = true;
	}

	template <typename TT>
	friend ostream& operator <<(ostream& o, const Sorter<TT>& s);
};

template <typename T>
ostream& operator <<(ostream& o, const Sorter<T>& s)
{
	if (s.sorted)
		o << "数组已排序：" << endl;
	else
		o << "数组未排序：" << endl;

	for (int i = 0; i < s.size; ++i)
		o << s.arr[i] << " ";
	o << endl << endl;

	if (s.sorted)
	{
		o << "比较次数：" << s.compareCount << endl;
		o << "交换次数：" << s.swapCount << endl;
	}

	return o;
}

int main()
{
	ofstream fout("D:\\1.txt");
	ifstream fin("D:\\2.txt");

	srand(time(0));
	int N, M;
	fin >> N;
	cout << N << endl;

	for (; ;)
	{
		if (!(fin >> M))
			break;

		cout << M << endl;
	}

	Point* arr = new Point[N];
	InitArrary(arr, N);

	Sorter<Point> sorter(arr, N);

	cout << sorter;
	fout << sorter;

	sorter.Sort(CompareX_DESC);

	cout << sorter;
	fout << sorter;

	delete[] arr;
	fout.close();
	fin.close();

	return 0;
}