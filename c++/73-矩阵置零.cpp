class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int line=-1;
        int row = -1;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                row = i;
                break;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                line = i;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = matrix.size() - 1; i > 0; i--) {
            if (matrix[i][0] == 0) {
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }
        for (int i = matrix[0].size() - 1; i > 0; i--) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (row != -1) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][0] = 0;
            }
        }
        if (line != -1) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
    }
};