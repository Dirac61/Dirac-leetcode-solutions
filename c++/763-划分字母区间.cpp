class Solution {
public:
    vector<int> partitionLabels(string s) {
        int left=0;
        int right=0;
        vector<int> res;
        vector<int> pre;
        pre.resize(26);
        for (int i = 0; i < 26; i++) {
            pre[i]=s.rfind('a'+i);
        }
        for (int i = 0; i < s.size(); i++) {
            right = max(pre[s[i] - 'a'], right);
            if (right == i) {
                res.push_back(right - left+1);
                right++;
                left = right;
            }
            if (right == s.size() - 1) {
                res.push_back(right - left + 1);
                return res;
            }
        }
        return res;
    }
};