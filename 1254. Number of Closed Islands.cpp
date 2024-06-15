class Solution {
private:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int n, int m) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            for (auto dir : directions) {
                int newrow = nrow + dir.first;
                int newcol = ncol + dir.second;
                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && 
                    grid[newrow][newcol] == 0 && vis[newrow][newcol] == 0) {
                    vis[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0 && vis[i][0] == 0) bfs(grid, vis, i, 0, n, m);
            if (grid[i][m-1] == 0 && vis[i][m-1] == 0) bfs(grid, vis, i, m-1, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0 && vis[0][j] == 0) bfs(grid, vis, 0, j, n, m);
            if (grid[n-1][j] == 0 && vis[n-1][j] == 0) bfs(grid, vis, n-1, j, n, m);
        }

    
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (grid[i][j] == 0 && vis[i][j] == 0) {
                    cnt++;
                    bfs(grid, vis, i, j, n, m);
                }
            }
        }
        return cnt;
    }
};
