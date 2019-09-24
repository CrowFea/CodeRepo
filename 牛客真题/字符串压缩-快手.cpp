/*
题目描述
对字符串进行RLE压缩，将相邻的相同字符，用计数值和字符值来代替。例如：aaabccccccddeee，则可用3a1b6c2d3e来代替。

输入描述:
输入为a-z,A-Z的字符串，且字符串不为空，如aaabccccccddeee
输出描述:
压缩后的字符串，如3a1b6c2d3e
示例1
输入
复制
aaabccccccdd
输出
复制
3a1b6c2d
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
            n++;
        else
        {
            cout<<n<<s[i-1];
            n=1;
        }
    }
    cout<<n<<s[s.size()-n];
    return 0;
}