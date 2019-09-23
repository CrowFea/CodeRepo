class Solution {
public:
    vector<int> getNext(string p){
        vector<int> next(p.size());
        int j=0,i=-1;
        next[0]=-1;
        while(j<p.size()){
            if(i==-1 || p[j]==p[i]){
                ++i;
                ++j;
                next[j]=i;
            }
            else{
                i=next[i];
            }
        }
        return next;
    }

    int KMP(string s,string p){
        int i=0,j=0; 
        while(i<s.size() && j<p.size()){
            if(s[i]==p[j]){
                ++i;
                ++j;
            }
            else{
                j=next[j];
            }
        }
        if(j==p.size()) return i-j;
        return -1;
    }

};