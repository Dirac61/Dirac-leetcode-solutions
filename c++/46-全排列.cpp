class Solution {
public:
    vector<vector<int>> res;
    int count = 0;
    vector<vector<int>> permute(vector<int>& nums) {

        auto v = vector<int>();
        backtrack(nums,v);
        return res;
    }
    void backtrack(vector<int> &nums,vector<int> &v) {
        for (int i = 0; i < nums.size(); i++) {
            //res[count].push_back(nums[i]);
            if(v.size()>0&&i!=0){
                v.pop_back();
            }
            //cout<<"i: "<<i<<"size: "<<nums.size()<<endl;
            v.push_back(nums[i]);
            int temp = nums[i];
            nums.erase(nums.begin() + i);
            if (nums.size() > 0) {
                backtrack(nums,v);
                nums.insert(nums.begin() + i, temp);
            }
            else {
                count++;
                res.push_back(v);
                nums.insert(nums.begin() + i, temp);
            }
        }
        if(v.size()>0){
                v.pop_back();
            }
    }
};