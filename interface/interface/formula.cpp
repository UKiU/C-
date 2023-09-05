#include "formula.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define N_A 6.02E23              //阿伏伽德罗常数
#define PI acos((double)-1)    //圆周率
using namespace std;

//生成0-1之间的一个随机数
double rand01()
{
	int temp = rand();
	double result = double(temp%100000)/100000.0;
	return result;
}
//修正bethe公式计算平均能量损失率

double BetheFx(double E, substrate Sub)
{
	double result, temp;
	temp = log (( 1.166 * E + Sub.k*Sub.J*1e-3)/(Sub.J*1e-3)  ) ;
	result = 7.85E4 * Sub.density * 1e21*Sub.Z / Sub.A / E * temp;
	return result;
}//结果为Kev/cm

//散射自由程
double ScatterFR(double A, double St, double D){
	double average, result;
	average = A / N_A / D / St;
	double temp;
	temp=rand01();
	result = -1.0 * average * log(temp);
	return result;
}//计算结果为nm
//方位角
double Azimuth(){
	double result;
	double temp=rand01();
	result = temp * 2 * PI;
	return result;
}
//散射后剩余能量
double EnergyRemain(double E, double dEds, double FRn){
	double result;
	result = E - (dEds * FRn*1e-7);
	return result;
}
//高能电子Rutherford公式计算散射截面
double RutherfordFx(double beta, double E, double Z)
{
	double result;
	result = (PI*pow(1.44,2)*Z*(Z+1)*(1e-6))/(4 * E * E * beta * (beta + 1));//计算结果为nm^2
	return result;
}

template<typename T>
void integer<T>::integrate()
{
	step=(b-a)/n;
	result=(cf.fun(a)+cf.fun(b))/2;
	for(int i=1;i<n;i++)
	{
		result+=cf.fun(a+i*step);
	}
	result*=step;
}
double scatterang(double Z,double E)
{
	int i;
	double step=PI/100000,R,division;
	R=rand01();
	integer<ftheta>
		integerdown(0.0,PI,100000,E,Z);
	integer<ftheta>
		integerup(0.0,0.0,100000,E,Z);

	for(i=1;i<integerup.n;i++)
	{
		integerup.result+=integerup.cf.fun(integerup.a+i*step)*step;
		division=integerup.result/integerdown.result;
		//cout<<division<<endl;
		if((fabs(division-R)/R)<0.0001||(division>R))
			break;
	}
	return(i*step);
}





//初始化基底材料
void subinitialize(substrate &Sub, double Width, double Length, double Density, int Cnum, int Hnum, int Onum)      
{
	//宽度、长度、密度
	Sub.width = Width;
	Sub.length = Length;
	Sub.density = Density;

	//C、H、O原子个数
	Sub.C = Cnum;
	Sub.H = Hnum;
	Sub.O = Onum;

	//平均原子量
	double Ac = 12, Ah = 1, Ao = 16;
	double Cc=0.6,Ch=0.08,Co=0.32;
	double down = (Cc / Ac) + (Ch / Ah) + (Co / Ao);
	Sub.A = 1.0 / down;

	//平均原子序数
	double Zc = 6, Zh = 1, Zo = 8;
	double up = (Cc * Zc / Ac) + (Ch * Zh / Ah) + (Co * Zo / Ao);
	Sub.Z = up / down;

	//添加平均电离能(单位ev)
	double Jc = 78, Jh = 18.7, Jo = 89;
	double upp = (Cc * Zc / Ac) * log(Jc) + (Ch * Zh / Ah) * log(Jh) + (Co * Zo / Ao) * log(Jo);
	Sub.J = exp(upp / up);

	//添加修正系数k
	double KAl = 0.815, Kc = 0.77, ZAl = 13;
	Sub.k = Kc - ((KAl - Kc) * (Zc - Sub.Z)) / (ZAl - Zc);
}
//初始化电子
void einitialize(epos &Epos, substrate Sub, double Enegry)          
{
	//能量
	Epos.E = Enegry;

	//原子屏蔽参量
	Epos.beta = 5.43E-3 * pow(Sub.Z, 2.0/3.0) / Enegry;

	//散射截面
	Epos.crossection = RutherfordFx(Epos.beta, Enegry, Sub.Z);

	//散射自由程
	Epos.freelength = ScatterFR(Sub.A, Epos.crossection, Sub.density);

	//散射角
	Epos.scatterangle=scatterang(Sub.Z,Enegry);

	//方位角
	Epos.azimuth=Azimuth();
}
//初始电子坐标
void XYinitialize(epos &Epos, double R)
{
	double R1 = rand01();
	double R2 = rand01();
	double temp = sqrt(-1 * log(R1));
	Epos.coordinate[0] = R * temp * cos(2 * PI * R2);
	Epos.coordinate[1]= R * temp * sin(2 * PI * R2);
	Epos.coordinate[2]=0;
}
//单位为nm

bool outofrange(epos Epos,substrate sub)
{
	if((Epos.coordinate[0]>sub.width)||(Epos.coordinate[1]>sub.width)||(Epos.coordinate[2]>sub.length))return 1;
	else return 0;
}