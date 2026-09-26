class Solution {
    public int trap(int[] height) {
        int[] diff=new int[height.length+1];
        int left=0;
        int right=height.length-1;
        int pre=0;
        int solid=0;
        for(int i=0;i<height.length;i++){
            solid+=height[i];
        }
        for(;left<=right;){
            int h=Math.min(height[left],height[right]);
            if(h>=pre){
                diff[left]+=h-pre;
                diff[right+1]+=pre-h;
                pre=h;
            }
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        int overall=0;
        int h=0;
        for(int i=0;i<diff.length;i++){
            h+=diff[i];
            overall+=h;
        }
        return overall-solid;
    }
}