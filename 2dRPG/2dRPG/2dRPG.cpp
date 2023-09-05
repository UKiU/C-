#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string>
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

:Object(x,y,10)//将信息传给基类
'((\\))/))'//其中\\的第一个是转义符
::color//作用于全局
typeid//类型编号
c_str()//获得c风格的字符串（char）；