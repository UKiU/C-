#include<iostream>
using namespace std ;

template<typename T>
class ArrayList {
private:
	T* arr;
	int Count;
	int Capacity;

public:
	ArrayList(int Capacity = 1024) :Count(0),Capacity(Capacity) 
	{
		
	}

	ArrayList()
};

template<typename T>
ostream& operator <<(ostream& o, ArrayList<T> t) {
	
}

template<typename T>
class Stack :public ArrayList<T> { //�̳У���ArrayList�е��������ݺ͹���
	//ArrayList<T>�ǻ���(����)�����Stack��������(������)
	//��������ݺ͹��ܶ�Ҫ��this



};