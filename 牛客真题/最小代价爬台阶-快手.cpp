/*
��̬�滮
��������ı���̫ɵ����
ûɶ��˼
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
        cin>>temp;//��ȡһ������
        costs.push_back(temp);//��������
        cin.get(c);//��ȡ�ַ�
        if(c=='\n')//���Ϊ���з�
            break;//�˳�
    }
    int n=costs.size();//�ܵ�̨����Ŀ
    vector<int> dp(n+1,0);//���ϵ�n�ף���0��ʼ���������С����
    //dp[0]=0 ��0�׳���
    //dp[1]=0 ��1�׳��� ��ʼֵ�ڳ�ʼ��dp����ʱ����һ����ֵ
    for(int i=2;i<=n;i++)
        dp[i]=min(dp[i-1]+costs[i-1],dp[i-2]+costs[i-2]);//�ɵ�i-1��i-2����
    cout<<dp[n]<<endl;//������ϵ�n+1��������С����
    return 0;
}