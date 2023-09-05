#include<iostream>
#include<cmath>
using namespace std;

bool huiwen(int a) { //判断是不是回文数
	int b = a,c = 0;
	while (b > 0) {
		int d = b% 10;
		b /= 10;
		c = c * 10 + d;
	}
	return a == c;
}

int main() {
	int yuan;
	cout <<"input a number <=2147483647 " << endl;
	cin >> yuan;
	if (huiwen(yuan)) {  //判断本体是不是回文
		cout << yuan;
		return 0;
	}
	int n=0,m=yuan;
	while (m) {
		m /= 10;
		n++;
	}
	
	while(yuan>0){
		for (int i = n;i>0; i--) {  //取出i位数
			for (int j = 1;; j++) {  //从倒数第j个开始取
				int a = yuan / pow(10, j - 1),b;  //从后把j-1位数去掉
				if (i > n+1-j)break;  //防止剩余数不足i位
				int mol = pow(10, i);  //取出i位数
				b = a % mol;
				
				if (huiwen(b)) { //判断回文
					cout << b << endl;
					return 0;
				}
			}
		}
	}

}