class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int,int> m;
        for(int i=0;i<data.size();++i){
            m[data[i]]++;
        }
        map<int,int>::iterator iter;
        iter=m.begin();
        bool fir=0;
        for(;iter!=m.end();++iter){
            if(iter->second==1){
                if(fir==false){
                    *num1=iter->first;
                    fir=true;
                }
                else{
                    *num2=iter->first;
                    break;
                }    
            }
        }
        return;
    }
};