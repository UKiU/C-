#include<iostream>
#include<cmath>
using namespace std;

bool huiwen(int a) { //�ж��ǲ��ǻ�����
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
	if (huiwen(yuan)) {  //�жϱ����ǲ��ǻ���
		cout << yuan;
		return 0;
	}
	int n=0,m=yuan;
	while (m) {
		m /= 10;
		n++;
	}
	
	while(yuan>0){
		for (int i = n;i>0; i--) {  //ȡ��iλ��
			for (int j = 1;; j++) {  //�ӵ�����j����ʼȡ
				int a = yuan / pow(10, j - 1),b;  //�Ӻ��j-1λ��ȥ��
				if (i > n+1-j)break;  //��ֹʣ��������iλ
				int mol = pow(10, i);  //ȡ��iλ��
				b = a % mol;
				
				if (huiwen(b)) { //�жϻ���
					cout << b << endl;
					return 0;
				}
			}
		}
	}

}