#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y)//自己定义一个gotoxy，将光标跳到x列y行 
{
	COORD c;    //定义一个光标类
	c.X = x;	//设置这个光标的位置
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);   //调用WindowsAPI来设置光标位置
}

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int inline rand(int Min, int Max)
{
	return rand() % (Max - Min) + Min;
}

int inline rand(int Max)
{
	return rand() % Max;
}

struct CanvasDot
{
	char chr;
	int clr;
};

class Canvas
{
	int w;
	int h;
	CanvasDot* arr;
public:
	Canvas(int w, int h) :w(w), h(h)
	{
		arr = new CanvasDot[w * h];
		Clear();
	}

	void SetLine(const char* str, int x, int y, int color)
	{
		for (const char* s = str; *s; ++s, ++x)
		{
			if (x < 0) continue;
			if (x >= w) break;
			if (y < 0) return;
			if (y >= h) return;

			int id = y * w + x;
			arr[id].chr = *s;
			arr[id].clr = color;
		}
	}

	void Clear()
	{
		int s = w * h;
		for (int i = 0; i < s; ++i)
		{
			arr[i].chr = ' ';
			arr[i].clr = 15;
		}
	}

	void Draw()
	{
		int id = 0;
		color(0);
		int lc = 0;
		for (int y = 0; y < h; ++y)
		{
			gotoxy(0, y);
			for (int x = 0; x < w; ++x, ++id)
			{
				if (lc != arr[id].clr)
				{
					color(arr[id].clr);
					lc = arr[id].clr;
				}
				cout << arr[id].chr;
			}
		}
	}

	~Canvas()
	{
		delete[] arr;
	}
};

class Object
{
protected:
	int x;
	int y;
	int color;

public:
	Object(int x = 0, int y = 0, int color = 0) : x(x), y(y), color(color) {}

	virtual void Draw(Canvas& cnv) = 0;

	virtual void Move(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
};


class Cabbage : public Object
{
public:
	Cabbage(int x, int y) : Object(x, y, 14) {}

	string s1 = " (((\\))/)) ";
	string s2 = "((\\)))/ ";
	string s3 = "(((_))   ";


	void Draw(Canvas& cnv)
	{
		cnv.SetLine(s1.c_str(), x, y, color);
		cnv.SetLine(s2.c_str(), x + 2, y + 1, color);
		cnv.SetLine(s3.c_str(), x + 2, y + 2, color);
	}

	void Move(int dx, int dy)
	{
		Object::Move(dx, dy);

		if (s1 == " (((\\))/)) ")
			s1 = "( ((\\))/) )";
		else
			s1 = " (((\\))/)) ";
	}
};

class Flower : public Object
{
public:
	Flower(int x, int y) : Object(x, y, 12) {}


	void Draw(Canvas& cnv)
	{
		cnv.SetLine("(  )", x + 3, y, color);
		cnv.SetLine("(  )OO(  )", x, y + 1, color);
		cnv.SetLine("(  )", x + 3, y + 2, color);
	}
};

template <typename T>
void Sort(T* arr, int size)
{
	int id = 0;
	while (id < size - 1)
	{
		if (arr[id] > arr[id + 1])
		{
			T t = arr[id];
			arr[id] = arr[id + 1];
			arr[id + 1] = t;
			if (id > 0)
				--id;
		}
		else
			++id;
	};
}



int main()
{
	int A[] = { 3, 38, 4,1,31, 2,6,23,78, 81, 19 };
	int s = sizeof(A) / sizeof(int);
	Sort(A, s);
	for (int i = 0; i < s; ++i)
		cout << A[i] << " ";

	system("pause");


	srand(time(0));

	Object* objects[10];
	Canvas cnv(70, 20);


	for (int i = 0; i < 10; ++i)
		objects[i] = (i % 2) ?
		(Object*)new Cabbage(rand(60), rand(15)) :
		(Object*)new Flower(rand(60), rand(15));

	Sort(objects, 10);

	for (int i = 0; i < 10; ++i)
		cout << objects[i] << endl;
	system("pause");

	for (int i = 0; i < 60; ++i)
	{
		for (int j = 0; j < 10; ++j)
			if (typeid(*objects[j]) == typeid(Cabbage))
				objects[j]->Move(1, 0);
			else
				objects[j]->Move(-1, 0);

		cnv.Clear();
		for (int i = 0; i < 10; ++i)
			objects[i]->Draw(cnv);
		cnv.Draw();

		::Sleep(200);
	}

	gotoxy(0, 21);
	cout << "GAME OVER";
	return 0;
}


