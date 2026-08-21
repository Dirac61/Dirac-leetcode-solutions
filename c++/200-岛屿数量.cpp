class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    DFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void DFS(vector<vector<char>>& grid, int line, int row) {
        if (line<0||line>=grid.size()||row<0||row>=grid[0].size()||grid[line][row] == '0') {
            return;
        }
        grid[line][row] = '0';
        DFS(grid, line-1,  row);
        DFS(grid, line, row+1);
        DFS(grid, line+1, row);
        DFS(grid, line, row-1);
    }
};