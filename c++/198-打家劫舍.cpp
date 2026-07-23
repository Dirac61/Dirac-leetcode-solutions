class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> v;
        v.push_back(0);
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            v.push_back(v[i - 1] + nums[i]);
            v[i + 1] = max(v[i +1], v[i ]);
        }
        return *(v.end()-1);
    }
};