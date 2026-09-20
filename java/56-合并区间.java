class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> list=new ArrayList<>();
        Arrays.sort(intervals,(a,b)->{
            return a[0]-b[0];
        });
        for(int i=0;i<intervals.length;i++){
            int right=intervals[i][1];
            int left=intervals[i][0];
            if(list.size()==0||list.get(list.size()-1)[1]<left){
                list.add(new int[]{left,right});
            }
            else{
                list.get(list.size()-1)[1]=Math.max(right,list.get(list.size()-1)[1]);
            }
        }
        return list.toArray(new int[list.size()][2]);
    }
}