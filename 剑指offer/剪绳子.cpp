/*
给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/

class Solution {
public:
    int cutRope(int number) {
        if(number==2)    return 1;
        if(number==3)    return 2;
        int len=number/3;
        int yu=number%3;
        if(yu==2){
            return 2*pow(3,len);
        }
        if(yu==1){
            return 4*pow(3,len-1);
        }
        return pow(3,len);
    }
};