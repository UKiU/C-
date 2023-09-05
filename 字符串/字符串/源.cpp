#include<iostream>
#include<cstring>
using namespace std;
class MyString {
private:	
	char* str;
	int capaticy;
	int length;

public:
	
	MyString() {
		str = new char[1];
	}



	int Getlength(const char* str) {
		int c = 0;
		for (const char* p = str; *p; ++p) {
			++c;
		}
		return c;
	}

	bool Find(const char* s1, const char* s2) {
		for (const char* p1 = s1, const char* p2 = s2; ; ++p1, ++p2) {
			
		}
		return ;
	}
};

int main() {
	const char* str;
	str = "ABC";

	cout << str << endl;
	cout << Getlength(str) << endl;

	const char* s1;
	strcpy_s()
}