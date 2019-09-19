/*
题目描述
最大回文子串是被研究得比较多的一个经典问题。最近月神想到了一个变种，对于一个字符串，如果不要求子串连续，那么一个字符串的最大回文子串的最大长度是多少呢。
输入描述:
每个测试用例输入一行字符串（由数字0-9，字母a-z、A-Z构成），字条串长度大于0且不大于1000.
输出描述:
输出该字符串的最长回文子串的长度。（不要求输出最长回文串，并且子串不要求连续）
示例1
输入
复制
adbca
输出
复制
3
说明
因为在本题中，不要求回文子串连续，故最长回文子串为aba(或ada、aca)
备注:
因为不要求子串连续，所以字符串abc的子串有a、b、c、ab、ac、bc、abc7个
*/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1000
 
char a[N];
int dp[N][N];
 
int main()
{
    int n, i, j, k;
    cin >> a;
    n = strlen(a);
    for(j = 0; j < n; j++) {
        dp[j][j] = 1;
        for(i = j - 1; i >= 0; i--) {
            if(a[i] == a[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}