/*
题目描述
小易在学校中学习了关于字符串的理论, 于是他基于此完成了一个字典的项目。

小易的这个字典很奇特, 字典内的每个单词都包含n个'a'和m个'z', 并且所有单词按照字典序排列。

小易现在希望你能帮他找出第k个单词是什么。

输入描述:
输入包括一行三个整数n, m, k(1 <= n, m <= 100, 1 <= k <= 109), 以空格分割。

输出描述:
输出第k个字典中的字符串，如果无解，输出-1。
示例1
输入
复制
2 2 6
输出
复制
zzaa
说明
字典中的字符串依次为aazz azaz azza zaaz zaza zzaa
*/

#include<iostream>
#include<vector>
using namespace std;

void solve(int n, int m, long long k) {
    vector<char> x;//
    while (n && m) {
        //每次迭代问题规模缩减一个单位
        ////排列组合:假设当前序列首字符为a，剩下n-1个a放在剩下n - 1 +m 个位置共有的可能数
        long long count = 1;
        for (int i = 0; i < n - 1; i++) {//求组合数
                count *= n - 1 + m - i;
                count /= (i + 1);
                if (count > k)break;//防止越界。count>k就可以退出计算了
            }
            if (k <= count) {//如果k小于等于count，则表明首字符的确应为a
                x.push_back('a');
                n--;//问题缩减为 n-1个a和m个z 中找第k大
            }
            else {
                x.push_back('z');
                m--;//问题缩减为 n-1个a和m个z 中找第k-count大
                k -= count;
            }
        }
        //循环结束后，剩余子序列只存在"aa..aaa" 或 "zz..zzz"1种情况
        if (k != 1) {//
            cout << -1;
            return;
        }
        while (n--)x.push_back('a');
        while (m--)x.push_back('z');
        for (int i = 0; i < x.size(); i++) {
            cout << x[i];
        }
    }

int main() {
    int n, m;
    long long k;
    while (cin >> n >> m >> k) {
        solve(n, m, k);
    }
    return 0;
}