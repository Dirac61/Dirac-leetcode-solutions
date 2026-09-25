class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left=0;
        int right=0;
        int max=0;
        int[] count=new int[128];
        for(;right<s.length();){
            if(count[s.charAt(right)]==0){
                count[s.charAt(right)]++;
                right++;
                max=Math.max(max,right-left);
            }
            else{
                for(;;left++){
                    if(s.charAt(left)==s.charAt(right)){
                        left++;
                        count[s.charAt(left-1)]--;
                        break;
                    }
                    else{
                        count[s.charAt(left)]--;
                    }
                }
            }
        }
        return max;
    }
}