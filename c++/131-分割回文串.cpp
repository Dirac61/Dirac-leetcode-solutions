bool isSimplePalindrome(const string& str) {
    // 处理空字符串或空指针（C++中std::string不会为null，但兼容空字符串）
    if (str.empty()) {
        return true;
    }

    // 双指针法：左指针从头部，右指针从尾部开始比较
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        // 逐字符比较，只要不相等就不是回文
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    // 所有字符匹配，是回文
    return true;
}

class Solution {
public:
    vector<vector<string>> res;
    vector<string> v;
    vector<vector<string>> partition(string s) {
        backTrack(s, 0);
        return res;
    }
    void backTrack(string& s, int start) {
        for (int i = 1; i + start <= s.size(); i++) {
            string a = s.substr(start, i);
            if (isSimplePalindrome(a)) {
                v.push_back(a);
                if (i + start == s.size()) {
                    res.push_back(v);
                    v.pop_back();
                    return;
                }
                backTrack(s, start + i);
                v.pop_back();
            }
        }
    }
};