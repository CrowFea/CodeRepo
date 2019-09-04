class Solution {
public:
    int rectCover(int number) {
        if(number==1)    return 1;
        if(number==2)    return 2;
        int a=1,b=2,sum=0;
        for(int i=2;i<number;++i){
            sum=a+b;
            a=b;
            b=sum;
        }
        return sum;
    }
};