#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

#define _G(col, row) this->map[(row) * this->wide + (col)]

void gotoxy(int x, int y)//�Լ�����һ��gotoxy�����������x��y�� 
{
	COORD c;    //����һ�������
	c.X = x;	//�����������λ��
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);   //����WindowsAPI�����ù��λ��
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

class Game {
public:
	int* map;
	int wide;
	int height;
	void PutApple()
	{
		for (;;)
		{
			int x = rand(1, this->wide - 1);
			int y = rand(1, this->height - 1);

			if (_G(x, y))
				continue;

			_G(x, y) = -9;
			break;
		}
	}

	void Init()
	{
		for (int y = 0; y < this->height; ++y)
			for (int x = 0; x < this->wide; ++x)
			{
				//this->map[y * this->wide + x] = 0;
				_G(x, y) = 0;
			}

		for (int y = 0; y < this->height; y += 2)
			for (int x = 0; x < this->wide; x += 2)
			{
				//this->map[y * this->wide + x] = 0;
				_G(x, y) = -2;
			}

		for (int y = 0; y < this->height; ++y)
		{
			_G(0, y) = -1;
			_G(this->wide - 1, y) = -1;
		}

		for (int x = 0; x < this->wide; ++x)
		{
			_G(x, 0) = -1;
			_G(x, this->height - 1) = -1;
		}

		//����
		int s = this->wide / 2 - 1;
		int t = this->height / 2;
		if (t % 2 == 0) t--;
		_G(s, t) = 1;
		_G(s + 1, t) = 2;
		_G(s + 2, t) = 3;

		this->PutApple();
		this->PutApple();
		this->PutApple();
	}

	bool Move()
	{
		//Find Head
		int hx, hy;
		for (int y = 0; y < this->height; ++y)
			for (int x = 0; x < this->wide; ++x)
				if (_G(x, y) == 1)
				{
					hx = x; hy = y;
				}

		int tx, ty;
		for (int y = 0; y < this->height; ++y)
			for (int x = 0; x < this->wide; ++x)
				if (_G(x, y) == 3)
				{
					tx = x; ty = y;
				}

		//next Step
		int nx, ny, bx, by;
		while (true)
		{
			if (rand(2))
			{
				int a = rand(2);
				nx = hx + (a ? 1 : -1);
				ny = hy;
				bx = hx - (a ? 1 : -1);
				by = hy;

			}
			else
			{
				int a = rand(2);
				nx = hx;
				ny = hy + (a ? 1 : -1);
				bx = hx;
				by = hy - (a ? 1 : -1);
			}
			if ((_G(nx, ny) == 2 || _G(nx, ny) == 3) && (_G(bx, by) == 2 || _G(bx, by) == 3))return false;
			if (_G(nx, ny) == -9)break;

			if (_G(nx, ny)) continue;
			else break;
		}

		//tnx
		int tnx, tny;
		if (_G(tx - 1, ty) == 2) { tnx = tx - 1; tny = ty; }
		if (_G(tx + 1, ty) == 2) { tnx = tx + 1; tny = ty; }
		if (_G(tx, ty - 1) == 2) { tnx = tx; tny = ty - 1; }
		if (_G(tx, ty + 1) == 2) { tnx = tx; tny = ty + 1; }

		//moveHead
		if (_G(nx, ny) == -9)
		{
			_G(nx, ny) = 1;
			_G(hx, hy) = 2;

			this->PutApple();
			this->PutApple();
		}
		else
		{
			_G(nx, ny) = 1;
			_G(hx, hy) = 2;
			_G(tnx, tny) = 3;
			_G(tx, ty) = 0;
		}

		return true;
	}

	void Print()
	{
		gotoxy(0, 0);

		for (int y = 0; y < this->height; ++y)
		{
			for (int x = 0; x < this->wide; ++x)
			{
				switch (_G(x, y))
				{
				case 0:  cout << "  "; break;
				case -1: color(3);  cout << "ǽ"; break;
				case -2: color(8);  cout << "ǽ"; break;
				case -9: color(4);  cout << "��"; break;


				case 1:  color(6);  cout << "ͷ"; break;
				case 2:  color(6);  cout << "��"; break;
				case 3:  color(6);  cout << "β"; break;

				}
			}
			cout << endl;
		}
	}

};

int main()
{
	Game g;
	g.wide = 41;
	g.height = 21;
	g.map = new int[g.wide * g.height];

	srand(time(0));

	//int g.wide = 41;
	//int g.height = 21;

	//int* g.map = new int[g.wide * g.height];

	g.Init();


	for (long long i = 0; g.Move(); ++i)
	{
		g.Print();
		if (i % 50 == 0)
			g.PutApple();
		Sleep(20);
		//break;
	}

	cout << "GAME OVER" << endl;

	delete[]g.map ;
}
