class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        ArrayList<Integer> res=new ArrayList<>();
        int[] count=new int[26];
        int[] count_s=new int[26];
        for(int i=0;i<p.length();i++){
            count[p.charAt(i)-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(i==0){
                for(int j=i;j<i+p.length()&&j<s.length();j++){
                    count_s[s.charAt(j)-'a']++;
                }
            }
            else if(i+p.length()<=s.length()){
                count_s[s.charAt(i-1)-'a']--;
                count_s[s.charAt(i+p.length()-1)-'a']++;
            }
            else{
                break;
            }

            if(Arrays.equals(count,count_s)){
                res.add(i);
            }
        }
        return res;
    }
}