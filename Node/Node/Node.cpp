#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

template<typename T>
class Node 
{
private:
	T data;
	Node* next;
public:
	
	Node(const T& newData);//缺省构造类内声明，写全局

	
};

template<typename T>
class List //链表管理器
{
private:
	Node* head;//头指针
	Node* tail;//尾指针

public:
	List() //初始化为空指针
	{
		tail = nullptr;
		head = nullptr;
	}

	Node<T>* Add(const T& newData); //有返回值时要给定T
	Node<T>* InsertFront(const T& newData);
	Node<T>* Insert(const T& newData);




};

template<typename T>
Node<T>* List<T>::Add(const T& newData)//前一个是函数返回值类型，后一个是声明类
{
	Node<T>* newNode = new Node<T>(newData);

	if (!tail)
		head = tail = newNode;
	else
	{	
		tail->next = newNode;
		tail = newNode;//不能颠倒,先B后A
	}

}


template<typename T>
Node<T>* List<T>::InsertFront(const T& newData);


template<typename T>
Node<T>* List<T>::Insert(const T& newData);


template<typename T>
Node<T>::Node(const T& newData) //Node类只有给定模板才存在，构造函数只需声明类
{ 
	this->data = newData;
	next = nullptr; //空指针
}