class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int x=array.size()-1,y=0;
        while(x>=0&&y<array[0].size()){
            if(array[x][y]==target)    return true;
            if(array[x][y]<target)    ++y;
            else --x;
        }
        return false;
    }
};