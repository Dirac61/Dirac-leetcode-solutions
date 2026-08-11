class Solution {
public:
    vector<string> res;
    int n;
    vector<string> generateParenthesis(int n) {
        string s;
        this->n = n;
        backtrack(s, 0, 0);
        return res;
    }
    void backtrack(string& s, int left, int right) {
        if (right == n) {
            res.push_back(s);
            return;
        }
        if (left == right) {
            s += '(';
            backtrack(s, left + 1, right);
            s.pop_back();
        }
        else {
            if (left < n) {
                s += '(';
                backtrack(s, left + 1, right);
                s.pop_back();
            }

            s += ')';
            backtrack(s, left, right + 1);
            s.pop_back();
        }
    }
};