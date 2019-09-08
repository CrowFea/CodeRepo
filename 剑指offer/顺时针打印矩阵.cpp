class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int up=0,left=0,down=matrix.size()-1,right=matrix[0].size()-1;
        while(res.size()<matrix.size()*matrix[0].size()){
            for(int i=left;i<=right;++i)    res.push_back(matrix[up][i]);
            ++up;
            if(res.size()==matrix.size()*matrix[0].size())    break;
            for(int i=up;i<=down;++i)    res.push_back(matrix[i][right]);
            --right;
            if(res.size()==matrix.size()*matrix[0].size())    break;
            for(int i=right;i>=left;--i)    res.push_back(matrix[down][i]);
            --down;
            if(res.size()==matrix.size()*matrix[0].size())    break;
            for(int i=down;i>=up;--i)    res.push_back(matrix[i][left]);
            ++left;
        }
        return res;
    }
};