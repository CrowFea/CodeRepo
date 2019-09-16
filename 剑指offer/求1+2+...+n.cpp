class Solution {
public:
    int Sum_Solution(int n) {
        int res = n;
        res &&(res += Sum_Solution(n - 1));//短路求值，退出条件为res==0
        return res;
    }
};