class Solution {
    public int subarraySum(int[] nums, int k) {
        int[] pre=new int[nums.length+1];
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0,1);
        int res = 0;
        for (int i = 1; i <= nums.length; i++) {
            pre[i]=pre[i-1]+nums[i-1];
            if(map.containsKey(pre[i])) {
                map.put(pre[i], map.get(pre[i]) + 1);
            }
            else{
                map.put(pre[i],1);
            }
        }
        for(int i=0;i<=nums.length;i++){
            if(map.containsKey(k+pre[i])){
                res+=map.get(k+pre[i]);
            }
            if(k==0){
                res--;
            }
            map.put(pre[i],map.get(pre[i])-1);
        }
        return res;
    }
}