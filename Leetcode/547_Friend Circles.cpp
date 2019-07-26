class UF{
public:
    UF(int size) : _count(size), _id(size), _weight(size, 1) {
        for (int i = 0; i < size; ++i) {
            _id[i] = i;
        }
    }
    
    bool connect(int a, int b) {
        int r1 = root(a);
        int r2 = root(b);
        if (r1 == r2) return false;
        if (_weight[r1] < _weight[r2]) {
            _id[r1] = r2;
            _weight[r2] += _weight[r1];
        } else {
            _id[r2] = r1;
            _weight[r1] += _weight[r2];
        }
        --_count;
        return true;
    }
    
    bool connected(int a, int b) {
        return root(a) == root(b);
    }
    
    int count() {
        return _count;
    }
private:
    int root(int a) {
        while (a != _id[a]) {
            _id[a] = _id[_id[a]];
            a = _id[a];
        }
        return a;
    }
private:
    vector<int> _id;
    vector<int> _weight;
    int _count;
};
class Solution {   
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        if(n==0)    return 0;
        UF uf(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i!=j&&M[i][j])   uf.connect(i,j);
            }
        }
        return uf.count();
    }
};