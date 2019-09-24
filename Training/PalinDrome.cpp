/*
判断一个字符串中包含的回文串的个数，单个的字符也算回文串
两种算法：
中心扩散法
动态规划
*/
class Solution
{
public:
    //中心扩散
    int res = 0;
    void helper(string s, int left, int right)
    {
        for (int i = left, j = right; i >= 0, j < s.size(); i--, j++)
        {
            if (s[i] == s[j])
            {
                ++res;
                continue;
            }
            else
                break;
        }
    }

    int NumberofPanli(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            helper(s, i, i);
            helper(s, i, i + 1); //考虑abba的情况
        }
        return res;
    }

    //动态规划
    int NumberofPanliDP(string s)
    {
        int res = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--)
        { //注意一定要从后往前
            for (int j = i; j < s.size(); j++)
            {
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1] == 1);
                if (dp[i][j] == 1)
                    res++;
            }
        }
        return res;
    }
};

//================================================================
/*
最长回文子串，求一个字符串中的最长连续回文串
中心扩散
dp
*/
class Solution
{
public:
//动态规划
    string longestPanlidromDP(string s)
    {
        if(s.size()<2) return s;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        string res ="";
        res+=s[0];
        for (int j = 1; j<s.size(); ++j){
            for (int i = 0; i < j; ++i){
                dp[i][j] == (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1] == 1);
                if (dp[i][j]){
                    if (j - i + 1 > res.size()){
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return res;
    }

//中心扩散
    int maxl=0,maxr=0; 
    void helper(string s,int left, int right){
        for(int i=left,j=right;i>=0,j<s.size();--i,++j){
            if(s[i]!=s[j])  break;
            if(j-i>maxr-maxl){
                maxr = j;
                maxl = i;
            }
        }
        return;
    }
    string longestPanlidrom(string s){
        if(s.size()<2)  return s;
        for(int i=0;i<s.size();i++){
            helper(s,i,i);
            helper(s, i, i+1);
        }
        string res=s.substr(left,right-left+1);
        return res;
    }
};

//================================================================
/*
最长不连续回文子串，求一个字符串中的最长不连续回文串的长度
dp
*/
class Solution
{
public:
//动态规划
    int longestPanlidromDP(string s)
    {
        if(s.size()<2) return s;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int l=1;l<s.size();l++){
            dp[l][l]=1; 
            for(int r=0;r<l; ++r){
                if(s[l]==s[r]){
                    dp[l][r]=dp[l+1][r-1]+2;
                }
                else{
                    dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};