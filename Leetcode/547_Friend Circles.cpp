struct UF {
    UF(int n) {
        father.resize(n + 1);
        for (int i = 0; i < father.size(); ++i) {
            father[i] = i;
        }
    }
    bool Union(int a, int b) {
        int root1 = Find(a), root2 = Find(b);
        if (root1 != root2) {
            father[root2] = root1; //or father[root1] = root2;
            return true;
        }
        return false;
    }
    int Find(int k) {
        int i = k, j = k;
        while (i != father[i]) i = father[i]; // i is the root of k.
        //path comdense (to be continued)

        while (j != father[j]) {
            int tmp = father[j];
            father[j] = i;
            j = tmp;
        }
        return i;
    }
    vector<int> father;
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, int> index;
        int count = 0;
        for (int i = 0; i < pairs.size(); ++i) {
            if (index[pairs[i].first] == 0) {
                ++count;
                index[pairs[i].first] = count;
            }
            if (index[pairs[i].second] == 0) {
                ++count;
                index[pairs[i].second] = count;
            }
        }

        UF uf_set(count);
        for (int i = 0; i < pairs.size(); ++i) {
            uf_set.Union(index[pairs[i].first], index[pairs[i].second]);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            int root1 = uf_set.Find(index[words1[i]]), root2 = uf_set.Find(index[words2[i]]);
            if (root1 == 0 || root2 == 0 || root1 != root2) return false;
        }
        return true;
    }
};