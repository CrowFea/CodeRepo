/*
题目描述
已知一个字符串数组words，要求寻找其中两个没有重复字符的字符串，使得这两个字符串的长度乘积最大，输出这个最大的乘积。如：
words=["abcd","wxyh","defgh"], 其中不包含重复字符的两个字符串是"abcd"和"wxyh"，则输出16
words=["a","aa","aaa","aaaa"], 找不到满足要求的两个字符串，则输出0
输入描述:
Input:

["a","ab","abc","cd","bcd","abcd"]
输出描述:
Output:

4
示例1
输入
复制
["a","ab","abc","cd","bcd","abcd"]
输出
复制
4
备注:
Input中，不包含相同字符的有三对：
"ab"和"cd"
"a"和"cd"
"a"和"bcd"
所以字符串长度乘积的最大值是4
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int mark[10002][26];
 
void read(vector<string> &vs){
  string s = "";
  bool flag = false;
  char c;
  while((c = getchar()) != ']'){
    if(c == '[' || c == ','){
      continue;
    }
    if(c == '"'){
      flag ^= 1;
      if(flag){
        continue;
      }
    }
    if(flag){
      s.push_back(c);
    } else {
      vs.push_back(s);
      s.clear();
    }
  }
}
 
int main(){
  vector<string> vs;
  int Max = 0;
  bool flag;
  read(vs);
  for (int i = 0; i < vs.size(); i++){
    for(char ch : vs[i]){
      mark[i][ch - 'a'] = 1;
    }
  }
  for (int i = 0; i < vs.size(); i++){
    for (int j = i + 1; j < vs.size(); j++){
      flag = true;
      for (char ch = 'a'; ch <= 'z'; ch++){
        if(mark[j][ch - 'a'] + mark[i][ch - 'a'] > 1){
          flag = false;
          break;
        }
      }
      if(flag){
        int mul = vs[i].length() * vs[j].length();
        Max = max(mul, Max);
      }
    }
  }
  cout << Max << "\n";
  return 0;
}