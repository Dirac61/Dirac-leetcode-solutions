class Solution {
public:
    vector<int> v{1,2};
    int climbStairs(int n) {
        for (int i = 2; i < n; i++) {
            v.push_back(v[i - 1] + v[i - 2]);
        }
        return v[n - 1];
    }
};