#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define Dimension 10 //维度
#define Precision 1.0e-6 //精度

//打印数组alpha
void print_alpha(double *a){
	for (int i = 0; i < Dimension; i++) {
		cout << "Alpha [" << i << "] = " << a[i] << endl;
	}
}
//生成并打印数组X、最优化值
void print_x(double *a,double line){
	//传进来的line为注水线高度,即1/V
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
//生成0-1之间的随机数组
void random(double* a) {
	for (int i = 0; i < Dimension; i++) {
		a[i] = (double)rand() / RAND_MAX;
	}
}
//解方程
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
//解注水问题
double fill_water(double* alpha, double total_water, double precision) {
	int step = 1;//步长方向
	double line = 0, pre=0.1;//line为注水线高度，即1/V，pre为步长
	double last_dif = 0;//上一次的差值
	double sum = caculate_target(alpha, line);//方程左端求和
	double cur_dif = sum - total_water;//此刻差值
	
	//方程未解出来（差值大于精度）
	while (abs(cur_dif) > Precision) {
		if (last_dif != 0 && last_dif * cur_dif < 0 && pre>1.0e-7) {
			//表示方程左端和从小于total_water到大于total_water的转折点
			//答案在这次的line和上次的line之间
			//步长反向并缩小
			pre /= 10;
			step *= (-1);
		}
		//记录差值，步步逼近
		last_dif = cur_dif;
		line += step * pre;
		sum = caculate_target(alpha, line);
		cur_dif = sum - total_water;
	}

	//方程已解出来（差值小于精度）
	if (abs(cur_dif) <= Precision) {
		print_x(alpha, line);
		return 1/line;//返回注水线高度的倒数
	}

}

int main() {
	srand(time(0));//生成随机种子
	double alpha[Dimension];//生成数组
	double total_water = 1;
	random(alpha);
	print_alpha(alpha);
	double water_line = fill_water(alpha, total_water, Precision);
}