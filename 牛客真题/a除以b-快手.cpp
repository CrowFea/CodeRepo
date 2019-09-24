/*
��Ŀ����
��a/b��С��������ʽ�����a��������b����ҪС���㡣���������С���������ֱ����������������ѭ��С��������Ҫ��С��ѭ���Ĳ�����"()"��������

��������:
��������a��b������

0 <= a <= 1000 000

1 <= b <= 10 000
�������:
һ���ַ������÷�����С��������ʽ
ʾ��1
����
����
10 1
���
����
10
˵��
10/1 = 10
ʾ��2
����
����
1 2
���
����
0.5
˵��
1/2 = 0.5
ʾ��3
����
����
1 3
���
����
0.(3)
˵��
1/3 = 0.333333...
ʾ��4
����
����
1 6
���
����
0.1(6)
˵��
1/6 = 0.16666666....
ʾ��5
����
����
1 7
���
����
0.(142857)
˵��
1 / 7 = 0.1428571428...
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define N 1000
 
int main()
{
    int a, b, t;
    cin >> a >> b;
    cout << a / b;
    a = a % b;
    if(a == 0) return 0;
    cout << ".";
    map<int, int> m;
    vector<int> vec;
    t = 0;
    while(a != 0) {
        if(m.count(a) != 0) break;
        vec.push_back(a * 10 / b);
        m[a] = t++;
        a = a * 10 % b;
    }
    if(a == 0) {
        for(int i = 0; i < t; i++) cout << vec[i];
    } else {
        int k = m[a];
        for(int i = 0; i < k; i++) cout << vec[i];
        cout << "(";
        for(int i = k; i < t; i++) cout << vec[i];
        cout << ")";
    }
    cout << endl;
    return 0;
}