/*
��Ŀ����
�����Ӽ�������
�磺
�����ַ�����"1+2+3" �����"6"
�����ַ�����"1+2-3" �����"0"
�����ַ�����"-1+2+3" �����"4"
�����ַ�����"1" �����"1"
�����ַ�����"-1" �����"-1"

��֪��������������㶼���������㣬��ֻ�мӼ�����
Ҫ�����ΪString���ͣ�����ʹ���ڽ���eval()����

��������:
�����ַ�����"1+2+3"
�������:
�����"6"
ʾ��1
����
����
1+2+3
���
����
6
*/
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int ans=0,i=0,start=0,end=0;
    bool plus=true;
    string str;
    cin>>str;
    if(str[0]=='-'){
        end++;
        start++;
        plus=false;
    }
    while(i<=str.size()){
        if(str[i]=='-'||str[i]=='+'||i==str.size())
            end=i;
        if(end>start){
            int num=stoi(str.substr(start,end-start));
            if(start>=1)
                plus = str[start-1]=='+';
            ans= plus==true ? ans+num:ans-num;
            start=end+1;
        }
        i++;
    }
    cout<<ans;
    return 0;
}