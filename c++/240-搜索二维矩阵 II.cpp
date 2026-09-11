class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix[0].size()-1;
        int y = 0;
        for (; x >= 0 && y <matrix.size() ;) {
            if (matrix[y][x] == target) {
                return true;
            }
            else if (matrix[y][x] < target) {
                y++;
            }
            else {
                x--;
            }
        }
        return false;
    }
};