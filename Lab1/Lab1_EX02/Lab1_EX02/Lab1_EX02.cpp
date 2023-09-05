// Lab1_EX02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

void main()
{
    float num1, num2, num3, sum, average, product, smallest, largest;

    cin >> num1 >> num2 >> num3;

    sum = num1 + num2 + num3;
    average = sum / 3;
    product = num1 * num2 * num3;
    if (num1 >= num2) {
        if (num2 >= num3)smallest = num3;
        else smallest = num2;

        if (num1 <= num3)largest = num3;
        else largest = num1;
    }
    else {
        if (num1 >= num3)smallest = num3;
        else smallest = num1;

        if (num2 <= num3)largest = num3;
        else largest = num2;
    }

    cout << "Sum " << "is " << sum<<"\n";
    cout << "Average " << "is " << average << "\n";
    cout << "Product " << "is " << product << "\n";
    cout << "Smallest " << "is " << smallest << "\n";
    cout << "Largest " << "is " << largest << "\n";
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
