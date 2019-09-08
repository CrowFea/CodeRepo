
class Solution {
public:
     vector<int> minn;
     int cur = 0;
     vector<int> stack;

     void push(int value) {
         stack.push_back(value);
         cur++;
         if(cur == 1) minn.push_back(value);
         else minn[cur-1] = minn[cur-2] > value ? value : minn[cur-2];
     }
     void pop() {
         if(cur == 0) return ;
         cur--;
         stack.pop_back();
         minn.pop_back();
     }
     int top() {
         return stack[cur-1];
     }
     int min() {
         return minn[cur-1];
     }
};