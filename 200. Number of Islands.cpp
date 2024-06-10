class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1; 
        queue<pair<int, int>> q;
        q.push({row, col}); 
        int n = grid.size(); 
        int m = grid[0].size(); 

        // Directions for up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int currRow = q.front().first; 
            int currCol = q.front().second; 
            q.pop();
            
            for (auto dir : directions) {
                int newRow = currRow + dir.first; 
                int newCol = currCol + dir.second; 
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                    && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1; 
                    q.push({newRow, newCol}); 
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(grid, vis, row, col);
                }
            }
        }
        return cnt;
    }
};
