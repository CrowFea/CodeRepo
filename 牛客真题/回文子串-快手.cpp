/*
题目描述
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
("回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。)
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
可用C++,Java,C#实现相关代码逻辑
输入描述:
输入一个字符串S 例如“aabcb”(1 <= |S| <= 50), |S|表示字符串S的长度。
输出描述:
符合条件的字符串有"a","a","aa","b","c","b","bcb"

所以答案:7
示例1
输入
复制
aabcb
输出
复制
7
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
 int NumberofPanliDP(string s){
        int res=0;
        vector<vector<int> > dp(s.size(),vector<int>(s.size(),0));
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                dp[i][j]=(s[i]==s[j])&&(j-i<=2||dp[i+1][j-1]==1);
                if(dp[i][j]==1) res++;
            }
        }
        return res;
    }

int main()
{
    string s;
    cin>>s;
    cout<<NumberofPanliDP(s)<<endl;
    return 0;
}