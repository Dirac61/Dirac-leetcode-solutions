class Solution {
public:
    int findMin(vector<int>& nums) {
        int pos=f(nums);
        int a=5001;
        if(pos<nums.size()-1){
            pos++;
            a=nums[pos];
        }

        if(nums[0]<a){
            return nums[0];
        }
        return a;
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