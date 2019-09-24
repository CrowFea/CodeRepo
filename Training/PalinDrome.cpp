/*
�ж�һ���ַ����а����Ļ��Ĵ��ĸ������������ַ�Ҳ����Ĵ�
�����㷨��
������ɢ��
��̬�滮
*/
class Solution
{
public:
    //������ɢ
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
            helper(s, i, i + 1); //����abba�����
        }
        return res;
    }

    //��̬�滮
    int NumberofPanliDP(string s)
    {
        int res = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--)
        { //ע��һ��Ҫ�Ӻ���ǰ
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
������Ӵ�����һ���ַ����е���������Ĵ�
������ɢ
dp
*/
class Solution
{
public:
//��̬�滮
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

//������ɢ
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
������������Ӵ�����һ���ַ����е�����������Ĵ��ĳ���
dp
*/
class Solution
{
public:
//��̬�滮
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