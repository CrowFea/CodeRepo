class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len=numbers.size();
        int count=0;
        int m[2];
        m[0]=numbers[0];
        m[1]=1;
        for(int i=1;i<len;++i){
            if(numbers[i-1]==m[0])    count++;
            else    --count;
            if(count==0){
                m[0]=numbers[i];
                count=1;
            }
        }
        count=0;
        for(int i=0;i<len;++i){
            if(numbers[i]==m[0])    count++;
            if(count>len/2)    return m[0];
        }
        return 0;
    }
};