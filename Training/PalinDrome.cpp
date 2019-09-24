class Solution{
public:
/*
判断一个字符串中包含的回文串的个数，单个的字符也算回文串
两种算法：
中心扩散法
动态规划
*/
//中心扩散
    int res=0;
    void helper(string s,int left,int right){
        for(int i=left,j=right;i>=0,j<s.size();i--,j++){
            if(s[i]==s[j]){
                ++res;
                continue;
            }
            else break;
        }
    }

    int NumberofPanli(string s){
        for(int i=0;i<s.size();++i){
            helper(s,i,i);
            helper(s,i,i+1);    //考虑abba的情况
        }
        return res;
    }

//动态规划
    int NumberofPanliDP(string s){
        int res=0;
        vector<vector<int> > dp(s.size(),vector<int>(s.size(),0));
        for(int i=s.size()-1;i>=0;i--){ //注意一定要从后往前
            for(int j=i;j<s.size();j++){
                dp[i][j]=(s[i]==s[j])&&(j-i<=2||dp[i+1][j-1]==1);
                if(dp[i][j]==1) res++;
            }
        }
        return res;
    }
};