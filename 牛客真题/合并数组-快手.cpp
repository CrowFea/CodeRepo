/*
题目描述
请实现一个函数，功能为合并两个升序数组为一个升序数组
点击页面左下角“例2”，了解如何实现输入输出
输入描述:
输入有多个测试用例，每个测试用例有1-2行，每行都是以英文逗号分隔从小到大排列的数字
输出描述:
输出一行以英文逗号分隔从小到大排列的数组
示例1
输入
复制
1,5,7,9
2,3,4,6,8,10
输出
复制
1,2,3,4,5,6,7,8,9,10
备注:
不允许使用原生的 sort、concat 等函数
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> arr;
    istringstream ss1(str1);
    int i;
    char c;
    while(ss1 >> i){
        arr.push_back(i);
        if(ss1 >> c ){
            continue;
        }
    }
    istringstream ss2(str2);
    while(ss2 >> i){
        arr.push_back(i);
        if(ss2 >> c ){
            continue;
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr[0];
    for(int i = 1; i < (int)arr.size(); i++){
        cout << "," << arr[i];
    }
    return 0;
}