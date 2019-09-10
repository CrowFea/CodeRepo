class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum=0,res=INT_MIN;
        for(int i=0;i<array.size();++i){
            if(sum<0)    sum=0;
            sum+=array[i];
            res=max(res,sum);
        }
        return res;
    }
};