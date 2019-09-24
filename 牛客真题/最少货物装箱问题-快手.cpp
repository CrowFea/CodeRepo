/*
题目描述
有重量分别为3，5，7公斤的三种货物，和一个载重量为X公斤的箱子（不考虑体积等其它因素，只计算重量）
需要向箱子内装满X公斤的货物，要求使用的货物个数尽可能少（三种货物数量无限）

输入描述:
输入箱子载重量X(1 <= X <= 10000)，一个整数。
输出描述:
如果无法装满，输出 -1。
如果可以装满，输出使用货物的总个数。
示例1
输入
复制
4
输出
复制
-1
说明
无法装满
示例2
输入
复制
8
输出
复制
2
说明
使用1个5公斤，1个3公斤货物
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    int res=0;
    cin>>n;
    
        res+=n/7;
        int yu=n%7;
        switch(yu){
            case 0:    break;
            case 1:    res++; break;
            case 2:    res+=2;break;
            case 3:    res+=1;break;
            case 4:    res+=2;break;
            case 5:    res+=1;break;
            case 6:    res+=2;break;
        }
    if(n==1 || n==2 || n==4)    res=-1;
    cout<<res<<endl;
    return 0;
}