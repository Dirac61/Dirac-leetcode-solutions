class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        stack<int> s;
        int max = 0;
        left.resize(heights.size(),-1);
        right.resize(heights.size(),-1);

        for (int i = 0; i < heights.size(); ) {
            if (s.empty()) {
                s.push(i);
                i++;
                continue;
            }
            if (heights[i] <= heights[s.top()]) {
                s.pop();
                continue;
            }
            else  {
                left[i] = s.top();
                s.push(i);
                i++;
            }

        }
        s = stack<int>();
        for (int i = heights.size() - 1; i >= 0; ) {
            if (s.empty()) {
                s.push(i);
                i--;
                continue;
            }
            if (heights[i] <= heights[s.top()]) {
                s.pop();
                continue;
            }
            else  {
                right[i] = s.top();
                s.push(i);
                i--;
            }

        }
        for (int i = 0; i < heights.size(); i++) {
            int r=right[i] == -1 ? heights.size() : right[i];
            int l=r - left[i]-1;
            int a = heights[i] * l;
            //cout<<r<<" "<<left[i]<<endl;
            if (max < a) {
                max = a;
            }
        }
        return max;
    }
};