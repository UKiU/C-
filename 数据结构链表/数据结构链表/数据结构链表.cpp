#include <iostream>
using namespace std;

class Node {
private:
	int Number;
	Node* Next;
	Node* Prior;
	int Freq;
public:
	Node() {
		this->Number = 0;
		this->Next = nullptr;
		this->Prior = nullptr;
		this->Freq = 0;
	}
	Node(const int& n);

	const int& GetNumber() const {
		return Number;
	}
	const Node* GetNext()const {
		return Next;
	}
	const Node* GetPrior()const {
		return Prior;
	}
	friend class LinkedList;
};

Node::Node(const int& n) {
	this->Number = n;
	this->Next = nullptr;
	this->Prior = nullptr;
}

class LinkedList {
private:
	Node* Head;
	Node* Tail;
public:
	LinkedList() {
		Head = nullptr;
		Tail = nullptr;
	}
	LinkedList(LinkedList& L1) {
		Node* Count = L1.Head;
		while (Count) {
			this->Add(Count->Number);
			Count = Count->Next;
		}
	}

	void Clear();//清除堆空间
	~LinkedList() { Clear(); }//析构函数

	const Node* GetHead()const { return Head; }

	Node* Add(const int& Data);//插入在尾部
	//Node* InsertFrist(const int& Data);//插入在第一个

	const int GetCount();//计总数
	const int GetThisCount(Node* This);
	const int CheckMax();
	const int CheckMaxPlace();
	const double GetAverage();

	void Combine(LinkedList& L1, LinkedList& L2);//链表递增合并到L1，将L2归空
	void AntiCombine(LinkedList& L1, LinkedList& L2);//链表递减合并到L1，将L2归空
	void Antitone(LinkedList& L1);//链表反序
	void DeleteAB(LinkedList& L1,int Mink,int Maxk);
	void DifferenceSet(const LinkedList& L1,const LinkedList& L2, LinkedList& L3);//求L1和L2差集
	void RankFreq(LinkedList& L);//按freq倒序排序
	void Locate(LinkedList& L, int X);
										
	//const Node* operator[] (int index)const;
	//Node* operator[](int index);


	//Node* Insert(const int& Data,int index);//插入在index处
};


void LinkedList::Clear() {
	while (Head) {
		Node* newHead = Head->Next;
		delete Head;
		Head = newHead;
	}
}

Node* LinkedList::Add(const int& Data) {
	Node* newNode = new Node(Data);

	if (!Tail)
		Head = Tail = newNode;
	else
	{
		Tail->Next = newNode;
		newNode->Prior = Tail;
		Tail = newNode;
	}

	return newNode;
}

const int LinkedList::GetCount() {
	int i = 0;
	for (Node* Count = this->Head; Count; Count = Count->Next)i++;
	return i;
}
const int LinkedList::GetThisCount(Node* This) {
	int i = 1;
	for (Node* Count = Head; (Count) && (Count != This); Count = Count->Next)i++;
	return i;
}
const int LinkedList::CheckMax() {
	int n = Head->Number;
	Node* This = nullptr;
	for (Node* Count = Head->Next; Count; Count = Count->Next) {
		if (n < Count->Number) {
			n = Count->Number;
			This = Count;
		}
	}
	return n;
}
const int LinkedList::CheckMaxPlace() {
	int n = Head->Number, i = 0;
	Node* This = nullptr;
	for (Node* Count = Head->Next; Count; Count = Count->Next) {
		if (n < Count->Number) {
			n = Count->Number;
			This = Count;
		}
	}
	i = GetThisCount(This);
	return i;
}
const double LinkedList::GetAverage() {
	double n = Head->Number;
	for (Node* Count = Head->Next; Count; Count = Count->Next) {
			n = n + Count->Number;
	}
	return n / (this->GetCount());
}

