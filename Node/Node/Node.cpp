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
	
	Node(const T& newData);//ȱʡ��������������дȫ��

	
};

template<typename T>
class List //���������
{
private:
	Node* head;//ͷָ��
	Node* tail;//βָ��

public:
	List() //��ʼ��Ϊ��ָ��
	{
		tail = nullptr;
		head = nullptr;
	}

	Node<T>* Add(const T& newData); //�з���ֵʱҪ����T
	Node<T>* InsertFront(const T& newData);
	Node<T>* Insert(const T& newData);




};

template<typename T>
Node<T>* List<T>::Add(const T& newData)//ǰһ���Ǻ�������ֵ���ͣ���һ����������
{
	Node<T>* newNode = new Node<T>(newData);

	if (!tail)
		head = tail = newNode;
	else
	{	
		tail->next = newNode;
		tail = newNode;//���ܵߵ�,��B��A
	}

}


template<typename T>
Node<T>* List<T>::InsertFront(const T& newData);


template<typename T>
Node<T>* List<T>::Insert(const T& newData);


template<typename T>
Node<T>::Node(const T& newData) //Node��ֻ�и���ģ��Ŵ��ڣ����캯��ֻ��������
{ 
	this->data = newData;
	next = nullptr; //��ָ��
}