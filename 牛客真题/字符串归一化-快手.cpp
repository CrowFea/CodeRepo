/*
题目描述

通过键盘输入一串小写字母(a~z)组成的字符串。
请编写一个字符串归一化程序，统计字符串中相同字符出现的次数，并按字典序输出字符及其出现次数。
例如字符串"babcc"归一化后为"a1b2c2"



输入描述:
每个测试用例每行为一个字符串，以'\n'结尾，例如cccddecca
输出描述:
输出压缩后的字符串ac5d2e
示例1
输入
复制
dabcab
输出
复制
a2b2c1d1
*/

#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    string s,res="";
    map<char,int> m;
    cin>>s;
    for(int i=0;i<s.size();++i){
        m[s[i]]++;
    }
    for(char ch='a';ch<='z';ch++){
       if(m.count(ch)){
           cout<<ch<<m[ch];
       }
    }
    cout<<endl;
    return 0;
}