void LinkedList::Combine(LinkedList& L1, LinkedList& L2) {//将L1和L2按递增合并进L1，并把L2归空
	if (L1.Head && L2.Head) {
		Node* p = L1.Head, * q = L2.Head;
		if (p->Number > q->Number) {
			L1.Head = q;
			q->Next->Prior = q;
			q = q->Next;
			q->Prior->Next = p;
		}
		while (p->Next || q->Next) {
			while (p->Next && q->Next) {
				if (p->Number <= q->Number) {
					p->Next->Prior = p;
					p = p->Next;
				}
				else {
					p->Prior->Next = q;
					q->Next->Prior = q;
					q = q->Next;
					q->Prior->Next = p;
				}
			}
			while (!p->Next && q->Next) {//p是最后一位，q不是
				if (p->Number <= q->Number) {
					p->Next = q;
					L1.Tail = q;
					break;
				}
				else {
					p->Prior->Next = q;
					q->Next->Prior = q;
					q = q->Next;
					q->Prior->Next = p;
				}

			}
			while (p->Next && !q->Next) {//q是最后一位，p不是
				if (p->Number <= q->Number) {
					p->Next->Prior = p;
					p = p->Next;
				}
				else {
					p->Prior->Next = q;
					q->Next = q;
					break;
				}
			}
			break;
		}
		if (p->Number <= q->Number) {//都是最后一位
			p->Next = q;
			L1.Tail = q;
		}
		else {
			p->Prior->Next = q;
			q->Next = q;
		}
	}
	else {
		if (!L1.Head)L1.Head = L2.Head;
	}
	L2.Head = nullptr;
}

void LinkedList::Antitone(LinkedList& L1) {
	Node* Temphead = L1.Head;
	Node* Temptail = L1.Tail;
	for (; Temphead->Next; Temphead = Temphead->Next) {
		Temphead->Next->Prior = Temphead;
	}
	for (; Temptail->Prior; Temptail = Temptail->Prior) {
		Temptail->Next = Temptail->Prior;
	}
	Temptail->Next = nullptr;
	Temphead = L1.Head;
	Temptail = L1.Tail;
	L1.Head = Temptail;
	L1.Tail = Temphead;
}

void LinkedList::AntiCombine(LinkedList& L1, LinkedList& L2) {//将L1和L2按递增合并进L1，并把L2归空
	L1.Combine(L1, L2);
	Antitone(L1);
}

void LinkedList::DeleteAB(LinkedList& L1, int Mink, int Maxk) {
	Node* Count = L1.Head;
	do {
		if (Count == L1.Head && Count->Number<Maxk && Count->Number>Mink) {
			if (Count->Next) {
				L1.Head = Count->Next;
				delete Count;
				Count = L1.Head;
			}
			else {
				delete Count;
				L1.Head = nullptr;
				Count = nullptr;
			}
		}
		else {
			if (Count!=nullptr&&Count->Number<Maxk && Count->Number>Mink) {
				Count->Prior->Next = Count->Next;
				Count->Next->Prior = Count->Prior;
				Node* Temp = Count->Next;
				delete Count;
				Count = Temp;
			}
			else {
				Count = Count->Next;
			}
		}
	} while (Count != nullptr);
}

void LinkedList::DifferenceSet(const LinkedList& L1, const LinkedList& L2, LinkedList& L3) {
	Node* Count1 = L1.Head;
	while (Count1) {
		for (Node* Count2 = L2.Head; Count2; Count2 = Count2->Next) {
			if (Count1->Number == Count2->Number) {
				L3.Add(Count1->Number);
				break;
			}
		}
		Count1 = Count1->Next;
	}
}

