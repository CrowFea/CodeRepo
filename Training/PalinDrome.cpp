class Solution{
public:
/*
�ж�һ���ַ����а����Ļ��Ĵ��ĸ������������ַ�Ҳ����Ĵ�
�����㷨��
������ɢ��
��̬�滮
*/
//������ɢ
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
            helper(s,i,i+1);    //����abba�����
        }
        return res;
    }

//��̬�滮
    int NumberofPanliDP(string s){
        int res=0;
        vector<vector<int> > dp(s.size(),vector<int>(s.size(),0));
        for(int i=s.size()-1;i>=0;i--){ //ע��һ��Ҫ�Ӻ���ǰ
            for(int j=i;j<s.size();j++){
                dp[i][j]=(s[i]==s[j])&&(j-i<=2||dp[i+1][j-1]==1);
                if(dp[i][j]==1) res++;
            }
        }
        return res;
    }
};