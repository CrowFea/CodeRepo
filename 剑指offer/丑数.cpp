class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<7)    return index;
        vector<int> res(index);
        res[0]=1;
        int t1=0,t2=0,t3=0;
        for(int i=1;i<index;++i){
            res[i]=min(res[t1]*2,min(res[t2]*3,res[t3]*5));
            if(res[i]==res[t1]*2)    t1++;
            if(res[i]==res[t2]*3)    t2++;
            if(res[i]==res[t3]*5)    t3++;
        }
        return res[index-1];
    }
};