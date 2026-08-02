class Solution {
public:
    string decodeString(string s) {
        stack<char> v;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                string temp;
                for (;;) {
                    if (v.top() == '[') {
                        v.pop();
                        reverse(temp.begin(), temp.end());
                        break;
                    }
                    temp += v.top();
                    v.pop();
                }
                int a = 0;
                for (int j = 0; !v.empty(); j++) {
                    if (v.top() >= 'A' && v.top() <= 'z') {
                        break;
                    }
                    a += (v.top() - '0') * pow(10, j);
                    v.pop();
                }
                string b = temp;
                for (int j = 1; j < a; j++) {
                    temp += b;
                }
                for (int j = 0; j < temp.size(); j++) {
                    v.push(temp[j]);
                }
            }
            else {
                v.push(s[i]);
            }
        }
        string res;
        res.resize(v.size());
        for (int i = res.size() - 1; !v.empty(); i--) {
            res[i] = v.top();
            v.pop();
        }
        return res;
    }
};