class Solution {
    public int maxSubArray(int[] nums) {
        int[] dp=new int[nums.length+1];
        for(int i=1;i<=nums.length;i++){
            dp[i]=Math.max(dp[i-1]+nums[i-1],nums[i-1]);
        }
        int max=dp[1];
        for(int i=2;i<=nums.length;i++){
            max=Math.max(max,dp[i]);
        }
        return max;
    }
}