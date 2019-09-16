class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int i=0;
        int j=array.size()-1;
        while(i<j){
            if(array[i]+array[j]==sum){
                res.push_back(array[i]);
                res.push_back(array[j]);
                break;
            }
            else if(array[i]+array[j]<sum){
                ++i;
            }
            else{
                --j;
            }
        }
        return res;
    }
};