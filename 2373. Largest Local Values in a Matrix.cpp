class Solution {
private:
    int maxi(std::vector<std::vector<int>>& grid, int i, int j) {
        int maxa = INT_MIN;
        for (int x = i; x < i + 3; x++) {
            for (int y = j; y < j + 3; y++) {
                maxa = std::max(grid[x][y], maxa);
            }
        }
        return maxa;
    }
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> v(n - 2, std::vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                v[i][j] = maxi(grid, i, j);
            }
        }
        return v;
    }
};
