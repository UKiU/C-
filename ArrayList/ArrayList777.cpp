#include <iostream>
using namespace std;

template<typename T>
class ArrayList
{
	T* arr;
	int count;
	int capacity;

public:
	ArrayList(int capacity = 1024) : count(0), capacity(capacity)
	{
		arr = new T[capacity];
	}

	ArrayList(const T& data, int repeatCount, int capacity = 1024)
		: ArrayList(capacity)
	{
		for (int i = 0; i < repeatCount; ++i)
			Add(data);
	}

	bool Add(const T& data)
	{
		if (count >= capacity) return false;

		arr[count] = data;
		++count;
		return true;
	}

	bool Insert(int id, const T& data)
	{
		if (count >= capacity) return false;

		for (int i = count - 1; i >= id; --i)
			arr[i + 1] = arr[i];

		arr[id] = data;
		++count;
		return true;
	}

	bool RemoveAt(int id)
	{
		if (id >= 0 && id < count)
		{
			for (int i = id + 1; i < count; ++i)
				arr[i - 1] = arr[i];

			--count;
			return true;
		}
		else
			return false;
	}

	const T& operator[] (int id) const
	{
		return arr[id];
	}

	T& operator[] (int id)
	{
		return arr[id];
	}

	int GetCount() const { return count; }

	~ArrayList() { delete arr; }
};

template<typename T>
ostream& operator << (ostream& o, const ArrayList<T>& list)
{
	for (int i = 0; i < list.GetCount(); ++i)
	{
		if (i > 0) o << " --> ";
		o << list[i];
	}

	return o;
}

template<typename T>
class Stack : public ArrayList<T>
{
public:
	Stack(const T& data, int repeatCount, int capacity = 1024) :
		ArrayList<T>(data, repeatCount, capacity)
	{

	}

	void Push(const T& data)
	{
		this->Add(data);
	}

	T Pop()
	{
		T val = (*this)[this->GetCount() - 1];
		this->RemoveAt(this->GetCount() - 1);

		return val;
	}
};

int  main()
{
	ArrayList<int> arr(15, 3);
	cout << arr << endl;

	cout << endl;
	Stack<int> myStack(9, 9);
	myStack.Push(3);
	myStack.Push(4);
	myStack.Push(5);
	cout << myStack << endl;
	cout << "POP: " << myStack.Pop() << endl;
	cout << myStack << endl;

	return 0;
}