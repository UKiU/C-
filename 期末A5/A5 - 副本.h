//////////////////////////////////////////////////////////////////////////////////////
// This file defines a array with template, named Array<T>.                         //
//              Author: Li, Junyang                                                 //
//             Version: 1.3                                                         //
//       Creation Date: 2013-03-15   for project XMV                                //
// Last Moidified Date: 2021-12-24   for C++ examination of School of W.J.X., SEU   //
//////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


#pragma region DEFINITIONS
#define EPS (1E-10)
#define EnumArr(type, pointer) for(T * pointer = dataPtr; pointer < dataEndPtr; ++pointer)

#define enumImageEnd }}}

#define enumImage(bmp, width, height, x1, x2, y1, y2, pointer)  \
{ \
	int x_____, y_____; \
	int x1_____ = (x1); \
	int y1_____ = (y1); \
	int x2_____ = (x2); \
	int y2_____ = (y2); \
	int stepy_____ = (width)-(x2_____ - x1_____); \
	int offset_____ = y1_____ * width + x1_____; \
	pointer = (bmp)+offset_____; \
	for (y_____ = y1_____; y_____ < y2_____; ++y_____, pointer += stepy_____) \
{ \
	for (x_____ = x1_____; x_____ < x2_____; ++x_____, ++pointer) \
{

#define enumImageStep(bmp, width, height, x1, x2, y1, y2, xStep, yStep, pointer)  \
{ \
	int x_____, y_____; \
	int x1_____ = (x1); \
	int y1_____ = (y1); \
	int x2_____ = (x2); \
	int y2_____ = (y2); \
	int xs_____ = (xStep); \
	int ys_____ = (yStep); \
	int stepy_____ = ys_____ * (width)-(x2_____ - x1_____) / xs_____ * xs_____; \
	int offset_____ = y1_____ * (width)+x1_____; \
	pointer = (bmp)+offset_____; \
	for (y_____ = y1_____; y_____ < y2_____; y_____ += ys_____, pointer += stepy_____) \
{ \
	for (x_____ = x1_____; x_____ < x2_____; x_____ += xs_____, pointer += xs_____) \
{

#define enumImage2(bmp1, bmp2, width, height, x1, x2, y1, y2, pointer1, pointer2)  \
{ \
	int x_____, y_____; \
	int x1_____ = (x1); \
	int y1_____ = (y1); \
	int x2_____ = (x2); \
	int y2_____ = (y2); \
	int stepy_____ = (width)-(x2_____ - x1_____); \
	int offset_____ = y1_____ * (width)+x1_____; \
	pointer1 = (bmp1)+offset_____; \
	pointer2 = (bmp2)+offset_____; \
	for (y_____ = y1_____; y_____ < y2_____; ++y_____, pointer1 += stepy_____, pointer2 += stepy_____) \
{ \
	for (x_____ = x1_____; x_____ < x2_____; ++x_____, ++pointer1, ++pointer2) \
{

#define enumImage3(bmp1, bmp2, bmp3, width, height, x1, x2, y1, y2, pointer1, pointer2, pointer3)  \
{ \
	int x_____, y_____; \
	int x1_____ = (x1); \
	int y1_____ = (y1); \
	int x2_____ = (x2); \
	int y2_____ = (y2); \
	int stepy_____ = (width)-(x2_____ - x1_____); \
	int offset_____ = y1_____ * (width)+x1_____; \
	pointer1 = (bmp1)+offset_____; \
	pointer2 = (bmp2)+offset_____; \
	pointer3 = (bmp3)+offset_____; \
	for (y_____ = y1_____; y_____ < y2_____; ++y_____, \
	pointer1 += stepy_____, \
	pointer2 += stepy_____, \
	pointer3 += stepy_____) \
{ \
	for (x_____ = x1_____; x_____ < x2_____; ++x_____, \
	++pointer1, \
	++pointer2, \
	++pointer3) \
{

#define enumImage4(bmp1, bmp2, bmp3, bmp4, width, height, x1, x2, y1, y2, pointer1, pointer2, pointer3, pointer4)  \
{ \
	int x_____, y_____; \
	int x1_____ = (x1); \
	int y1_____ = (y1); \
	int x2_____ = (x2); \
	int y2_____ = (y2); \
	int stepy_____ = (width)-(x2_____ - x1_____); \
	int offset_____ = y1_____ * (width)+x1_____; \
	pointer1 = (bmp1)+offset_____; \
	pointer2 = (bmp2)+offset_____; \
	pointer3 = (bmp3)+offset_____; \
	pointer4 = (bmp4)+offset_____; \
	for (y_____ = y1_____; y_____ < y2_____; ++y_____, \
	pointer1 += stepy_____, \
	pointer2 += stepy_____, \
	pointer3 += stepy_____, \
	pointer4 += stepy_____) \
{ \
	for (x_____ = x1_____; x_____ < x2_____; ++x_____, \
	++pointer1, \
	++pointer2, \
	++pointer3, \
	++pointer4) \
{

#define enumImage5(bmp1, bmp2, bmp3, bmp4, bmp5, width, height, x1, x2, y1, y2, pointer1, pointer2, pointer3, pointer4, pointer5)  \
{ \
	int x_____, y_____; \
	int x1_____ = (x1); \
	int y1_____ = (y1); \
	int x2_____ = (x2); \
	int y2_____ = (y2); \
	int stepy_____ = (width)-(x2_____ - x1_____); \
	int offset_____ = y1_____ * (width)+x1_____; \
	pointer1 = (bmp1)+offset_____; \
	pointer2 = (bmp2)+offset_____; \
	pointer3 = (bmp3)+offset_____; \
	pointer4 = (bmp4)+offset_____; \
	pointer5 = (bmp5)+offset_____; \
	for (y_____ = y1_____; y_____ < y2_____; ++y_____, \
	pointer1 += stepy_____, \
	pointer2 += stepy_____, \
	pointer3 += stepy_____, \
	pointer4 += stepy_____, \
	pointer5 += stepy_____) \
{ \
	for (x_____ = x1_____; x_____ < x2_____; ++x_____, \
	++pointer1, \
	++pointer2, \
	++pointer3, \
	++pointer4, \
	++pointer5) \
{

#define enumImage6(bmp1, bmp2, bmp3, bmp4, bmp5, bmp6, width, height, x1, x2, y1, y2, pointer1, pointer2, pointer3, pointer4, pointer5, pointer6)  \
{ \
	int x_____, y_____; \
	int x1_____ = (x1); \
	int y1_____ = (y1); \
	int x2_____ = (x2); \
	int y2_____ = (y2); \
	int stepy_____ = (width)-(x2_____ - x1_____); \
	int offset_____ = y1_____ * (width)+x1_____; \
	pointer1 = (bmp1)+offset_____; \
	pointer2 = (bmp2)+offset_____; \
	pointer3 = (bmp3)+offset_____; \
	pointer4 = (bmp4)+offset_____; \
	pointer5 = (bmp5)+offset_____; \
	pointer6 = (bmp6)+offset_____; \
	for (y_____ = y1_____; y_____ < y2_____; ++y_____, \
	pointer1 += stepy_____, \
	pointer2 += stepy_____, \
	pointer3 += stepy_____, \
	pointer4 += stepy_____, \
	pointer5 += stepy_____) \
	pointer6 += stepy_____) \
{ \
	for (x_____ = x1_____; x_____ < x2_____; ++x_____, \
	++pointer1, \
	++pointer2, \
	++pointer3, \
	++pointer4, \
	++pointer5, \
	++pointer6, \
	) \
{


#define enumArray(arr, x1, x2, pointer) \
{ \
	void * end_____ = (arr)+(x2); \
	for ((pointer) = (arr)+(x1); (pointer) < (end_____); ++(pointer)) \
{

#define enumArray2(arr1, arr2, x1, x2, pointer1, pointer2) \
{ \
	void * end_____ = (arr1)+(x2); \
	(pointer1) = (arr1)+(x1); \
	(pointer2) = (arr2)+(x1); \
	for (; (pointer1) < (end_____); ++pointer1, ++pointer2) \
{

#define enumArray3(arr1, arr2, arr3, x1, x2, pointer1, pointer2, pointer3) \
{ \
	void * end_____ = (arr1)+(x2); \
	(pointer1) = (arr1)+(x1); \
	(pointer2) = (arr2)+(x1); \
	(pointer3) = (arr3)+(x1); \
	for (; (pointer1) < (end_____); ++(pointer1), ++(pointer2), ++(pointer3)) \
{

#define enumArray4(arr1, arr2, arr3, arr4, x1, x2, pointer1, pointer2, pointer3, pointer4) \
{ \
	void * end_____ = (arr1)+(x2); \
	(pointer1) = (arr1)+(x1); \
	(pointer2) = (arr2)+(x1); \
	(pointer3) = (arr3)+(x1); \
	(pointer4) = (arr4)+(x1); \
	for (; (pointer1) < (end_____); ++(pointer1), ++(pointer2), ++(pointer3), ++(pointer4)) \
{

#define enumArray5(arr1, arr2, arr3, arr4, arr5, x1, x2, pointer1, pointer2, pointer3, pointer4, pointer5) \
{ \
	void * end_____ = (arr1)+(x2); \
	(pointer1) = (arr1)+(x1); \
	(pointer2) = (arr2)+(x1); \
	(pointer3) = (arr3)+(x1); \
	(pointer4) = (arr4)+(x1); \
	(pointer5) = (arr5)+(x1); \
	for (; (pointer1) < (end_____); ++(pointer1), ++(pointer2), ++(pointer3), ++(pointer4), ++(pointer5)) \
{

#define enumArray6(arr1, arr2, arr3, arr4, arr5, arr6, x1, x2, pointer1, pointer2, pointer3, pointer4, pointer5, pointer6) \
{ \
	void * end_____ = (arr1)+(x2); \
	(pointer1) = (arr1)+(x1); \
	(pointer2) = (arr2)+(x1); \
	(pointer3) = (arr3)+(x1); \
	(pointer4) = (arr4)+(x1); \
	(pointer5) = (arr5)+(x1); \
	(pointer6) = (arr6)+(x1); \
	for (; (pointer1) < (end_____); ++(pointer1), ++(pointer2), ++(pointer3), ++(pointer4), ++(pointer5), ++(pointer6)) \
{


#define enumArray7(arr1, arr2, arr3, arr4, arr5, arr6, arr7, x1, x2, pointer1, pointer2, pointer3, pointer4, pointer5, pointer6, pointer7) \
{ \
	void * end_____ = (arr1)+(x2); \
	(pointer1) = (arr1)+(x1); \
	(pointer2) = (arr2)+(x1); \
	(pointer3) = (arr3)+(x1); \
	(pointer4) = (arr4)+(x1); \
	(pointer5) = (arr5)+(x1); \
	(pointer6) = (arr6)+(x1); \
	(pointer7) = (arr7)+(x1); \
	for (; (pointer1) < (end_____); ++(pointer1), ++(pointer2), ++(pointer3), ++(pointer4), ++(pointer5), ++(pointer6), ++(pointer7)) \
{
#define enumArrayEnd }}


#pragma endregion

#pragma region CLASS ARRAY
template<typename T>class Array
{
protected:
	int size;								//size count of the Array
	int memorySize;							//memory size of the Array  = size * sizeof(T)
	T* dataPtr;							//the start fo Array array
	T* dataEndPtr;							//the end of Array array

public:
	Array();
	Array(int size);
	Array(int size, T value);
	Array(const Array<T>& other);
	Array(T* arr, int size);
	Array(int size, T* arr, int arrSize);

	~Array(void);

	inline int Size() const;						// ����Ԫ�صĸ���
	inline int MemorySize() const;				// ����ʵ��ռ���ڴ���ֽ���
	inline void ReSize(int size);			// �����趨��С��������е�����
	inline T* Buffer();					// ��ȡ�ڲ�������׵�ַ
	const inline T* Buffer() const;					// ��ȡ�ڲ�������׵�ַ
	inline void SetValue(int index, T val);	// ���õ�index�����ݵ�ֵ
	inline T GetValue(int index) const;			// ��õ�index������
	//T SquareOfNorm2() const;						// 2��ʽ��ƽ��
	//T SquareOfDistance(const Array<T>& another) const;	// ������һ������ľ����ƽ��
	//T Distance(const Array<T>& another) const;			// ������������ľ���
	Array<T> Cut(int start, int len) const;		// �������н�ȡһ���ֳ�Ϊ�µ�����
	Array<T> Cut(int start) const;				// ���������һ���֣������µ����飬��start��ʼ��һֱ������
	T Norm0() const;								// 0��ʽ�������0Ԫ�ظ���
	T Norm1() const;								// 1��ʽ����������Ԫ�صĺ�
	T Norm2() const;								// 2��ʽ����������Ԫ�ص�ƽ���Ϳ�����
	T Norm(int p = 2) const;						// p��ʽ
	T Sum() const;								// ����Ԫ�صĺ�
	void SetSmallValueToZero();				// ������ֵС��eps����ֵ����Ϊ0
	T AbsMin() const;						// ���ؾ���ֵ����Сֵ
	T Min() const;							// ������Сֵ
	T AbsMax() const;						// ���ؾ���ֵ�����ֵ
	T Max() const;							// �������ֵ
	void Offset(T value);					// ��������ƫ��value
	T Average() const;						// ����������ݵ�ƽ��ֵ
	void AverageTo(T value = 0)				// ������ƽ������ĳ����ֵ
	{
		T avg = this->Average();
		EnumArr(T, ptr)
		{
			*ptr -= (avg - value);
		}
	}

	T Variance() const;							// ���ط���
	void GaussianWhiten() const;					// ��˹�׻���ʹ������ƽ��ֵΪ0������Ϊ1
	void AbsValues();						// ���е�Ԫ��ȡ����ֵ
	bool InfinityCheck(T maxValue = 1E50) const;	// ���ݼ�飬���������Ƿ�������Ϊ�����
	int ClearInfinityValues(T maxValue = 1E50, T clearValue = 0);	// ���ݼ�飬���������Ƿ�������Ϊ���������У������Ϊclearvalue��������յ����ݵĸ���
	bool IsZero() const;							// ���������Ƿ�ȫ��Ϊ0
	void Clear();							// ������ȫ����0
	void Normalization();					// ���滯��ÿ��Ԫ��ƽ����Ϊ1
	void SumAsOne();						// ��ÿ��Ԫ�صĺ�Ϊ1
	void SetMinTo(T value);					// ��С��value��Ԫ��ȫ������Ϊvalue
	void SetMaxTo(T value);					// ������value��Ԫ��ȫ������Ϊvalue
	//bool Contains(T value, int begin = 0, int len = -1); //�����Ƿ����ֵΪvalue��Ԫ��=-0987654321`

protected:
	inline void Init(int size);

public:
	Array<T>& operator = (Array<T>& v);
	Array<T>& operator = (T value);
	T& operator[] (int index);
	const T& operator[] (int index)const;
};

template<typename T>
inline int Array<T>::Size() const
{
	return size;
}

template<typename T>
inline int Array<T>::MemorySize() const
{
	return memorySize;
}

template<typename T>
inline T* Array<T>::Buffer()
{
	return this->dataPtr;
}

template<typename T>
const inline T* Array<T>::Buffer() const
{
	return this->dataPtr;
}

template<typename T>
inline void Array<T>::SetValue(int index, T val)
{
	dataPtr[index] = val;
}

template<typename T>
inline T Array<T>::GetValue(int index) const
{
	return dataPtr[index];
}

template<typename T>
Array<T> Array<T>::Cut(int start, int len) const
{
	Array<T> v(len);
	memcpy(v.dataPtr, this->dataPtr + start, len * sizeof(T));
	return v;
}

template<typename T>
Array<T> Array<T>::Cut(int start) const
{
	int len = this->size - start;
	Array<T> v(len);
	memcpy(v.dataPtr, this->dataPtr + start, len * sizeof(T));
	return v;
}


template<typename T> T Array<T>::Average()	 const				// ����������ݵ�ƽ��ֵ
{
	T sum = 0;
	EnumArr(T, ptr)
		sum += *ptr;
	return sum / size;
}

template<typename T> T Array<T>::Variance()	 const						// ���ط���
{
	T avg = Average();
	T sum = 0;
	T temp;
	EnumArr(T, ptr)
	{
		temp = *ptr - avg;
		sum += temp * temp;
	}
	return sum / this->size;
}


template<typename T>
T Array<T>::Norm0()  const// 0��ʽ�������0Ԫ�ظ���
{
	int count = 0;
	EnumArr(T, ptr)
		if (fabs(*ptr) > EPS) count++;
	return count;
}

template<typename T>
T Array<T>::Norm1()  const// 1��ʽ����������Ԫ�صĺ�
{
	T sum = 0;
	EnumArr(T, ptr)
		sum += *ptr;
	return sum;
}

template<typename T>
T Array<T>::Norm2()  const// 2��ʽ����������Ԫ�ص�ƽ��
{
	T sum = 0;
	EnumArr(T, ptr)
		sum += *ptr * *ptr;
	return sqrt(sum);
}

template<typename T>
T Array<T>::Sum() const // ��������Ԫ�صĺ�
{
	T sum = 0;
	EnumArr(T, ptr)
		sum += *ptr;
	return sum;
}

template<typename T>
inline void Array<T>::Init(int size)
{
	this->size = size;
	memorySize = size * sizeof(T);

	dataPtr = new T[size];
	dataEndPtr = dataPtr + size;
}

template<typename T>
Array<T>::Array()
{
	Init(1);
}

template<typename T>
Array<T>::Array(int size)
{
	Init(size);
}

template<typename T>
Array<T>::Array(int size, T value)
{
	Init(size);

	EnumArr(T, ptr)
		* ptr = value;
}

template<typename T>
Array<T>::Array(T* arr, int size)
{
	Init(size);
	memcpy(this->dataPtr, arr, this->memorySize);
}

template<typename T>
Array<T>::Array(int size, T* arr, int arrSize)
{
	Init(size);
	int s = (this->memorySize < arrSize) * sizeof(T) ?
		this->memorySize : arrSize * sizeof(T);
	memcpy(this->dataPtr, arr, s);
}

template<typename T>
Array<T>::Array(const Array<T>& other)
{
	Init(other.size);
	::memcpy(this->dataPtr, other.dataPtr, memorySize);
}

template<typename T>
inline void Array<T>::ReSize(int size)
{
	if (this->size != size)
	{
		delete[] dataPtr;
		Init(size);
	}
}

template<typename T> Array<T>::~Array(void)
{
	delete[] dataPtr;
}

template<typename T> ostream& operator << (ostream& out, const Array<T>& data)
{
	const T* ptrEnd = data.Buffer() + data.Size();
	for (const T* ptr = data.Buffer(); ptr < ptrEnd; ++ptr)
	{
		out << setw(8) << *ptr << ' ';
	}

	return out;
}

template<typename T> istream& operator >> (istream& in, Array<T>& data)
{
	T* ptr = data.Buffer();
	int size = data.Size();

	for (int y = 0; !in.eof() && y < size; ++y)
	{
		in >> *ptr++;
	}

	return in;
}

template<typename T> Array<T>& Array<T>::operator = (Array<T>& v)
{
	this->ReSize(v.size);

	memcpy(this->dataPtr, v.dataPtr, this->memorySize);

	return *this;
}

template<typename T> Array<T>& Array<T>::operator = (T value)
{
	EnumArr(T, ptr)
		* ptr = value;
	return *this;
}

template<typename T> T& Array<T>::operator[] (int index)
{
	return this->dataPtr[index];
}

template<typename T> const T& Array<T>::operator[] (int index)const
{
	return this->dataPtr[index];
}

//��С��EPS��ֵ����Ϊ0
template<typename T> void Array<T>::SetSmallValueToZero()
{
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr)
		if (fabs(*ptr) < EPS) *ptr = 0;
}

template<typename T> T Array<T>::AbsMin() const
{
	T max;
	max = 0;
	EnumArr(T, ptr)
		if (fabs(*ptr) < max) max = fabs(*ptr);
	return max;
}
template<typename T> T Array<T>::Min() const
{
	T max;
	max = 0;
	EnumArr(T, ptr)
		if (*ptr < max) max = *ptr;
	return max;
}
template<typename T> T Array<T>::AbsMax() const
{
	T max;
	max = 0;
	EnumArr(T, ptr)
		if (fabs(*ptr) > max) max = fabs(*ptr);
	return max;
}

template<typename T> T Array<T>::Max() const
{
	T max;
	max = 0;
	EnumArr(T, ptr)
		if (*ptr > max) max = *ptr;
	return max;
}

template<typename T> void Array<T>::Offset(T value)
{
	T max = 0;
	EnumArr(T, ptr)
		* ptr += value;
}

template<typename T> T Array<T>::Norm(int p) const	//��ʽ
{
	T sum = 0;
	EnumArr(T, ptr)
		sum += pow(*ptr, p);
	return pow(sum, 1.0 / p);
}

template<typename T> void Array<T>::AbsValues()
{
	EnumArr(T, ptr)
		* ptr = fabs(*ptr);
}

// ���ݼ�飬���������Ƿ�������Ϊ�����
template<typename T> bool Array<T>::InfinityCheck(T maxValue)	 const	// ���ݼ�飬���������Ƿ�������Ϊ�����
{
	EnumArr(T, ptr)
	{
		if (!(*ptr > -maxValue)) return false;
		if (!(*ptr < maxValue)) return false;
	}
	return true;
}

// ���ݼ�飬���������Ƿ�������Ϊ���������У������Ϊclearvalue��������յ����ݵĸ���
template<typename T> int Array<T>::ClearInfinityValues(T maxValue, T clearValue)
{
	int count = 0;
	EnumArr(T, ptr)
	{
		if (!(*ptr > -maxValue)) { count++; *ptr = clearValue; }
		if (!(*ptr < maxValue)) { count++; *ptr = clearValue; }
	}
	return count;
}


// ���ݼ�飬���������Ƿ�������Ϊ�����
template<typename T> bool Array<T>::IsZero() const		// ���ݼ�飬���������Ƿ�������Ϊ�����
{
	EnumArr(T, ptr)
	{
		if (*ptr > EPS) return false;
		if (*ptr < -EPS) return false;
	}
	return true;
}

//��������0
template<typename T> void Array<T>::Clear()
{
	memset(dataPtr, 0, memorySize);
}

// ���滯��ÿ��Ԫ��ƽ����Ϊ1
template<typename T> void Array<T>::Normalization()
{
	T v = this->Norm2();
	if (fabs(v) > EPS)
		EnumArr(T, ptr)
		* ptr /= v;
}

// ʹÿ��Ԫ�صĺ�Ϊ1
template<typename T> void Array<T>::SumAsOne()
{
	T v = this->Norm1();
	if (fabs(v) > EPS)
		EnumArr(T, ptr)
		* ptr /= v;
}

// ��С��value��Ԫ��ȫ������Ϊvalue
template<typename T> void Array<T>::SetMinTo(T value)
{
	EnumArr(T, ptr)
		if (*ptr < value) *ptr = value;
}
// ������value��Ԫ��ȫ������Ϊvalue
template<typename T> void Array<T>::SetMaxTo(T value)
{
	EnumArr(T, ptr)
		if (*ptr > value) *ptr = value;
}
#pragma endregion

#pragma region CLASS VECTOR
//////////////////////////////////////////////////////////////////////////////////////
// This file defines a vector with template, named Vector<T>��which is inherited    //
// from Array<T> in 'array.h'.                                                      //
//              Author: Li, Junyang                                                 //
//             Version: 1.3                                                         //
//       Creation Date: 2013-03-15   for project XMV                                //
// Last Moidified Date: 2021-12-24   for C++ examination of School of W.J.X., SEU   //
//////////////////////////////////////////////////////////////////////////////////////
template<typename T> class Matrix;
template<typename T> class Vector : public Array<T>
{
public:
	Vector();
	Vector(int size);
	Vector(int size, T value);
	Vector(const Vector<T>& other);
	Vector(T* arr, int size);

	~Vector(void);

	inline Vector<T> Cut(int start, int len) const;		//�������н�ȡһ���ֳ�Ϊ�µ�����2
	inline Vector<T> Cut(int start) const;				//�������н�ȡһ���ֳ�Ϊ�µ�����

public:

	inline Vector<T>& operator = (const Vector<T>& v);
	inline Vector<T>& operator = (T value);
	inline Vector<T>& operator += (const Vector<T>& v);
	inline Vector<T>& operator -= (const Vector<T>& v);
	inline Vector<T>& operator *= (T value);
	inline Vector<T>& operator /= (T value);
	inline T& operator[] (int index);
	inline const T& operator[] (int index) const;
};

template<typename T>
Vector<T>::Vector(const Vector<T>& other) : Array<T>(other.dataPtr, other.size)
{
}

template<typename T>
Vector<T>::Vector() : Array<T>()
{
}

template<typename T>
Vector<T>::Vector(int size) : Array<T>(size)
{
}

template<typename T>
Vector<T>::Vector(int size, T value) : Array<T>(size, value)
{
}

template<typename T>
Vector<T>::Vector(T* arr, int size) : Array<T>(arr, size)
{
}

template<typename T> Vector<T>::~Vector(void)
{
}

template<typename T> ostream& operator << (ostream& out, const Vector<T> vector)
{
	const T* ptr = vector.Buffer();
	int size = vector.Size();

	for (int y = 0; y < size; ++y)
	{
		out << setw(8) << *ptr++ << ' ';
	}

	return out;
}

template<typename T> istream& operator >> (istream& in, Vector<T>& vector)
{
	T* ptr = vector.Buffer();
	int size = vector.Size();

	for (int y = 0; !in.eof() && y < size; ++y)
	{
		in >> *ptr++;
	}

	return in;
}

template<typename T> Vector<T>& Vector<T>::operator = (const Vector<T>& v)
{
	this->ReSize(v.size);

	memcpy(this->dataPtr, v.dataPtr, v.memorySize);

	return *this;
}

template<typename T> Vector<T>& Vector<T>::operator = (T value)
{
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr)
		*ptr = value;
	return *this;
}

template<typename T> Vector<T>& Vector<T>::operator += (const Vector<T>& v)
{
	const T* sourcePtr = v.Buffer();
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr, ++sourcePtr)
		*ptr += *sourcePtr;
	return *this;
}

template<typename T> Vector<T>& Vector<T>::operator -= (const Vector<T>& v)
{
	const T* sourcePtr = v.Buffer();
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr, ++sourcePtr)
		*ptr -= *sourcePtr;
	return *this;
}

template<typename T> Vector<T>& Vector<T>::operator *= (T value)
{
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr)
		*ptr *= value;
	return *this;
}

template<typename T> Vector<T>& Vector<T>::operator /= (T value)
{
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr)
		*ptr /= value;
	return *this;
}

template<typename T> Vector<T> operator + (const Vector<T>& v1, const Vector<T>& v2)
{
	Vector<T> v = v1;
	v += v2;
	return v;
}

template<typename T> Vector<T> operator - (const Vector<T>& v1, const Vector<T>& v2)
{
	Vector<T> v = v1;
	v -= v2;
	return v;
}

template<typename T> Vector<T> operator + (const Vector<T>& vector)
{
	Vector<T> v = Vector;
	return v;
}

template<typename T> Vector<T> operator - (const Vector<T>& vector)
{
	Vector<T> v(vector.Size());
	const T* sourcePtr = vector.Buffer();
	const T* EndPtr = v.Buffer() + v.Size();
	for (T* ptr = v.Buffer(); ptr < EndPtr; ++ptr, ++sourcePtr)
		*ptr = -*sourcePtr;
	return v;
}

template<typename T> Matrix<T> operator * (const Vector<T>& m1, const Matrix<T>& m2)
{
	int c1 = 1;
	int r1 = m1.Size();
	int c2 = m2.Col();
	int r2 = m2.Row();
	if (c1 != r2) throw;
	Matrix<T> m(r1, c2);
	int x, y;
	const T* m1sizePtr = m1.Buffer(), * ptr1;
	const T* m2Ptr = m2.Buffer(), * m2ColPtr, * ptr2;
	T* ptr = m.Buffer();

	for (y = 0; y < r1; ++y, m1sizePtr += c1) //ѭ��m����
	{
		m2ColPtr = m2Ptr;
		for (x = 0; x < c2; ++x, ++m2ColPtr, ++ptr) //ѭ��m����
		{
			ptr1 = m1sizePtr;
			ptr2 = m2ColPtr;

			*ptr = *ptr1 * *ptr2;;
		}
	}

	return m;
}

template<typename T> Vector<T> operator * (const Matrix<T>& m1, const Vector<T>& m2)
{
	int c1 = m1.Col();
	int r1 = m1.Row();
	int r2 = m2.Size();

	if (c1 != r2) throw;
	Vector<T> m(r1);
	int y, z;
	const T* m1RowPtr = m1.Buffer(), * ptr1;
	const T* m2Ptr = m2.Buffer(), * ptr2;
	T* ptr = m.Buffer();
	T sum;
	for (y = 0; y < r1; ++y, m1RowPtr += c1, ++ptr) //ѭ��m����
	{
		ptr1 = m1RowPtr;
		ptr2 = m2Ptr;
		sum = 0;
		for (z = 0; z < c1; ++z, ++ptr1, ++ptr2) //����mÿ����Ԫ���ֵ
		{
			if (*ptr1 * *ptr2 < 0)
			{
				sum = sum;
			}
			sum += *ptr1 * *ptr2;
		}
		*ptr = sum;

	}

	return m;
}

template<typename T> T operator * (const Vector<T>& v1, const Vector<T>& v2)
{
	if (v1.Size() != v2.Size()) throw;

	const T* p1, * p2;
	T sum = 0;
	enumArray2((v1.Buffer()), (v2.Buffer()), 0, (v1.Size()), p1, p2)
		sum += *p1 * *p2;
	enumArrayEnd;

	return sum;
}

template<typename T> Vector<T> operator * (T val, const Vector<T>& vector)
{
	Vector<T> m = vector;
	m *= val;

	return m;
}

template<typename T> Vector<T> operator * (const Vector<T>& vector, T val)
{
	Vector<T> m = vector;
	m *= val;

	return m;
}

template<typename T> Vector<T> operator / (const Vector<T>& vector, T val)
{
	Vector<T> m = vector;
	m /= val;

	return m;
}

template<typename T> T& Vector<T>::operator[] (int index)
{
	return this->dataPtr[index];
}

template<typename T> const T& Vector<T>::operator[] (int index) const
{
	return this->dataPtr[index];
}

//��õ�λ������������oneIndex��Ϊ1������Ϊ0��sizeΪ�������ȣ�oneIndexΪ�ڼ�������ֵΪ1����0��ʼ��
template<typename T> Vector<T> UnitVector(int size, int oneIndex)
{
	Vector<T> v(size, (T)0);
	v[oneIndex] = 1;
	return v;
}

//���һ���������
template<typename T> Vector<T> RandomVector(int size, T minValue, T maxValue)
{
	Vector<T> v(size);
	T* ptr;
	enumArray(v.Buffer(), 0, size, ptr)
		* ptr = rand(minValue, maxValue);
	enumArrayEnd;

	return v;
}

//���һ������ĵ�λ����
template<typename T> Vector<T> RandomUnitVector(int size)
{
	if (T(1) / 2 == 0)
		return UnitVector<T>(size, (rand() % size));

	Vector<T> v(size);
	T* ptr;
	enumArray(v.Buffer(), 0, size, ptr)
		* ptr = (T)rand() / RAND_MAX;
	enumArrayEnd;

	return v / v.Modulo();
}

//�������н�ȡһ���ֳ�Ϊ�µ�����
template<typename T>
Vector<T> Vector<T>::Cut(int start, int len)const
{
	Vector<T> v(len);
	memcpy(v.dataPtr, this->dataPtr + start, len * sizeof(T));
	return v;
}

//�������н�ȡһ���ֳ�Ϊ�µ�����
template<typename T>
Vector<T> Vector<T>::Cut(int start)const
{
	int len = this->size - start;
	Vector<T> v(len);
	memcpy(v.dataPtr, this->dataPtr + start, len * sizeof(T));
	return v;
}

//�����������ϲ�Ϊһ������
template<typename T> Vector<T> MergeVector(const Vector<T>& m1, const Vector<T>& m2)
{
	int c1 = m1.Size();
	int c2 = m2.Size();
	int c = c1 + c2;

	Vector<T> m(c, 0);

	memcpy(m.Buffer(), m1.Buffer(), m1.MemorySize());
	memcpy((char*)m.Buffer() + m1.MemorySize(), m2.Buffer(), m2.MemorySize());

	return m;
}

#pragma endregion

#pragma region CLASS MATRIX
//////////////////////////////////////////////////////////////////////////////////////
// This file defines a matrix with template, named Matrix<T>��                    //
// which is inherited from Array<T> in 'array.h'.                                             //
//              Author: Li, Junyang																			//
//              Version: 1.3																						//
// Creation Date: 2013-03-15   for project XMV											    //
// Last Moidified Date: 2021-12-24   for C++ examination of School of W.J.X., SEU   //
//////////////////////////////////////////////////////////////////////////////////////

template<typename T> class Matrix : public Array<T>
{
protected:
	int row;				//row count of the matrix
	int col;				//col count of the matrix
public:
	Matrix();
	Matrix(int rowCount, int colCount);
	Matrix(int rowCount, int colCount, T value);
	Matrix(int rowCount, int colCount, T* valueArr, int valueArrSize);
	Matrix(const Matrix<T>& other);
	~Matrix(void);

	inline int Row() const;													//���ؾ��������
	inline int Col() const;															//���ؾ��������	
	inline void ReSize(int rowCount, int colCount);								//���¶������Ĵ�С����������е�����
	inline void SetValue(int rowIndex, int colIndex, T val);					//���þ����е�����
	inline T GetValue(int rowIndex, int colIndex)const;								//���ؾ����е�����

	T* Buffer() { return this->dataPtr; }
	const T* Buffer() const { return this->dataPtr; }
	int Size() const { return size; }
	int MemorySize() const { return this->memorySize; }

	inline Vector<T> ToVector() const;

	inline void TransformRowMul(int row, T factor);								//Row[row]  *= factor
	inline void TransformRowDiv(int row, T factor);								//Row[row]  /= factor
	inline void TransformRowSum(int row1, int row2);							//Row[row1] += Row[row2]
	inline void TransformRowSub(int row1, int row2);							//Row[row1] -= Row[row2]
	inline void TransformRow(int row1, T factor1, int row2, T factor2);			//Row[row1] = Row[row1] * factor1 + Row[row2] * factor2
	inline void TransformRowSwap(int row1, int row2);							//Row[row1] <==> Row[row2]
	inline void TransformColSwap(int col1, int col2);							//Col[col1] <==> Col[col2]

	Vector<T> GetRow(int rowIndex) const;											//��þ����ĳһ��
	Vector<T> GetCol(int colIndex) const;												//��þ����ĳһ��
	//Matrix<T> SelectColumns(const Vector<int>& indexVector)const;		//�Ӿ���ѡȡindexVector��ָ�����У�����µľ���
	void SetCol(int colIndex, T value);											//�������þ����ĳһ��Ϊͬ����ֵvalue
	void SetCol(int colIndex, Vector<T>& colVector);							//�������þ����ĳһ��
	void SetRow(int rowIndex, T value);											//�������ĳһ������Ϊͬ��������value
	void SetRow(int rowIndex, Vector<T>& rowVector);							//�������þ����ĳһ��
	Matrix<T> Cut(int rowStart, int rowCount, int colStart, int colCount)const;		//��þ����һ����
	Matrix<T> Cut(int rowStart, int colStart)const;									//��þ����һ����
	void CopyFrom(const Matrix<T>& source, int dstRowStart, int dstColStart);		//����һ����С�ľ����Ƶ���������

	Matrix<T> Transpose(void)const;													//����ת�þ���
	Matrix<T> ConjugateTranspose(void)const;											//���ع���ת��
	Matrix<T> Inverse()const;														//���ظþ������
	Matrix<T> Pseudoinverse()const;													//���ظþ���Ĺ�����
	void GaussianElimination(bool eliminateUpperHalf = true);						//�Ծ�����г��ȱ任��ʹ�þ����ǰrow�г�Ϊ��λ��
	int Rank()const;																	//��øþ������
	bool IsFullRank()const;															//���ظþ����Ƿ������ȵ�
	T Determinant()const;															//��øþ��������ʽ

//	
public:
	Matrix<T>& operator = (const Matrix<T>& m);
	Matrix<T>& operator = (T value);

	Matrix<T>& operator += (const Matrix<T>& m);

	Matrix<T>& operator -= (const Matrix<T>& m);

	Matrix<T>& operator *= (const Matrix<T>& m);
	Matrix<T>& operator *= (T value);

	Matrix<T>& operator /= (T value);

	Matrix<T> operator ~ () const;
	Matrix<T> operator ! () const;
	T* operator [] (int rowIndex);
	const T* operator [] (int rowIndex) const;

};

template<typename T> inline Vector<T> Matrix<T>::ToVector() const
{
	return Vector<T>(this->dataPtr, this->size);
}

template<typename T> T* Matrix<T>::operator [] (int rowIndex)
{
	return this->dataPtr + rowIndex * col;
}

template<typename T> const T* Matrix<T>::operator [](int rowIndex) const
{
	return this->dataPtr + rowIndex * col;
}


template<typename T> Matrix<T>::Matrix()
{
}

template<typename T> Matrix<T>::Matrix(int rowCount, int colCount)
	: row(rowCount), col(colCount), Array<T>(rowCount* colCount)
{
}

template<typename T> Matrix<T>::Matrix(const Matrix<T>& other)
	: row(other.row), col(other.col), Array<T>(other.dataPtr, other.row* other.col)
{
}

template<typename T> Matrix<T>::Matrix(int rowCount, int colCount, T value)
	: row(rowCount), col(colCount), Array<T>(rowCount* colCount, value)
{
}

template<typename T> Matrix<T>::Matrix(int rowCount, int colCount, T* valueArr, int valueArrSize)
	: Array<T>(rowCount* colCount, valueArr, valueArrSize), row(rowCount), col(colCount)
{
}

template<typename T> void Matrix<T>::ReSize(int rowCount, int colCount)
{
	row = rowCount;
	col = colCount;
	Array<T>::ReSize(row * col);
}

//���ؾ��������
template<typename T> inline int  Matrix<T>::Row() const
{
	return row;
}

//���ؾ��������	
template<typename T> inline int  Matrix<T>::Col() const
{
	return col;
}

//���þ����е�����
template<typename T> inline void  Matrix<T>::SetValue(int rowIndex, int colIndex, T val)
{
	this->dataPtr[rowIndex * col + colIndex] = val;
}

//���ؾ����е�����
template<typename T> inline T  Matrix<T>::GetValue(int rowIndex, int colIndex) const
{
	return this->dataPtr[rowIndex * col + colIndex];
}

//���ת�þ���
template<typename T> Matrix<T> Matrix<T>::Transpose() const
{
	Matrix m(col, row);
	T* ptr = this->dataPtr;
	T* mColPtr = m.dataPtr, * mPtr;
	int x, y;
	for (y = 0; y < row; ++y, ++mColPtr)
	{
		mPtr = mColPtr;
		for (x = 0; x < col; ++x, ++ptr, mPtr += row)
		{
			*mPtr = *ptr;
		}
	}
	return m;
}

//��ù���ת�þ���
template<typename T> Matrix<T> Matrix<T>::ConjugateTranspose()const
{
	Matrix m(col, row);
	T* ptr = this->dataPtr;
	T* mColPtr = m.dataPtr, * mPtr;
	int x, y;
	for (y = 0; y < row; ++y, ++mColPtr)
	{
		mPtr = mColPtr;
		for (x = 0; x < col; ++x, ++ptr, mPtr += row)
		{
			*mPtr = *ptr;
		}
	}
	return m;
}

template<typename T> Matrix<T>::~Matrix(void)
{
}

template<typename T> ostream& operator << (ostream& out, const Matrix<T>& matrix)
{
	const T* ptr = matrix.Buffer();
	int x, y;
	int row = matrix.Row();
	int col = matrix.Col();

	for (y = 0; y < row; ++y)
	{
		for (x = 0; x < col; ++x)
		{
			out << setw(8) << *ptr++ << ' ';
		}
		out << endl;
	}
	return out;
}

template<typename T> istream& operator >> (istream& in, Matrix<T>& matrix)
{
	T* ptr = matrix.Buffer();
	int x, y;

	for (y = 0; y < matrix.Row(); ++y)
	{
		for (x = 0; x < matrix.Col(); ++x)
		{
			in >> *ptr++;
		}
	}
	return in;
}

template<typename T> Matrix<T>& Matrix<T>::operator = (const Matrix<T>& m)
{
	this->ReSize(m.Row(), m.Col());
	const T* sourcePtr = m.Buffer();
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr, ++sourcePtr)
		*ptr = *sourcePtr;
	return *this;
}

template<typename T> Matrix<T>& Matrix<T>::operator = (T value)
{
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr)
		*ptr = value;
	return *this;
}

template<typename T> Matrix<T>& Matrix<T>::operator += (const Matrix<T>& m)
{
	const T* sourcePtr = m.Buffer();
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr, ++sourcePtr)
		*ptr += *sourcePtr;
	return *this;
}

template<typename T> Matrix<T>& Matrix<T>::operator *= (const Matrix<T>& m)
{
	return *this = *this * m;
}

template<typename T> Matrix<T>& Matrix<T>::operator -= (const Matrix<T>& m)
{
	const T* sourcePtr = m.Buffer();
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr, ++sourcePtr)
		*ptr -= *sourcePtr;
	return *this;
}

template<typename T> Matrix<T>& Matrix<T>::operator *= (T value)
{
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr)
		*ptr *= value;
	return *this;
}

template<typename T> Matrix<T>& Matrix<T>::operator /= (T value)
{
	for (T* ptr = this->dataPtr; ptr < this->dataEndPtr; ++ptr)
		*ptr /= value;
	return *this;
}

template<typename T> Matrix<T> Matrix<T>::operator ~ () const
{
	return this->ConjugateTranspose();
}

template<typename T> Matrix<T> operator + (const Matrix<T>& m1, const Matrix<T>& m2)
{
	Matrix<T> m = m1;
	m += m2;
	return m;
}

template<typename T> Matrix<T> operator - (const Matrix<T>& m1, const Matrix<T>& m2)
{
	Matrix<T> m = m1;
	m -= m2;
	return m;
}

template<typename T> Matrix<T> operator + (const Matrix<T>& matrix)
{
	Matrix<T> m = matrix;
	return m;
}

template<typename T> Matrix<T> operator - (const Matrix<T>& matrix)
{
	Matrix<T> m(matrix.Row(), matrix.Col());
	const T* sourcePtr = matrix.Buffer();
	T* ptrEnd = m.Buffer() + m.Size();
	for (T* ptr = m.Buffer(); ptr < ptrEnd; ++ptr, ++sourcePtr)
		*ptr = -*sourcePtr;
	return m;
}

template<typename T> Matrix<T> operator * (const Matrix<T>& m1, const Matrix<T>& m2)
{
	int c1 = m1.Col();
	int c2 = m2.Col();
	int r1 = m1.Row();
	int r2 = m2.Row();

	if (c1 != r2) throw;

	Matrix<T> m(r1, c2);

	int x, y, z;
	const T* m1RowPtr = m1.Buffer();
	const T* ptr1;
	const T* m2Ptr = m2.Buffer();
	const T* m2ColPtr;
	const T* ptr2;
	T* ptr = m.Buffer();
	T sum;
	for (y = 0; y < r1; ++y, m1RowPtr += c1) //ѭ��m����
	{
		m2ColPtr = m2Ptr;
		for (x = 0; x < c2; ++x, ++m2ColPtr, ++ptr) //ѭ��m����
		{
			ptr1 = m1RowPtr;
			ptr2 = m2ColPtr;
			sum = 0;
			for (z = 0; z < c1; ++z, ++ptr1, ptr2 += c2) //����mÿ����Ԫ���ֵ
			{
				sum += *ptr1 * *ptr2;
			}
			*ptr = sum;
		}
	}

	return m;
}

template<typename T> Matrix<T> operator * (const T& val, const Matrix<T>& matrix)
{
	Matrix<T> m = matrix;
	m *= val;

	return m;
}

template<typename T> Matrix<T> operator * (const Matrix<T>& matrix, T val)
{
	Matrix<T> m = matrix;
	m *= val;

	return m;
}

template<typename T> Matrix<T> operator / (const Matrix<T>& matrix, T val)
{
	Matrix<T> m = matrix;
	m /= val;

	return m;
}


//ͨ������m������v�����������
template<typename T> Matrix<T> CreateAugmentedMatrix(const Matrix<T>& m, const Vector<T>& v)
{
	if (m.Col() != m.Row()) throw;
	if (m.Row() != v.Size()) throw;

	Matrix<T> matrix(m.Row(), m.Col() + 1);
	const T* ptr1 = m.Buffer();
	const T* ptrV = v.Buffer();
	T* ptr2 = matrix.Buffer();
	int x, y;
	for (y = 0; y < m.Row(); ++y, ++ptr2, ++ptrV)
	{
		for (x = 0; x < m.Col(); ++x, ++ptr1, ++ptr2)
		{
			*ptr2 = *ptr1;
		}
		*ptr2 = *ptrV;
	}

	return matrix;
}

//��õ�λ����
template <typename T> Matrix<T> UnitMatrix(int row, int col)
{
	Matrix<T> m(row, col, 0);
	int sz = row < col ? row : col;     //Min(row, col);
	int id = 0;
	for (T* ptr = m.Buffer(); id < sz; ++id, ptr += col + 1)
		*ptr = 1;

	return m;
}

//��õ�λ����
template <typename T> Matrix<T> UnitMatrix(int matrixOrder)
{
	Matrix<T> m(matrixOrder, matrixOrder, 0);
	int id = 0;
	for (T* ptr = m.Buffer(); id < matrixOrder; ++id, ptr += matrixOrder + 1)
		*ptr = 1;

	return m;
}

template<typename T> Matrix<T> Matrix<T>::Cut(int rowStart, int rowCount, int colStart, int colCount) const
{
	Matrix<T> m(rowCount, colCount);
	T* ptrD = m.Buffer();
	T* ptrS = this->dataPtr + col * rowStart + colStart;
	int copyLen = colCount * sizeof(T);
	for (int i = 0; i < rowCount; ++i, ptrD += colCount, ptrS += this->col)
		memcpy(ptrD, ptrS, copyLen);

	return m;
}	 //��þ����һ����


template<typename T> Matrix<T> Matrix<T>::Cut(int rowStart, int colStart) const
{
	int rowCount = this->row - rowStart;
	int colCount = this->col - colStart;
	Matrix<T> m(rowCount, colCount);
	T* ptrD = m.Buffer();
	T* ptrS = this->dataPtr + col * rowStart + colStart;
	int copyLen = colCount * sizeof(T);
	for (int i = 0; i < rowCount; ++i, ptrD += colCount, ptrS += this->col)
		memcpy(ptrD, ptrS, copyLen);

	return m;
}	 //��þ����һ����

template<typename T> void Matrix<T>::SetCol(int colIndex, T value)
{
	T* dataPtr = this->dataPtr + colIndex;
	for (int rowIndex = 0; rowIndex < row; ++rowIndex, dataPtr += col)
		*dataPtr = value;
}

template<typename T> void Matrix<T>::SetCol(int colIndex, Vector<T>& colVector)
{
	T* vectorPtr = colVector.Buffer();
	T* vectorPtrEnd = vectorPtr + colVector.Size();
	T* dataPtr = this->dataPtr + colIndex;
	for (; vectorPtr < vectorPtrEnd; ++vectorPtr, dataPtr += col)
		*dataPtr = *vectorPtr;
}

template<typename T> void Matrix<T>::SetRow(int rowIndex, T value)
{
	T* dataPtr = this->dataPtr + this->col * rowIndex;
	for (int colIndex = 0; colIndex < col; ++colIndex, ++dataPtr)
		*dataPtr = value;
}

template<typename T> void Matrix<T>::SetRow(int rowIndex, Vector<T>& rowVector)
{
	T* vectorPtr = rowVector.Buffer();
	T* dataPtr = this->dataPtr + this->col * rowIndex;
	memcpy(dataPtr, vectorPtr, rowVector.MemorySize());
}

template<typename T> void Matrix<T>::CopyFrom(const Matrix<T>& source, int dstRowStart, int dstColStart)
{
	const T* ptrS = source.Buffer();
	int colCount = source.Col();
	int rowCount = source.Row();
	T* ptrD = this->dataPtr + col * dstRowStart + dstColStart;
	int copyLen = colCount * sizeof(T);
	for (int i = 0; i < rowCount; ++i, ptrS += colCount, ptrD += this->col)
		memcpy(ptrD, ptrS, copyLen);
}	//����һ����С�ľ����Ƶ���������

template<typename T> Vector<T> Matrix<T>::GetRow(int rowIndex) const
{
	return Vector<T>(this->dataPtr + rowIndex * col, col);
}

template<typename T> Vector<T> Matrix<T>::GetCol(int colIndex) const
{
	Vector<T> v(row);
	T* ptr = v.Buffer();
	T* ptrEnd = ptr + v.Size();
	T* ptr2 = this->dataPtr + colIndex;
	for (; ptr < ptrEnd; ++ptr, ptr2 += col)
		*ptr = *ptr2;

	return v;
}

//Row[row] *= factor
template<typename T> inline void Matrix<T>::TransformRowMul(int row, T factor)
{
	T* ptr = this->dataPtr + row * col;
	T* ptrEnd = ptr + col;
	for (; ptr < ptrEnd; ++ptr)
		*ptr *= factor;
}

//Row[row] /= factor
template<typename T> inline void Matrix<T>::TransformRowDiv(int row, T factor)
{
	T* ptr = this->dataPtr + row * col;
	T* ptrEnd = ptr + col;
	for (; ptr < ptrEnd; ++ptr)
		*ptr /= factor;
}

//Row[row1] += Row[row2]
template<typename T> inline void Matrix<T>::TransformRowSum(int row1, int row2)
{
	T* p1 = this->dataPtr + row1 * col;
	T* p2 = this->dataPtr + row2 * col;
	T* pe = p1 + col;
	for (; p1 < pe; ++p1, ++p2)
		*p1 += *p2;
}

//Row[row1] -= Row[row2]
template<typename T> inline void Matrix<T>::TransformRowSub(int row1, int row2)
{
	T* p1 = this->dataPtr + row1 * col;
	T* p2 = this->dataPtr + row2 * col;
	T* pe = p1 + col;
	for (; p1 < pe; ++p1, ++p2)
		*p1 -= *p2;
}

//Row[row1] = Row[row1] * factor1 + Row[row2] * factor2
template<typename T> inline void Matrix<T>::TransformRow(int row1, T factor1, int row2, T factor2)
{
	T* p1 = this->dataPtr + row1 * col;
	T* p2 = this->dataPtr + row2 * col;
	T* pe = p1 + col;
	for (; p1 < pe; ++p1, ++p2)
		*p1 = *p1 * factor1 + *p2 * factor2;
}

//Row[row1] <==> Row[row2]
template<typename T> inline void Matrix<T>::TransformRowSwap(int row1, int row2)
{
	T t;
	T* p1 = this->dataPtr + row1 * col;
	T* p2 = this->dataPtr + row2 * col;
	T* pe = p1 + col; for (; p1 < pe; ++p1, ++p2)
	{
		t = *p1;
		*p1 = *p2;
		*p2 = t;
	}
}

//Col[col1] <==> Col[col2]
template<typename T> inline void Matrix<T>::TransformColSwap(int col1, int col2)
{
	T t;
	T* p1 = this->dataPtr + col1;
	T* p2 = this->dataPtr + col2;
	T* pe = this->dataEndPtr;
	for (; p1 < pe; p1 += col, p2 += col)
	{
		t = *p1;
		*p1 = *p2;
		*p2 = t;
	}
}

//��˹��ȥ�������һ����λ��
template<typename T> void Matrix<T>::GaussianElimination(bool eliminateUpperHalf)
{
	Matrix<T>& am = *this;
	T* rowPtr = am.Buffer();
	T* ptr;
	int row = am.Row();
	int col = am.Col();

	int r = row < col ? row : col;

	int x, y;

	for (x = 0; x < r; ++x, rowPtr += col + 1)
	{
		//Ѱ�ҵ�һ����0�У����������
		ptr = rowPtr;
		for (y = x; y < row && fabs(*ptr) < EPS; ++y, ptr += col);
		if (y >= row)
			continue;
		if (y != x)
			am.TransformRowSum(x, y);

		////cout << am << endl;

		//���й�һ��
		ptr = rowPtr;
		for (y = x; y < row; ++y, ptr += col)
		{
			if (fabs(*ptr) > EPS)
				am.TransformRowDiv(y, *ptr);
		}

		////cout << am << endl;

		//�����·��趨Ϊ0
		ptr = rowPtr + col;
		for (y = x + 1; y < row; ++y, ptr += col)
		{
			if (fabs(*ptr) > EPS)
				am.TransformRowSub(y, x);
		}

		////cout << am << endl;

		//�����Ϸ��趨Ϊ0
		if (eliminateUpperHalf && fabs(*rowPtr) > EPS)
		{
			ptr = rowPtr - col;
			for (y = x - 1; y >= 0; --y, ptr -= col)
			{
				am.TransformRow(y, 1, x, -(*ptr));
			}
		}

		////cout << am << endl;
	}
}

//��������������ϲ�Ϊһ������
template<typename T> Matrix<T> MergeMatrixVertical(Matrix<T>& m1, Matrix<T>& m2)
{
	int c1 = m1.Col();
	int c2 = m2.Col();
	int r1 = m1.Row();
	int r2 = m2.Row();
	int r = r1 + r2;
	int c = c1;

	if (c1 != c2) throw;

	Matrix<T> m(r, c);

	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < r1; i++)
			m.SetValue(i, j, m1.GetValue(i, j));
		for (int i = 0; i < r2; i++)
			m.SetValue(i + r1, j, m2.GetValue(i, j));
	}

	return m;
}

//�������������ϲ�Ϊһ������
template<typename T> Matrix<T> MergeMatrixHorizontal(const Matrix<T>& m1, const Matrix<T>& m2)
{
	int c1 = m1.Col();
	int c2 = m2.Col();
	int c = c1 + c2;
	int r = m1.Row();

	if (r != m2.Row()) throw;

	Matrix<T> m(r, c);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c1; j++)
			m.SetValue(i, j, m1.GetValue(i, j));
		for (int j = 0; j < c2; j++)
			m.SetValue(i, j + c1, m2.GetValue(i, j));
	}

	return m;
}

//���ؾ������
template<typename T> Matrix<T> Matrix<T>::Inverse() const
{
	if (this->row != this->col) throw;
	int r = this->row;
	Matrix<T> mx = MergeMatrixHorizontal(*this, UnitMatrix<T>(r));
	mx.GaussianElimination();
	return mx.Cut(0, r);
}

//���ؾ������
template<typename T> int Matrix<T>::Rank() const
{
	Matrix<T> m = *this;
	m.GaussianElimination(false);

	//int r = min(m.col, m.row);
	int r =  (m.col<= m.row)? m.col : m.row;
	for (int i = 0; i < r; ++i)
	{
		if (fabs(m[i][i]) < EPS)
			--r;
	}
	return r;
}

//�þ����Ƿ�Ϊ���Ⱦ���
template<typename T> bool Matrix<T>::IsFullRank() const
{
	return this->Rank() == (this->row < this->col ? this->row : this->col);
}

//���ؾ���Ĺ�����
template<typename T> Matrix<T> Matrix<T>::Pseudoinverse() const
{
	Matrix<T> B = this->Transpose();
	Matrix<T> C = (*this) * B;
	return C.Inverse() * B;
}

//���ؾ��������߹�����
template<typename T> Matrix<T> Matrix<T>::operator ! () const
{
	return this->Pseudoinverse();
}

//���ؾ��������ʽ
template<typename T> T Matrix<T>::Determinant() const
{
	Matrix<T> am = *this;
	T* rowPtr = am.Buffer();
	T* ptr;
	int row = am.Row();
	int col = am.Col();

	if (row != col) throw;

	int x, y;

	T dev = 1;
	for (x = 0; x < row; ++x, rowPtr += col + 1)
	{
		//Ѱ�ҵ�һ����0�У����������
		ptr = rowPtr;
		for (y = x; y < row && fabs(*ptr) < EPS; ++y, ptr += col);
		if (y >= row) return 0;	//�ҵ���ȫ0�����ʽΪ0
		if (y != x)
			am.TransformRowSum(x, y);

		////cout << am << endl;

		//���й�һ��
		ptr = rowPtr;
		for (y = x; y < row; ++y, ptr += col)
		{
			if (fabs(*ptr) > EPS)
			{
				dev *= *ptr;
				am.TransformRowDiv(y, *ptr);
			}
		}

		////cout << am << endl;

		//�����·��趨Ϊ0
		ptr = rowPtr + col;
		for (y = x + 1; y < row; ++y, ptr += col)
		{
			if (fabs(*ptr) > EPS)
				am.TransformRowSub(y, x);
		}

	}

	//cout << am;
	//cout << dev << endl;

	return dev;
}
#pragma endregion