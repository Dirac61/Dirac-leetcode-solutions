class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        auto v = vector<int>();
        res.push_back(v);
        backtrack(nums, v,0);
        return res;
    }
    void backtrack(vector<int>& nums, vector<int>& v,int i) {
        for (; i < nums.size(); i++) {
            v.push_back(nums[i]);
            res.push_back(v);
            backtrack(nums, v, i+1);
            v.pop_back();
        }
    }
};