/*
题目描述
今天上课，老师教了小易怎么计算加法和乘法，乘法的优先级大于加法，但是如果一个运算加了括号，那么它的优先级是最高的。例如：
1+2*3=7
1*(2+3)=5
1*2*3=6
(1+2)*3=9
现在小易希望你帮他计算给定3个数a，b，c，在它们中间添加"+"， "*"， "("， ")"符号，能够获得的最大值。
输入描述:
一行三个数a，b，c (1 <= a, b, c <= 10)
输出描述:
能够获得的最大值
示例1
输入
复制
1 2 3
输出
复制
9
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> nums(3);
    cin>>nums[0]>>nums[1]>>nums[2];
    int a=nums[0]+nums[1]*nums[2];
    int b=nums[0]*(nums[1]*nums[2]);
    int c=nums[0]*nums[1]*nums[2];
    int d=(nums[0]+nums[1])*nums[2];
    cout<<max(a,max(b,max(c,d)))<<endl;
    return 0;
}