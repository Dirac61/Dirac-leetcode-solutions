class Solution {
public:
    vector<vector<int>> res{ {1} };
    vector<vector<int>> generate(int numRows) {
        for (int i = 1; i < numRows; i++) {
            vector<int> v;
            for (int j = 0; j <= i; j++) {
                int a = 0;
                if (j > 0) {
                    a += res[i - 1][j - 1];
                }
                if (j < i) {
                    a += res[i - 1][j ];
                }
                v.push_back(a);
            }
            res.push_back(v);
        }
        return res;
    }
};