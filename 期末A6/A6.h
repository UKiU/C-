#pragma once
#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;


// =========动态数组模板类 Array =========
template<typename T>
class Array
{
private:
	T* data;      //存储空间首地址
	int length;  //数组大小

public:
	Array(int size = 1024) : length(size > 0 ? size : 1)            //缺省元素数为1024
	{
		data = new T[this->length];   // 申请动态空间
	}

private:
	Array(Array<T> const& rhs) {};       //禁止拷贝
	Array<T>& operator=(Array<T> const& rhs) {} //禁止赋值

public:
	int size() const { return length; }        //返回数组已存储元素个数，兼容vector
	int GetCount() const { return length; }        //返回数组已存储元素个数
	T& operator[](int i) { return data[i]; }    //重载下标运算符[]，用于写
	T const& operator[](int i) const { return data[i]; }         //重载下标运算符[]，用于读
};

template <typename T>
ostream& operator << (ostream& o, const Array<T>& arr)
{
	if (arr.GetCount() < 20)
	{
		for (int i = 0; i < arr.GetCount(); ++i)
			o << arr[i] << " ";
	}
	else
	{
		for (int i = 0; i < 10; ++i)
			o << arr[i] << " ";
		cout << "... ";
		for (int i = arr.GetCount() - 5; i < arr.GetCount(); ++i)
			o << arr[i] << " ";
	}
	return o;
}


// ========= 排序算法基类 Sorter =========
//该结构可以对任意具有可采用中括号“[]”访问或修改其数据的线性结构进行排序
template<typename TList>
class Sorter
{
protected:
	TList* arr;
	int arrSize;
	int compareCount;
	int swapCount;
	string sorterName;
protected:
	// 构造函数，指定为某个数组排序
	Sorter(TList& arr, int arrLength, string sorterName)
		: arr(&arr), arrSize(arrLength), swapCount(0), compareCount(0), sorterName(sorterName)
	{
	}

	Sorter(TList& arr, string sorterName)
		: Sorter(arr, arr.size(), sorterName)
	{
	}

public:
	void virtual Sort() = 0;			// 排序
	void ResetCounter() { compareCount = swapCount = 0; }
	string GetSorterName() const { return sorterName; }
	int GetSwapCount()const { return swapCount; }
	int GetCompareCount()const { return compareCount; }

protected:
	void virtual Swap(int i, int j)		//交换第i和第j个数据
	{
		if (i == j)return;
		int s = sizeof((*arr)[i]);

		unsigned char* buffer = (unsigned char*)malloc(s);

		memcpy_s(buffer, s, &(*arr)[i], s);
		memcpy_s(&(*arr)[i], s, &(*arr)[j], s);
		memcpy_s(&(*arr)[j], s, buffer, s);

		swapCount++;

		free(buffer);
	}

	int virtual Compare(int i, int j)
	{
		compareCount++;
		if ((*arr)[i] < (*arr)[j]) return -1;
		if ((*arr)[i] > (*arr)[j]) return 1;
		return 0;
	}
};

// =========冒泡排序器 BubbleSorter，公有继承 Sorter =========
template<typename TList>
class BubbleSorter : public Sorter<TList>
{
public:
	BubbleSorter(TList& arr, int arrLength)
		: Sorter<TList>(arr, arrLength, "冒泡排序")
	{}

	BubbleSorter(TList& arr)
		: Sorter<TList>(arr, "冒泡排序")
	{}

	void Sort()
	{
		for (int i = 0; i < this->arrSize - 1;)
		{
			if (this->Compare(i, i + 1) > 0)
			{
				this->Swap(i, i + 1);
				if (i > 0)--i;
			}
			else
				++i;
		}
	}
};

// =========冒泡排序器 InsertSorter，公有继承 Sorter =========
template<typename TList>
class InsertSorter : public Sorter<TList>
{
public:
	InsertSorter(TList& arr, int arrLength)
		: Sorter<TList>(arr, arrLength, "插入排序")
	{}

	InsertSorter(TList& arr)
		: Sorter<TList>(arr, "插入排序")
	{}

	void Sort()
	{
		for (int i = 1; i < this->arrSize; ++i)
		{
			int insertPos = i, k = i - 1;
			for (; k >= 0; --k)
				if (this->Compare(i, k) > 0)
				{
					insertPos = k + 1;
					break;
				}
			if (k < 0) insertPos = 0;

			this->Swap(i, insertPos);

			for (int k = i; k >= insertPos + 2; --k)
				this->Swap(k - 1, k);

		}
	}
};

template<typename TList>
class SelectSorter : public Sorter<TList>
{
public:
	SelectSorter(TList& arr, int arrLength)
		: Sorter<TList>(arr, arrLength, "选择排序")
	{}

	SelectSorter(TList& arr)
		: Sorter<TList>(arr, "选择排序")
	{}

	void Sort()
	{
		for (int i = 0; i < this->arrSize - 1; ++i)
		{
			int minPos = i;
			for (int j = i + 1; j < this->arrSize; ++j)
				if (this->Compare(minPos, j) > 0)
					minPos = j;

			this->Swap(minPos, i);
		}
	}
};


template<typename TList>
class ShellSorter : public Sorter<TList>
{
public:
	ShellSorter(TList& arr, int arrLength)
		: Sorter<TList>(arr, arrLength, "希尔排序")
	{}

	ShellSorter(TList& arr)
		: Sorter<TList>(arr, "希尔排序")
	{}

	void Sort()
	{

		for (int step = (int)(this->arrSize * 0.5);; step *= 0.75)
		{
			if (step <= 0) step = 1;
			bool ok = true;
			for (int j = 0; j < this->arrSize - step; ++j)
				if (this->Compare(j, j + step) > 0)
				{
					ok = false;
					this->Swap(j, j + step);
				}

			if (ok && step == 1) break;
		}
	}
};


template<typename TList>
class QuickSorter : public Sorter<TList>
{
public:
	QuickSorter(TList& arr, int arrLength)
		: Sorter<TList>(arr, arrLength, "快速排序")
	{}

	QuickSorter(TList& arr)
		: Sorter<TList>(arr, "快速排序")
	{}

	void Sort(int start, int end)
	{
		if (end - start <= 1) return;

		if (end - start == 2)
		{
			if (this->Compare(start, end - 1) > 0)
				this->Swap(start, end - 1);
			return;
		}

		int m1 = start;
		int m2 = end - 1;
		int m3 = (m1 + m2) / 2;

		int v12 = this->Compare(m1, m2);
		int v23 = this->Compare(m2, m3);
		if (v12 * v23 >= 0)
			this->Swap(m1, m2);
		else
		{
			int v31 = this->Compare(m3, m1);
			if (v23 * v31 >= 0)
				this->Swap(m1, m3);
		}
		int l = start + 1, r = end - 1;
		int m = start;
		for (;;)
		{
			for (; r > start; --r)
				if (this->Compare(m, r) > 0)
					break;
			for (; l < end; ++l)
				if (this->Compare(m, l) < 0)
					break;
			if (l > r) break;

			this->Swap(l, r);
		}

		m = r;
		this->Swap(m, start);

		Sort(start, m);
		Sort(m + 1, end);
	}

	void Sort()
	{
		Sort(0, this->arrSize);
	}
};