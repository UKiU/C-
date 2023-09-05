//电商会员的积分统计及会员信息输出

#include <string>
#include <iostream>
using namespace std;

class Member
{
private:
	int      ID;				//会员编号
	string   Name;				//会员姓名
protected:
	int      MemberPoint;		//会员积分

public:
	Member(int id = 0, string name = "", int point = 0) :
		ID(id), Name(name), MemberPoint(point) {}
	virtual void print()
	{
		cout << "ID: " << ID << ", Name : " << Name << ", MemberPoint: " << MemberPoint;
	}

	//添加代码：定义Member类的AddPoint成员函数（3分）
	void AddPoint(int Consumption) {
		MemberPoint += Consumption;
	}
};

class VIPMember :public Member
{
private:
	int   Proportion;		//积分上浮比例

public:
	//添加代码：根据题目说明，定义VIPMember类的带默认参数的构造函数及其他成员函数（9分）
	VIPMember(int id = 0, string name = "", int point = 0, int proportion = 2) :
		Member(id, name, point), Proportion(proportion) {};
	void print()
	{
		Member::print();
		cout << ", Proportion: " <<Proportion;
	}
	void AddPoint(int Consumption) {
		MemberPoint += Consumption;
	}
};

void AddupMemberPoint(Member* list[], int c[], int len)       
//针对一组会员，根据消费金额统计会员积分，并输出会员信息
//参数说明：list为指向基类对象的指针数组，c为一组会员的消费金额，len为这组会员人数
{
	//添加代码：根据这组会员的消费金额，统计各自的积分，并输出会员信息（7分）
	for (int i = 0; i < len; i++) {
		list[i]->AddPoint(c[i]);
		list[i]->print();
		cout << endl;
	}
}

int main()
{
	Member* memberlist[4];

	memberlist[0] = new Member(1, "Li Ming", 100);           //创建会员
	memberlist[1] = new Member(2, "Liu Hao", 200);
	memberlist[2] = new VIPMember(11, "Zhang San", 1000, 3);
	memberlist[3] = new VIPMember(12, "Wang Er", 2000);

	int c[] = { 100,100,100,100 };                          //该组会员每人消费了100元   

	//添加代码：调用函数AddupMemberPoint，统计每位会员消费100元后的积分并输出信息（4分）
	AddupMemberPoint(memberlist, c, 4);

	//添加代码：释放会员对象存储空间(2分)	
	for (int i = 0; i < 4; i++) {
		delete memberlist[i];
	}


	return 0;
}

