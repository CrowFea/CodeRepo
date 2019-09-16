/*
题目描述
牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。

但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
牛牛希望你能帮他计算一共有多少个可能的数对。

输入描述:
输入包括两个正整数n,k(1 <= n <= 10^5, 0 <= k <= n - 1)。
输出描述:
对于每个测试用例, 输出一个正整数表示可能的数对数量。
示例1
输入
复制
5 2
输出
复制
7
说明
满足条件的数对有(2,3),(2,4),(2,5),(3,4),(3,5),(4,5),(5,3)
*/

#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    long long n,k;
    cin>>n>>k;
    long long ans=0;
    for(int y=max(1LL,k);y<=n;++y)
    {
        int res=0;
        res=n/y*(y-k);
        if(n%y>=k)
            if(k)
                res+=n%y-k+1;
            else res+=n%y;
        ans+=res;
    }
    cout<<ans<<endl;
    return 0;
}