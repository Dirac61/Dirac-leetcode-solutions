class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int row=0;
        int i = 0;
        int j = 0;
        for (;;) {
            v.push_back(matrix[i][j]);
            if (v.size() == matrix.size() * matrix[0].size()) {
                break;
            }
            if (i == row && j != matrix[0].size() - 1 - row) {
                j++;
            }
            else if (j == matrix[0].size() - 1 - row && i != matrix.size() - 1 - row) {
                i++;
            }
            else if (i == matrix.size() - 1 - row && j != row) {
                j--;
            }
            else if (j == row && i != row + 1) {
                i--;
            }
            else {
                row++;
                j++;
            }

        }
        return v;
    }
};