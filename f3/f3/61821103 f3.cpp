//定义两列统计数据量化指标类 VecCorrelation ，计算和输出两个变量的相关性。

#include<iostream>
#include<cmath>
#include "string"
using namespace std;


class VecCorrelation {
	double* dataset1, * dataset2;   //两列变量的统计数据向量
	int count;						//有效数据的个数
	int maxSize;					//每列向量最大可存储元素个数，

	double mean1;					//第一列向量的平均值
	double mean2;					//第二列向量的平均值
	double correlationvalue;		//两列向量的相关系数
	double deviation1;				//第一列向量的标准差
	double deviation2;				//第二列向量的标准差
public:
	VecCorrelation(int maxs=2) ;										//构造函数
	VecCorrelation(const VecCorrelation& vecs);						//拷贝（复制）构造函数
	~VecCorrelation() ;												//析构函数

	void SetData(double array1[], double array2[], int len);		//更新两列变量的统计数据向量
	void CalMeanDeviation();										//计算两列数据各自的平均值、标准差和相关系数
	VecCorrelation  operator+(const VecCorrelation& vecs);			//合并两组统计数据

	//添加代码：补充所需的成员函数或友元函数（4分）
	
	VecCorrelation& operator=(const VecCorrelation& vecs);
	
	friend ostream& operator<<(ostream& output, const VecCorrelation& obj);
};

VecCorrelation::VecCorrelation(int maxs)
{
	maxSize = maxs;
	dataset1 = new double[maxSize];
	dataset2 = new double[maxSize];
	count = 0;
	correlationvalue = mean1 = mean2 = 0;

}

VecCorrelation::VecCorrelation(const VecCorrelation& vecs)
{

	maxSize = vecs.maxSize;
	dataset1 = new double[maxSize];
	dataset2 = new double[maxSize];

	count = vecs.count;
	for (int i = 0; i < count; i++)
	{
		dataset1[i] = vecs.dataset1[i];
		dataset2[i] = vecs.dataset2[i];
	}
	CalMeanDeviation();
}


//+ 运算符重载：合并两组数据
VecCorrelation  VecCorrelation::operator+(const VecCorrelation& vecs)
{
	VecCorrelation result;
	delete[]result.dataset1;
	delete[]result.dataset2;
	int i;
	result.maxSize = vecs.maxSize + maxSize;
	result.dataset1 = new double[result.maxSize];
	result.dataset2 = new double[result.maxSize];

	for (i = 0; i < count; i++)
	{
		result.dataset1[i] = dataset1[i];
		result.dataset2[i] = dataset2[i];
	}

	for (i = 0; i < vecs.count; i++)
	{
		result.dataset1[count + i] = vecs.dataset1[i];
		result.dataset2[count + i] = vecs.dataset2[i];
	}

	result.count = vecs.count + count;
	result.CalMeanDeviation();

	return result;
}

void VecCorrelation::SetData(double array1[], double array2[], int len)
{
	if (maxSize < len)
	{
		delete[]dataset1;
		delete[]dataset2;

		maxSize = len;
		dataset1 = new double[maxSize];
		dataset2 = new double[maxSize];
	}
	count = len;

	for (int i = 0; i < len; i++)
	{
		dataset1[i] = array1[i];
		dataset2[i] = array2[i];
	}
	CalMeanDeviation();
}

//计算平均值、标准差、协方差和相关系数
void VecCorrelation::CalMeanDeviation()
{
	double sum1 = 0, sum2 = 0, sum3 = 0;

	for (int i = 0; i < count; i++)
	{
		sum1 += dataset1[i];
		sum2 += dataset2[i];
	}
	mean1 = sum1 / count;						//计算平均值
	mean2 = sum2 / count;

	sum1 = 0; sum2 = 0; sum3 = 0;
	for (int i = 0; i < count; i++)
	{
		sum1 += (dataset1[i] - mean1) * (dataset1[i] - mean1);
		sum2 += (dataset2[i] - mean2) * (dataset2[i] - mean2);
		sum3 += (dataset1[i] - mean1) * (dataset2[i] - mean2);
	}

	deviation1 = sqrt(sum1 / count);			//计算标准差
	deviation2 = sqrt(sum2 / count);

	//添加代码：计算协方差和相关系数（4分）
	double dxy = sum3 / (count * 1.0);
	correlationvalue = dxy / (deviation1 * deviation2);
}

VecCorrelation::~VecCorrelation()
{
	//添加代码：完善析构函数（4分）	
	delete[]dataset1;
	delete[]dataset2;
}

//添加代码，实现所需的成员函数或友元函数（13分）
VecCorrelation& VecCorrelation::operator=(const VecCorrelation& vecs) {
	maxSize = vecs.maxSize;
	dataset1 = new double[maxSize];
	dataset2 = new double[maxSize];

	count = vecs.count;
	for (int i = 0; i < count; i++)
	{
		dataset1[i] = vecs.dataset1[i];
		dataset2[i] = vecs.dataset2[i];
	}
	CalMeanDeviation();
	return *this;
}

ostream& operator<<(ostream& output, const VecCorrelation& obj)
{
	cout << "数据1平均值：" << obj.mean1 << " 数据2平均值：" << obj.mean2 << endl;
	cout << "数据1标准差：" << obj.deviation1 << " 数据2标准差：" << obj.deviation2 << endl;

	output << "两个数据集的相关性为： " << obj.correlationvalue;

	//添加代码：根据相关系数correlationvalue的值，依据题目中的说明，输出从"强负相关"到"强正相关"的判断信息
	if (obj.correlationvalue <= -0.6)cout << "  强负相关" << endl;
	else if (obj.correlationvalue > -0.6 && obj.correlationvalue <= -0.2)cout << "  一般负相关" << endl;
	else if (obj.correlationvalue > -0.2 && obj.correlationvalue <= 0.2)cout << "  不相关" << endl;
	else if (obj.correlationvalue > 0.2 && obj.correlationvalue <= 0.6)cout << "  一般正相关" << endl;
	else if (obj.correlationvalue > 0.6)cout << "  强正相关" << endl;
	output << endl;
	return output;
}

int main()
{
	VecCorrelation data1, data2, data3;
	//利用数组a,b生成并输出data1
	double a[10] = { 169, 154, 170, 173, 160, 181, 157, 172, 171, 163 };
	double b[10] = { 65,50,55,79,57,74,48,60,64,63 };
	data1.SetData(a, b, 10);
	cout << data1 << endl;
	//利用数组c,d生成data2
	double c[3] = { 167,171, 180 };
	double d[3] = { 67, 72, 74 };
	data2.SetData(c, d, 3);
	//合并data1,data2,生成并输出data3
	data3 = data2 + data1;
	cout << data3 << endl;

	return 0;
}
