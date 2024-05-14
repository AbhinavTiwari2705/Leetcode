class Solution {
private:
    int helper(vector<vector<int>>& grid, int i, int j, int row, int col) {
        // Boundary conditions and checking if the current cell has no gold.
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) return 0;

        int temp = grid[i][j];
        grid[i][j] = 0;  // Mark as visited by setting it to 0.

        // Recursively explore all four directions.
        int up = helper(grid, i - 1, j, row, col);
        int down = helper(grid, i + 1, j, row, col);
        int left = helper(grid, i, j - 1, row, col);
        int right = helper(grid, i, j + 1, row, col);

        grid[i][j] = temp;  // Unmark the cell (backtrack).

        // Return the maximum gold collected from the current cell.
        return temp + max(max(up, down), max(left, right));
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxGold = 0;

        // Try to collect gold starting from each cell.
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, helper(grid, i, j, row, col));
                }
            }
        }

        return maxGold;
    }
};
