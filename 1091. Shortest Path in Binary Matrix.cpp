class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;

       
        dis[0][0] = 0;
        q.push({1, {0, 0}});

        int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; 

        while (!q.empty()) {
            int wt = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

          
            if (row == n-1 && col == n-1) return wt;

            for (int i = 0; i < 8; i++) {
                int delrow = row + dr[i];
                int delcol = col + dc[i];

                if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < n && grid[delrow][delcol] == 0 && dis[delrow][delcol] > wt + 1) {
                    dis[delrow][delcol] = wt + 1;
                    q.push({dis[delrow][delcol], {delrow, delcol}});
                }
            }
        }

    
        return -1;
    }
};
