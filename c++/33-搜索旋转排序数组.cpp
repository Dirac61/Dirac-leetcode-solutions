class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = f(nums);
        auto i = lower_bound(nums.begin(), nums.begin() + pos+1, target);
        if (i != (nums.begin() + pos+1)&&*i==target) {
            return i - nums.begin();
        }
        i = lower_bound(nums.begin() + pos+1, nums.end(), target);
        if (i != nums.end()&&*i==target) {
            return i - nums.begin();
        }
        return -1;
    }
    int f(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        for (; left < right;) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[left]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};