/*
��Ŀ����
����һ���ַ�������������Ǽ�������ַ������ж��ٸ������Ӵ���
("���Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���)
���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ��Ϊ�ǲ�ͬ���Ӵ���
����C++,Java,C#ʵ����ش����߼�
��������:
����һ���ַ���S ���硰aabcb��(1 <= |S| <= 50), |S|��ʾ�ַ���S�ĳ��ȡ�
�������:
�����������ַ�����"a","a","aa","b","c","b","bcb"

���Դ�:7
ʾ��1
����
����
aabcb
���
����
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