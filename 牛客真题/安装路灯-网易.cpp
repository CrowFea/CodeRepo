/*
题目描述
小Q正在给一条长度为n的道路设计路灯安置方案。

为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。

小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。

小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。

输入描述:
输入的第一行包含一个正整数t(1 <= t <= 1000), 表示测试用例数
接下来每两行一个测试数据, 第一行一个正整数n(1 <= n <= 1000),表示道路的长度。
第二行一个字符串s表示道路的构造,只包含'.'和'X'。
输出描述:
对于每个测试用例, 输出一个正整数表示最少需要多少盏路灯。
示例1
输入
复制
2
3
.X.
11
...XX....XX
输出
复制
1
3
*/

#include<iostream>
#include<string>

using namespace std;

int lamp(int len,string s){
    int res=0;
    for(int i=0;i<len;++i){
        if(s[i]=='.'){
            ++res;
            i+=2;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin>>tt;
    for(int cas=0;cas<tt;++cas){
        int len;
        string s;
        cin>>len>>s;
        cout<<lamp(len,s)<<endl;
    }
    return 0;
}