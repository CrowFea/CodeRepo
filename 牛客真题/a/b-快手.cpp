/*
题目描述
求a/b的小数表现形式。如果a可以整除b则不需要小数点。如果是有限小数，则可以直接输出。如果是无限循环小数，则需要把小数循环的部分用"()"括起来。

输入描述:
两个整数a和b，其中

0 <= a <= 1000 000

1 <= b <= 10 000
输出描述:
一个字符串，该分数的小数表现形式
示例1
输入
复制
10 1
输出
复制
10
说明
10/1 = 10
示例2
输入
复制
1 2
输出
复制
0.5
说明
1/2 = 0.5
示例3
输入
复制
1 3
输出
复制
0.(3)
说明
1/3 = 0.333333...
示例4
输入
复制
1 6
输出
复制
0.1(6)
说明
1/6 = 0.16666666....
示例5
输入
复制
1 7
输出
复制
0.(142857)
说明
1 / 7 = 0.1428571428...
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define N 1000
 
int main()
{
    int a, b, t;
    cin >> a >> b;
    cout << a / b;
    a = a % b;
    if(a == 0) return 0;
    cout << ".";
    map<int, int> m;
    vector<int> vec;
    t = 0;
    while(a != 0) {
        if(m.count(a) != 0) break;
        vec.push_back(a * 10 / b);
        m[a] = t++;
        a = a * 10 % b;
    }
    if(a == 0) {
        for(int i = 0; i < t; i++) cout << vec[i];
    } else {
        int k = m[a];
        for(int i = 0; i < k; i++) cout << vec[i];
        cout << "(";
        for(int i = k; i < t; i++) cout << vec[i];
        cout << ")";
    }
    cout << endl;
    return 0;
}