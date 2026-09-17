class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        vector<int> pre;
        vector<int> tail;
        pre.resize(nums.size(), 0);
        tail.resize(nums.size(), 0);
        pre[0] = nums[0];
        tail[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = nums[i] * pre[i - 1];
            tail[nums.size() - 1 - i] = tail[nums.size() - i] * nums[nums.size() - 1 - i];
        }
        answer.push_back(tail[1]);

        for (int i = 1; i < nums.size()-1; i++) {
            answer.push_back(pre[i - 1] * tail[i + 1]);
        }
        answer.push_back(pre[nums.size() - 2]);
        // cout<<pre[nums.size() - 1];
        return answer;
    }
};