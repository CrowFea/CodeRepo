class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> t;
        res.push_back(t);
        int left = 0, right = 1, len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1])    left = res.size() - len;
            else left = 0;
            right = res.size();
            len = right - left;
            for (int j = left; j < right; ++j) {
                t = res[j];
                t.push_back(nums[i]);
                res.push_back(t);
            }
        }
        return res;
    }
};