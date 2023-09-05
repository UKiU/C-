#include <iostream>
using namespace std;
#define Maxsize 255 
class mystring{
private:
	char ch[Maxsize];
	int length;
public:
	mystring() {
		ch[0] = '\0';
		length = 0;
	}
	mystring(string & str) {
		for (int i = 0; i < str.length(); i++) {
			ch[i] = str[i];
		}
		length = str.length();
	}
	mystring(mystring& str) {
		for (int i = 0; i < str.length; i++) {
			ch[i] = str.ch[i];
		}
		length = str.length;
	}

	char getch(int n) {
		return ch[n];
	}
	int getlength() {
		return length;
	}
	void Reverse(mystring& ch ,int n , int m);
	friend void format(mystring& s1, mystring& s2, mystring& s3, int n);
};

void mystring::Reverse(mystring& my , int n,int m) {//反转从n到m的字符
	if (n >= m)return;
	Reverse(my, n + 1, m - 1);
	char temp;
	temp = my.ch[n];
	my.ch[n] = my.ch[m];
	my.ch[m] = temp;
}
void format(mystring& s1, mystring& s2, mystring& s3,int n) {
	int i,k;
	bool bl = 0;//判断首是否有空格
	for (i = 0, k = 0; i < n;) {
		if (bl == 0&&s1.ch[k] == ' ') {
			k++;
		}
		else {
			bl = 1;
			s2.ch[i] = s1.ch[k];
			s2.length++;
			i++, k++;
		}
	}
	//判断尾是否有空格
	if (s2.ch[n - 1] == ' ') {
		if (k < s1.getlength()) {
			for (; k < s1.getlength();) {
				if (s1.ch[k] != ' ') {
					s2.ch[n - 1] = s1.ch[k];
					k++;
					break;
				}
				else k++;
			}
		}
	}
	for (int j=0; k < s1.getlength(); j++,k++) {
		s3.ch[j] = s1.ch[k];
		s3.length++;
	}
}

int main() {
	string str;
	str = "  abcd  efgh";
	/*cin >> str;
	mystring my(str);
	for (int i = 0; i < my.getlength(); i++) {
		cout << my.getch(i);
	}
	my.Reverse(my,0,(my.getlength()-1));
	cout << endl;
	for (int i = 0; i < my.getlength(); i++) {
		cout << my.getch(i);
	}*/
	mystring s1(str);
	mystring s2,s3;
	cout << "s1=";
	for (int i = 0; i < s1.getlength(); i++) {
		cout << s1.getch(i);
	}
	format(s1, s2, s3, 5);
	cout << endl << "s2=";
	for (int i = 0; i < s2.getlength(); i++) {
		cout << s2.getch(i);
	}
	cout << endl << "s3=";
	for (int i = 0; i < s3.getlength(); i++) {
		cout << s3.getch(i);
	}
}