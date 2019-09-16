/*
题目描述
平面内有n个矩形, 第i个矩形的左下角坐标为(x1[i], y1[i]), 右上角坐标为(x2[i], y2[i])。

如果两个或者多个矩形有公共区域则认为它们是相互重叠的(不考虑边界和角落)。

请你计算出平面内重叠矩形数量最多的地方,有多少个矩形相互重叠。

输入描述:
输入包括五行。
第一行包括一个整数n(2 <= n <= 50), 表示矩形的个数。
第二行包括n个整数x1[i](-10^9 <= x1[i] <= 10^9),表示左下角的横坐标。
第三行包括n个整数y1[i](-10^9 <= y1[i] <= 10^9),表示左下角的纵坐标。
第四行包括n个整数x2[i](-10^9 <= x2[i] <= 10^9),表示右上角的横坐标。
第五行包括n个整数y2[i](-10^9 <= y2[i] <= 10^9),表示右上角的纵坐标。
输出描述:
输出一个正整数, 表示最多的地方有多少个矩形相互重叠,如果矩形都不互相重叠,输出1。
示例1
输入
复制
2
0 90
0 90
100 200
100 200
输出
复制
2
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;
// square overlap
class Square{
public:
    int left, right, up, down;
    bool operator <(const Square &x){
        return down < x.down;
    }
};
 
bool leftto(Square a, Square b){
    return a.left < b.left;
}
 
void eraselower(vector<Square> &a, int ybound){
    int deln = 0, i = 0, n = a.size();
    while(i + deln < n){
        if(a[i].up<=ybound)
            swap(a[i], a[n-(++deln)]);
        else
            ++i;
    }
    a.erase(a.end()-deln, a.end());
}
 
int main(){
    int n;
    cin>>n;
    vector<Square> sqs(n), row;
    for(int i=0; i<n; ++i)
        cin>>sqs[i].left;
    for(int i=0; i<n; ++i)
        cin>>sqs[i].down;
    for(int i=0; i<n; ++i)
        cin>>sqs[i].right;
    for(int i=0; i<n; ++i)
        cin>>sqs[i].up;
    sort(sqs.begin(), sqs.end());
    int sn = 0, curdown = 0, res = 0;
    while(sn<n){
        curdown = sqs[sn].down;
        while(sn<n && sqs[sn].down == curdown)
            row.push_back(sqs[sn++]);
        eraselower(row, curdown);
        sort(row.begin(), row.end(), leftto);
        vector<int> rights;
        for(Square x:row){
            rights.erase(rights.begin(), upper_bound(rights.begin(), rights.end(), x.left));
            rights.insert(upper_bound(rights.begin(), rights.end(), x.right), x.right);
            if(res < rights.size()) res = rights.size();
        }
    }
    cout<<res<<endl;
}