// EX04-5.24.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "input a even number in the range 1 to 19 .\n";
    cin >> a;

    for (int hang = 1; hang <=a/2; hang++) {
        for (int kong =a/2  - hang; kong >= 0; kong--) {
            cout << " ";
        }
        for (int xing = 2 * hang - 1; xing > 0; xing--) {
            cout << "*";
        }
        cout << "\n";
    }

    for (int xing = 1; xing <= a + 1; xing++) {
        cout << "*";
    };
    cout << "\n";

    for (int hang = a/2; hang >= 1; hang--) {
        for (int kong = a/2 - hang; kong >= 0; kong--) {
            cout << " ";
        }
        for (int xing = 2 * hang - 1; xing > 0; xing--) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}