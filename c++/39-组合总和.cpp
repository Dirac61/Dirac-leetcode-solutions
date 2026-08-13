class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    int target;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        backtrack(candidates, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, int pos) {
        for (int i = pos; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            if (sum == target) {
                res.push_back(path);
            }
            else if(sum<target){
                backtrack(candidates, i);
            }
            path.pop_back();
            sum -= candidates[i];
        }
    }
};