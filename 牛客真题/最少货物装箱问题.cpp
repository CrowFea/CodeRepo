/*
��Ŀ����
�������ֱ�Ϊ3��5��7��������ֻ����һ��������ΪX��������ӣ�������������������أ�ֻ����������
��Ҫ��������װ��X����Ļ��Ҫ��ʹ�õĻ�������������٣����ֻ����������ޣ�

��������:
��������������X(1 <= X <= 10000)��һ��������
�������:
����޷�װ������� -1��
�������װ�������ʹ�û�����ܸ�����
ʾ��1
����
����
4
���
����
-1
˵��
�޷�װ��
ʾ��2
����
����
8
���
����
2
˵��
ʹ��1��5���1��3�������
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    int res=0;
    cin>>n;
    
        res+=n/7;
        int yu=n%7;
        switch(yu){
            case 0:    break;
            case 1:    res++; break;
            case 2:    res+=2;break;
            case 3:    res+=1;break;
            case 4:    res+=2;break;
            case 5:    res+=1;break;
            case 6:    res+=2;break;
        }
    if(n==1 || n==2 || n==4)    res=-1;
    cout<<res<<endl;
    return 0;
}