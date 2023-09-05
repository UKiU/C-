#include <iostream>
#include <cstring>

using namespace std;


class MyString
{
private:
	char* str;
	int capacity;
	int length;

public:
	MyString()
	{
		str = new char[1];
		str[0] = 0;
		capacity = 1;
		length = 0;
	}

	MyString(const char* s)
	{
		int len = strlen(s);
		str = new char[len + 1];
		strcpy_s(str, len + 1, s);
		capacity = len + 1;
		length = len;
	}

	MyString(const MyString& other) //COPYππ‘Ï
	{
		capacity = other.length + 1;
		str = new char[capacity];

		strcpy_s(str, capacity, other.str);
		length = other.length;
	}

	~MyString()
	{
		delete[]str;
	}

public:

	int GetLength() const
	{
		return length;
	}

private:
	bool Find_Head(const char* str, const char* sFind) const
	{
		for (const char* p1 = str, *p2 = sFind;
			;
			++p1, ++p2)
		{
			if (!*p2) return true;
			if (!*p1) return false;

			if (*p1 != *p2)return false;
		}
	}

public:
	int Find(const char* sFind) const
	{
		for (const char* p1 = str; *p1; ++p1)
			if (Find_Head(p1, sFind))
				return p1 - str;

		return -1;
	}


	MyString& operator=(const MyString& other)
	{
		if (capacity < other.length + 1)
		{
			delete[]str;
			capacity = other.length + 1;
			str = new char[capacity];
		}

		strcpy_s(str, capacity, other.str);
		length = other.length;

		return *this;
	}

	char& operator[](int i)
	{
		return str[i];
	}

	char operator[](int i)const
	{
		return str[i];
	}

	friend MyString operator + (const MyString& s1, const MyString& s2);
	friend ostream& operator<< (ostream& o, const MyString& s);
};

MyString operator + (const MyString& s1, const MyString& s2)
{
	int LEN = s1.length + s2.length + 1;
	char* str = new char[LEN];

	strcpy_s(str, LEN, s1.str);
	//strcpy_s(str + s1.length, LEN - s1.length, s2.str);
	strcat_s(str, LEN, s2.str);

	MyString S = str;

	delete[]str;
	return S;
}

ostream& operator<< (ostream& o, const MyString& s)
{
	return o << s.str;
}

int main()
{
	//const char* s7;
	//s7 = "ABC";
	//cout << s7 << endl;
	//cout << GetLength(s7) << endl;

	//int a = 3;
	//int b = a;

	//const char* s1 = "ABC";
	//char s2[1024] = "BCD";
	//char* s3 = new char[1024];

	//strcpy_s(s2, 1024, s1);
	//s2 = s1;


	MyString s1 = "HELLO";
	cout << s1 << endl;
	MyString sk;

	MyString s2 = s1 + ", World!";
	cout << s2 << endl;

	s2[0] = 'K';
	cout << s2 << endl;

	cout << s2.Find("LLO") << endl;

	MyString s3 = s2;
	cout << s3 << endl;

}