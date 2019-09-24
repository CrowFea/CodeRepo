/*
动态规划
但是这题的表述太傻逼了
没啥意思
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> costs;
    int temp;
    char c;
    while(1)
    {
        cin>>temp;//获取一个数字
        costs.push_back(temp);//放入数组
        cin.get(c);//获取字符
        if(c=='\n')//如果为换行符
            break;//退出
    }
    int n=costs.size();//总的台阶数目
    vector<int> dp(n+1,0);//跳上第n阶（从0开始）所需的最小代价
    //dp[0]=0 从0阶出发
    //dp[1]=0 从1阶出发 初始值在初始化dp数组时可以一并赋值
    for(int i=2;i<=n;i++)
        dp[i]=min(dp[i-1]+costs[i-1],dp[i-2]+costs[i-2]);//由第i-1或i-2阶跳
    cout<<dp[n]<<endl;//输出跳上第n+1阶所需最小代价
    return 0;
}