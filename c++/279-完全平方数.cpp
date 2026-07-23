class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i <= n; i++) {
            int min = INT_MAX;
            for (int j = 1; j*j <= i; j++) {
                int a=1 + v[i - j * j];
                min = min < a ? min : a;
            }
            v.push_back(min);
        }
        return v[n];
    }
};