class Solution {
public:
    int StrToInt(string str) {
        int res=0;
        bool flag=true;
        for(int i=0;i<str.size();++i){
            if(str[i]=='+'&&i==0)    continue;
            if(str[i]=='-'&&i==0){
                flag=false;
                continue;
            }    
            if(str[i]<='9'&&str[i]>='0'){
                res=res*10+str[i]-'0';
            }
            else{
                return 0;
            }
        }
        if(flag==false)    res*=-1;
        return res;
    }
};