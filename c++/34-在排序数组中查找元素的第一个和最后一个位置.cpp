class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        if (left==nums.end()||*left != target) {
            return vector<int>{-1, -1};
        }
        auto right = lower_bound(nums.begin(), nums.end(), target + 1);
        return vector<int>{(int)(left-nums.begin()), (int)(right - nums.begin()-1)};
    }
};