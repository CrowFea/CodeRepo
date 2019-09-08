class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int j=0;
        for(int i=0;i<pushV.size();++i){
            while(!s.empty()&&s.top()==popV[j]){
                s.pop();
                ++j;
            }
            s.push(pushV[i]);
        }
        while(!s.empty()&&s.top()==popV[j]){
                s.pop();
                ++j;
        }
        if(!s.empty())    return false;
        return true;
    }
};