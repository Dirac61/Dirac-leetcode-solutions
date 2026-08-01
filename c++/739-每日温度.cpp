class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res;
        res.resize(temperatures.size());
        for (int i = 0; i < temperatures.size(); ) {
            if (s.empty()) {
                s.push(i);
                i++;
                continue;
            }
            if (temperatures[i] > temperatures[s.top()]) {
                res[s.top()] = i - s.top();
                s.pop();
                continue;
            }
            else {
                s.push(i);
            }
            i++;
        }
        return res;
    }
};