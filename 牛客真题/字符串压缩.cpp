/*
��Ŀ����
���ַ�������RLEѹ���������ڵ���ͬ�ַ����ü���ֵ���ַ�ֵ�����档���磺aaabccccccddeee�������3a1b6c2d3e�����档

��������:
����Ϊa-z,A-Z���ַ��������ַ�����Ϊ�գ���aaabccccccddeee
�������:
ѹ������ַ�������3a1b6c2d3e
ʾ��1
����
����
aaabccccccdd
���
����
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