class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    if(n <= 0)return 0;
        int count = 0;
        for(int i=1; i <= n; i*=10){
            //计算在第i位上总共有多少个1
            count = count + (n/(10*i))*i;
            //不足i的部分有可能存在1
            int mod = n%(10*i);
            //如果超出2*i -1，则多出的1的个数是固定的
            if(mod > 2*i -1)count+=i;
            else{
                //只有大于i的时候才能会存在1
                if(mod >= i)
                    count += (mod -i)+1;
            }
        }
        return count;
    }
};