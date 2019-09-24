/*
题目描述
解析加减法运算
如：
输入字符串："1+2+3" 输出："6"
输入字符串："1+2-3" 输出："0"
输入字符串："-1+2+3" 输出："4"
输入字符串："1" 输出："1"
输入字符串："-1" 输出："-1"

已知条件：输入的运算都是整数运算，且只有加减运算
要求：输出为String类型，不能使用内建的eval()函数

输入描述:
输入字符串："1+2+3"
输出描述:
输出："6"
示例1
输入
复制
1+2+3
输出
复制
6
*/
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int ans=0,i=0,start=0,end=0;
    bool plus=true;
    string str;
    cin>>str;
    if(str[0]=='-'){
        end++;
        start++;
        plus=false;
    }
    while(i<=str.size()){
        if(str[i]=='-'||str[i]=='+'||i==str.size())
            end=i;
        if(end>start){
            int num=stoi(str.substr(start,end-start));
            if(start>=1)
                plus = str[start-1]=='+';
            ans= plus==true ? ans+num:ans-num;
            start=end+1;
        }
        i++;
    }
    cout<<ans;
    return 0;
}