class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=10001;
        int max=0;
        for(int i:prices){
            if(i-min>max){
                max=i-min;
            }
            if(i<min){
                min=i;
            }
        }
        return max;
    }
};