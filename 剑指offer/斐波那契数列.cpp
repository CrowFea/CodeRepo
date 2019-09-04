class Solution {
public:
    int Fibonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int sum=0,a=0,b=1;
        for(int i=1;i<n;++i){
            sum=a+b;
            a=b;
            b=sum;
        }
        return sum;
    }
};