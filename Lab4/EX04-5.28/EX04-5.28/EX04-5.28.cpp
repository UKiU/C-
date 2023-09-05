// EX04-5.28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
    for (int n = 1; n <= 12; n++) {
        cout << "On the ";
        switch (n) {
            case 1: cout << "first "; break;
            case 2: cout << "second "; break;
            case 3: cout << "third "; break;
            case 4: cout << "fourth "; break;
            case 5: cout << "fifth "; break;
            case 6: cout << "sixth "; break;
            case 7: cout << "seventh "; break;
            case 8: cout << "eighth "; break;
            case 9: cout << "ninth "; break;
            case 10: cout << "tenth "; break;
            case 11: cout << "eleventh "; break;
            case 12: cout << "twelfth "; break;
        }
        cout << "day of Christmas\n" 
             << "my true love sent to me:\n";
        switch(n) case 1:cout << "A ";
        for (int m = n; m >= 1; m--) {
            switch (m) {
                case 2: cout << "Two Turtle Doves\n"<<"and a "; break;
                case 3: cout << "Three French Hens\n"; break;
                case 4: cout << "Four Calling Birds\n"; break;
                case 5: cout << "Five Golden Rings\n"; break;
                case 6: cout << "Six Geese a Laying\n"; break;
                case 7: cout << "Seven Swans a Swimming\n"; break;
                case 8: cout << "Eight Maids a Milking\n"; break;
                case 9: cout << "Nine Ladies Dancing\n"; break;
                case 10: cout << "Ten Lords a Leaping\n"; break;
                case 11: cout << "Eleven Pipers Piping\n"; break;
                case 12: cout << "twelwe Drummers Drumming\n"; break;
        }
        }
        cout << "Partridge in a Pear Tree\n"<<"\n";
    }
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
