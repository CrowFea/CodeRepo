/*
����һ������Ϊn�����ӣ�������Ӽ���m�Σ�m��n����������n>1����m>1����
ÿ�����ӵĳ��ȼ�Ϊk[0],k[1],...,k[m]������k[0]xk[1]x...xk[m]���ܵ����˻��Ƕ��٣�
���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
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