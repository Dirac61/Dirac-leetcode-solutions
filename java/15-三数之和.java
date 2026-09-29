class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;nums[i]<=0&&i<nums.length-2;){
            int left=i+1;
            int right=nums.length-1;
            for(;left<right;){
                if(nums[i]+nums[left]+nums[right]==0){
                    List<Integer> list=new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[left]);
                    list.add(nums[right]);
                    res.add(list);
                    left++;
                    while(left<right&&nums[left]==nums[left-1]){
                        left++;
                    }
                }
                else if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                    while(left<right&&nums[left]==nums[left-1]){
                        left++;
                    }
                }
                else{
                    right--;
                    while(left<right&&nums[right]==nums[right+1]){
                        right--;
                    }
                }
            }
            i++;
            while(i<nums.length-2&&nums[i]==nums[i-1]){
                i++;
            }
        }
        return res;
    }
}