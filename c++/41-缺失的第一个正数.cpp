class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto pos=lower_bound(nums.begin(), nums.end(), 1);
        if (pos == nums.end()||*pos!=1) {
            return 1;
        }
        else {
            for (; pos+1 != nums.end(); pos++) {
                if (*pos +1!= *(pos + 1) &&*pos!=*(pos+1)) {
                    return *pos + 1;
                }
            }
        }
        return nums[nums.size()-1] + 1;
    }
};