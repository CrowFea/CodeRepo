class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n==0||str.size()==0)    return str;
        string res="";
        n=n%str.size();
        res=str.substr(n,str.size()-n)+str.substr(0,n);
        return res;
    }
};