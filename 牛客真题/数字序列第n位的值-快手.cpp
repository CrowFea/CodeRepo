/*
题目描述
有一个无限长的数字序列1，2，2，3，3，3，4，4，4，4，5，5，5，5，5。。。（数字序列从1开始递增，且数字k在该序列中正好出现k次），求第n项是多少
输入描述:
输入为一个整数n
输出描述:
输出一个整数，即第n项的值
示例1
输入
复制
4
输出
复制
3
备注:
如：输入为3，有序数列第3项的值为2，则输出为2
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<ceil(((-1)+sqrt(1+4*1*2*n))/2)<<endl;
    return 0;
}