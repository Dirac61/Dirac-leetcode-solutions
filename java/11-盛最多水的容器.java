class Solution {
    public int maxArea(int[] height) {
        int max=0;
        int max_h=0;
        int left=0;
        int right=height.length-1;
        for(;left<right;){
            int a=(right-left)*Math.min(height[left],height[right]);
            if(a>max){
                max=a;
            }
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return max;
    }
}