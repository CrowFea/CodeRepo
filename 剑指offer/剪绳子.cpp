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