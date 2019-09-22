class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool* flag=new bool[rows*cols];
        for(int i=0;i<rows*cols;i++)
            flag[i]=false;
        int count=moving(threshold,rows,cols,0,0,flag);//�ӣ�0,0�����꿪ʼ����;
        delete[] flag;
        return count;
    }
    //��������ƶ�λ��
    int moving(int threshold,int rows,int cols,int i,int j,bool* flag)
    {
        int count=0;
        if(check(threshold,rows,cols,i,j,flag))
        {
            flag[i*cols+j]=true;
            //��Ƿ��ʹ��������־flag����Ҫ���ݣ���ΪֻҪ�����ʹ����ɡ�
           //��Ϊ����ܷ��ʣ����ʹ����1.���ܷ��ʣ�Ҳ�����·��ʹ���
            count=1+moving(threshold,rows,cols,i-1,j,flag)
                   +moving(threshold,rows,cols,i,j-1,flag)
                   +moving(threshold,rows,cols,i+1,j,flag)
                   +moving(threshold,rows,cols,i,j+1,flag);
        }
        return count;
    }
    //��鵱ǰλ���Ƿ���Է���
    bool check(int threshold,int rows,int cols,int i,int j,bool* flag)
    {
        if(i>=0 && i<rows && j>=0 && j<cols
            && getSum(i)+getSum(j)<=threshold
            && flag[i*cols+j]==false)
           return true;
        return false;
    }
    //����λ�õ���ֵ
    int getSum(int number)
    {
        int sum=0;
        while(number>0)
        {
            sum+=number%10;
            number/=10;
        }
        return sum;
    }
};