void LinkedList::RankFreq(LinkedList& L) {
	for (int i = 1; i <= L.GetCount(); i++) {
		for (Node* p = L.Head; p && p->Next;) {
			if (p == L.Head)
				if (p->Next->Freq > p->Freq) {
					L.Head = p->Next;
					if (p->Next->Next) {
						p->Next->Next->Prior = p;
						p->Prior = p->Next;
						p = p->Next;
						p->Prior->Next = p->Next;
						p->Next = p->Prior;
						p->Prior = nullptr;
						p = p->Next;
					}
					else {
						L.Head = p->Next;
						p->Prior = p->Next;
						p = p->Next;
						p->Next = p->Prior;
						p->Prior->Next = nullptr;
						p->Prior = nullptr;
						L.Tail = p->Next;
					}
				}
				else p = p->Next;
			else {
				if (p->Next->Freq > p->Freq) {
					if (p->Next->Next) {
						p->Prior->Next = p->Next;
						p->Next->Prior = p->Prior;
						p->Prior = p->Next;
						p->Next = p->Next->Next;
						p->Next->Prior->Next = p;
						p->Next->Prior = p;
						p = p->Next;
					}
					else {
						p->Prior->Next = p->Next;
						p->Next->Prior = p->Prior;
						p->Prior = p->Next;
						p->Next->Next = p;
						p->Next = nullptr;
						L.Tail = p;
					}
				}
				else p = p->Next;
			}
		}
	}
}
void LinkedList::Locate(LinkedList& L, int X) {
	for (Node* p = L.Head; p ;p=p->Next) {
		if (p->Number == X)p->Freq++;
	}
	L.RankFreq(L);
}


ostream& operator << (ostream& o, const LinkedList& list)
{
	if (list.GetHead() != nullptr) {
		for (const Node* p = list.GetHead();
			p;
			p = p->GetNext())
		{
			o << "[" << p->GetNumber() << "]";

			if (p->GetNext())
				o << " -> ";
		}
	}
	else {
		o << "This list is empty.";
	}
	return o;
}

int main()
{
	LinkedList Mylist1;
	Mylist1.Add(1);
	Mylist1.Add(2);
	Mylist1.Add(7);
	Mylist1.Add(16);
	Mylist1.Add(22);
	
	/*LinkedList Mylist2;
	Mylist2.Add(1);
	Mylist2.Add(7);
	Mylist2.Add(16);
	Mylist2.Add(23);
	Mylist2.Add(44);*/


	cout << "Mylist1 is" << endl;
	cout << Mylist1 << endl;
	cout << Mylist1.CheckMax()<<endl;
	cout << Mylist1.GetCount() << endl;
	cout << Mylist1.GetAverage() << endl;
	
	/*Mylist1.Locate(Mylist1,2);
	cout << "Locate(Mylist1,2)" << endl;
	cout << Mylist1 << endl;
	Mylist1.Locate(Mylist1, 7);
	cout << "Locate(Mylist1,7)" << endl;
	Mylist1.Locate(Mylist1, 7);
	cout << "Locate(Mylist1,7)" << endl;
	cout << Mylist1 << endl;
	Mylist1.Locate(Mylist1, 16);
	cout << "Locate(Mylist1,16)" << endl;
	Mylist1.Locate(Mylist1, 16);
	cout << "Locate(Mylist1,16)" << endl;
	cout << Mylist1 << endl;
	cout << "Mylist2 is" << endl;
	cout << Mylist2 << endl;*/

	/*Mylist1.DeleteAB(Mylist1, 2, 9);//删除大于2小于9的数
	cout <<"Delete from 2 to 9"<<endl << "Mylist1 is" << endl << Mylist1 << endl;
	Mylist1.DeleteAB(Mylist1, 0, 10);//删除大于0小于10的数
	cout << "Delete from 0 to 10" << endl << "Mylist1 is" << endl << Mylist1 << endl;
	Mylist1.DeleteAB(Mylist1, 0, 90);//删除大于0小于90的数
	cout << "Delete from 0 to 90" << endl << "Mylist1 is" << endl<< Mylist1 << endl;*/
	
	/*LinkedList DifferenceSet1;
	Mylist1.DifferenceSet(Mylist1, Mylist2, DifferenceSet1);
	int n = DifferenceSet1.GetCount();
	cout << "DifferenceSet1 is" << endl;
	cout << DifferenceSet1 << endl;
	cout << "The number of DifferenceSet1 is" << endl;
	cout << n << endl;*/

	//Mylist1.AntiCombine(Mylist1, Mylist2);
	/*/cout << "Mylist is" << endl;
	cout << Mylist1 << endl;
	Mylist1.Antitone(Mylist1);
	cout << Mylist1 << endl;
	cout << "The length is  " << Mylist.GetCount()<< endl;
	cout << "The maxnumber is at  " << Mylist.CheckMaxPlace() << endl;*/
}

