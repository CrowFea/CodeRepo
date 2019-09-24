/*
题目描述

输入年、月、日，计算该天是本年的第几天。 

输入： 

包括三个整数年(1<=Y<=3000)、月(1<=M<=12)、日(1<=D<=31)。 

输出： 

输入可能有多组测试数据，对于每一组测试数据， 

输出一个整数，代表Input中的年、月、日对应本年的第几天。


输入描述:
输入：1990 9 20
输出描述:
输入：263
示例1
输入
复制
2000 5 1 
输出
复制
122
备注:
注意闰年的判定方式
*/

#include<iostream>
using namespace std;

int main()
{
    int year,month,day;
    cin>>year>>month>>day;
    int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int res=0;
    if(year%4==0&&year%100!=0 || year%400==0){
        m[1]++;
    }
    for(int i=1;i<month;++i){
        res+=m[i];
    }
    res+=day;
    cout<<res<<endl;
    return 0;
}