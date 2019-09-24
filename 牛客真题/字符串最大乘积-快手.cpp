/*
��Ŀ����
��֪һ���ַ�������words��Ҫ��Ѱ����������û���ظ��ַ����ַ�����ʹ���������ַ����ĳ��ȳ˻�������������ĳ˻����磺
words=["abcd","wxyh","defgh"], ���в������ظ��ַ��������ַ�����"abcd"��"wxyh"�������16
words=["a","aa","aaa","aaaa"], �Ҳ�������Ҫ��������ַ����������0
��������:
Input:

["a","ab","abc","cd","bcd","abcd"]
�������:
Output:

4
ʾ��1
����
����
["a","ab","abc","cd","bcd","abcd"]
���
����
4
��ע:
Input�У���������ͬ�ַ��������ԣ�
"ab"��"cd"
"a"��"cd"
"a"��"bcd"
�����ַ������ȳ˻������ֵ��4
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