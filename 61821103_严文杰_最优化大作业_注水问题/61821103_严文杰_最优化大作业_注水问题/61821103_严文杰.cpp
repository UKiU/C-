#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define Dimension 10 //ά��
#define Precision 1.0e-6 //����

//��ӡ����alpha
void print_alpha(double *a){
	for (int i = 0; i < Dimension; i++) {
		cout << "Alpha [" << i << "] = " << a[i] << endl;
	}
}
//���ɲ���ӡ����X�����Ż�ֵ
void print_x(double *a,double line){
	//��������lineΪעˮ�߸߶�,��1/V
	double min = 0;
	for (int i = 0; i < Dimension; i++) {
		if (line - a[i] >= 0) {
			cout << "X [" << i << "] = " << line - a[i] << endl;
			min +=-log(line);
		}
		else {
			cout << "X [" << i << "] = " << 0 << endl;
			min += -log(a[i]);
		}
	}
	cout << "water_line = " << line << endl;
	cout << "minimize = " << min << endl;
}
//����0-1֮����������
void random(double* a) {
	for (int i = 0; i < Dimension; i++) {
		a[i] = (double)rand() / RAND_MAX;
	}
}
//�ⷽ��
double caculate_target(double* alpha, double line) {
	double sum_temp = 0;
	for (int i = 0; i < Dimension; i++) {
		if (line - alpha[i] < 0)sum_temp += 0;
		else {
			sum_temp += line - alpha[i];
		}
	}
	return sum_temp;
}
//��עˮ����
double fill_water(double* alpha, double total_water, double precision) {
	int step = 1;//��������
	double line = 0, pre=0.1;//lineΪעˮ�߸߶ȣ���1/V��preΪ����
	double last_dif = 0;//��һ�εĲ�ֵ
	double sum = caculate_target(alpha, line);//����������
	double cur_dif = sum - total_water;//�˿̲�ֵ
	
	//����δ���������ֵ���ھ��ȣ�
	while (abs(cur_dif) > Precision) {
		if (last_dif != 0 && last_dif * cur_dif < 0 && pre>1.0e-7) {
			//��ʾ������˺ʹ�С��total_water������total_water��ת�۵�
			//������ε�line���ϴε�line֮��
			//����������С
			pre /= 10;
			step *= (-1);
		}
		//��¼��ֵ�������ƽ�
		last_dif = cur_dif;
		line += step * pre;
		sum = caculate_target(alpha, line);
		cur_dif = sum - total_water;
	}

	//�����ѽ��������ֵС�ھ��ȣ�
	if (abs(cur_dif) <= Precision) {
		print_x(alpha, line);
		return 1/line;//����עˮ�߸߶ȵĵ���
	}

}

int main() {
	srand(time(0));//�����������
	double alpha[Dimension];//��������
	double total_water = 1;
	random(alpha);
	print_alpha(alpha);
	double water_line = fill_water(alpha, total_water, Precision);
}