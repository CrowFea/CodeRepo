class Solution {
public:
     bool isScramble(string s1, string s2) {
        if(s1==s2)  return true;
        int arr[26]={0};
        for(int i=0;i<s1.length();++i)  {++arr[s1[i]-'a'];--arr[s2[i]-'a'];}
        for(int i=0;i<26;++i)  if(arr[i])  return false;
        for(int i=1;i<s1.length();++i){
            //first i characters of s1 match first i characters of s2
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) &&
              isScramble(s1.substr(i),s2.substr(i)))    return true;
            //first i characters of s1 match last i characters of s2
            if(isScramble(s1.substr(0,i),s2.substr(s1.length()-i)) &&
              isScramble(s1.substr(i),s2.substr(0,s1.length()-i)))    return true;            
        }
        return false;
    }
};