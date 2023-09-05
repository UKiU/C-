#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class List;

template <typename T>
class Node
{
private:
	T data;
	Node* next;

public:
	Node(const T& newData);

	const T& GetData()const { return data; }
	const Node* GetNext()const { return next; }

	
	const Node*

	template <typename t>
	friend class List;

	//template <typename t>
	//friend ostream& operator <<  (ostream& o, const List<T>& list);

};

template <typename T>
Node<T>::Node(const T& newData)
{
	this->data = newData;
	next = nullptr;
}

template <typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	const Node<T>* GetHead()const { return head; }

	Node<T>* Add(const T& newData);
	Node<T>* InsertFront(const T& newData);

	const int GetCount();
	const Node<T>* operator[] const (int index);
	Node<T>* operator[](int index);

	Node<T>* Insert(const T& newData, int index);
	Node<T>* RemoveAt(int index);

	void Clear();

	~List() { Clear(); }

	//friend ostream& operator << (ostream& o, const List<T>& list);
};

template <typename T>
Node<T>* List<T>::Add(const T& newData)
{
	Node<T>* newNode = new Node<T>(newData);

	if (!tail)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;
	}

	return newNode;
}

template <typename T>
Node<T>* List<T>::InsertFront(const T& newData)
{
	Node<T>* newNode = new Node<T>(newData);

	if (!head)
		head = tail = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}

	return newNode;
}

template <typename T>
ostream& operator << (ostream& o, const List<T>& list)
{
	for (const Node<T>* p = list.GetHead();
		p;
		p = p->GetNext())
	{
		o << "[" << p->GetData() << "]";

		if (p->GetNext())
			o << " -> ";
	}

	return o;
}

int main()
{
	{
		List<int> iList;
		iList.Add(3);
		iList.Add(5);
		iList.Add(7);
		iList.InsertFront(6);
		iList.InsertFront(4);
		iList.InsertFront(2);

		cout << iList << endl;
	}
	{
		List<double> iList;
		iList.Add(2.3);
		iList.Add(5.1);
		iList.Add(7.1);
		iList.InsertFront(6.3);
		iList.InsertFront(4.1);
		iList.InsertFront(2.3);

		cout << iList << endl;
	}
}