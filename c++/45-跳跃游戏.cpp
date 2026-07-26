class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int max = 0;
        int temp = 0;
        int step = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i + nums[i] > temp) {
                temp = i + nums[i];
            }
            if (i == max) {
                max = temp;
                step++;
                if (max >= nums.size() - 1) {
                    return step;
                }
            }
        }
        return step;
    }
};