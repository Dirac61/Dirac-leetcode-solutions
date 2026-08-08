class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = (int)matrix[0].size() - 1;
        for (;j>=0&&i<matrix.size();) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};