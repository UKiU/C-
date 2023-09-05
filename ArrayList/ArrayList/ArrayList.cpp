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
class Stack :public ArrayList<T> { //继承，用ArrayList中的所有数据和功能
	//ArrayList<T>是基类(或父类)，这个Stack是派生类(或子类)
	//基类的数据和功能都要加this



};