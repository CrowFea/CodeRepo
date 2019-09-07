class Solution {
public:
    double getPower(double base,int exponent){
        if(exponent==0)    return 1;
        if(exponent==1)    return base;
        double ans=getPower(base,exponent>>1);
        ans*=ans;
        if((exponent&1)==1){
            ans*=base;
        }
        
        return ans;
    }
    
    double Power(double base, int exponent) {
        if(exponent==0)    return 1;
        if(exponent==1)    return base;
        bool flag=false;
        if(exponent<0){
            flag=1;
            exponent*=-1;
        }
        double ans=getPower(base,exponent);
        return flag==0?ans:1/ans;
    }
};