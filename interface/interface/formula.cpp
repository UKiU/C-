#include "formula.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define N_A 6.02E23              //����٤���޳���
#define PI acos((double)-1)    //Բ����
using namespace std;

//����0-1֮���һ�������
double rand01()
{
	int temp = rand();
	double result = double(temp%100000)/100000.0;
	return result;
}
//����bethe��ʽ����ƽ��������ʧ��

double BetheFx(double E, substrate Sub)
{
	double result, temp;
	temp = log (( 1.166 * E + Sub.k*Sub.J*1e-3)/(Sub.J*1e-3)  ) ;
	result = 7.85E4 * Sub.density * 1e21*Sub.Z / Sub.A / E * temp;
	return result;
}//���ΪKev/cm

//ɢ�����ɳ�
double ScatterFR(double A, double St, double D){
	double average, result;
	average = A / N_A / D / St;
	double temp;
	temp=rand01();
	result = -1.0 * average * log(temp);
	return result;
}//������Ϊnm
//��λ��
double Azimuth(){
	double result;
	double temp=rand01();
	result = temp * 2 * PI;
	return result;
}
//ɢ���ʣ������
double EnergyRemain(double E, double dEds, double FRn){
	double result;
	result = E - (dEds * FRn*1e-7);
	return result;
}
//���ܵ���Rutherford��ʽ����ɢ�����
double RutherfordFx(double beta, double E, double Z)
{
	double result;
	result = (PI*pow(1.44,2)*Z*(Z+1)*(1e-6))/(4 * E * E * beta * (beta + 1));//������Ϊnm^2
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





//��ʼ�����ײ���
void subinitialize(substrate &Sub, double Width, double Length, double Density, int Cnum, int Hnum, int Onum)      
{
	//��ȡ����ȡ��ܶ�
	Sub.width = Width;
	Sub.length = Length;
	Sub.density = Density;

	//C��H��Oԭ�Ӹ���
	Sub.C = Cnum;
	Sub.H = Hnum;
	Sub.O = Onum;

	//ƽ��ԭ����
	double Ac = 12, Ah = 1, Ao = 16;
	double Cc=0.6,Ch=0.08,Co=0.32;
	double down = (Cc / Ac) + (Ch / Ah) + (Co / Ao);
	Sub.A = 1.0 / down;

	//ƽ��ԭ������
	double Zc = 6, Zh = 1, Zo = 8;
	double up = (Cc * Zc / Ac) + (Ch * Zh / Ah) + (Co * Zo / Ao);
	Sub.Z = up / down;

	//���ƽ��������(��λev)
	double Jc = 78, Jh = 18.7, Jo = 89;
	double upp = (Cc * Zc / Ac) * log(Jc) + (Ch * Zh / Ah) * log(Jh) + (Co * Zo / Ao) * log(Jo);
	Sub.J = exp(upp / up);

	//�������ϵ��k
	double KAl = 0.815, Kc = 0.77, ZAl = 13;
	Sub.k = Kc - ((KAl - Kc) * (Zc - Sub.Z)) / (ZAl - Zc);
}
//��ʼ������
void einitialize(epos &Epos, substrate Sub, double Enegry)          
{
	//����
	Epos.E = Enegry;

	//ԭ�����β���
	Epos.beta = 5.43E-3 * pow(Sub.Z, 2.0/3.0) / Enegry;

	//ɢ�����
	Epos.crossection = RutherfordFx(Epos.beta, Enegry, Sub.Z);

	//ɢ�����ɳ�
	Epos.freelength = ScatterFR(Sub.A, Epos.crossection, Sub.density);

	//ɢ���
	Epos.scatterangle=scatterang(Sub.Z,Enegry);

	//��λ��
	Epos.azimuth=Azimuth();
}
//��ʼ��������
void XYinitialize(epos &Epos, double R)
{
	double R1 = rand01();
	double R2 = rand01();
	double temp = sqrt(-1 * log(R1));
	Epos.coordinate[0] = R * temp * cos(2 * PI * R2);
	Epos.coordinate[1]= R * temp * sin(2 * PI * R2);
	Epos.coordinate[2]=0;
}
//��λΪnm

bool outofrange(epos Epos,substrate sub)
{
	if((Epos.coordinate[0]>sub.width)||(Epos.coordinate[1]>sub.width)||(Epos.coordinate[2]>sub.length))return 1;
	else return 0;
}