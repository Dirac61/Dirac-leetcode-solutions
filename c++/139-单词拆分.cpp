class Solution {
public:
    unordered_set<string> set;
    vector<bool> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<bool>(s.size() + 1, false);
        dp[0] = true;
        for (string i : wordDict) {
            set.insert(i);
        }
        for (int i = 0; i < s.size(); i++) {
            f(s, i);
        }
        return dp.back();
    }
    void f(string s, int i) {
        for (int j = 0; j <= i; j++) {
            if (dp[j]) {
                if (set.find(s.substr(j, i - j + 1)) != set.end()) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
    }
};