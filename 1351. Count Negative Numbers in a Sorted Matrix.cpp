class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            int e = cols - 1;
            int s = 0;

            while (s <= e) {
                int mid = s + (e - s) / 2;

                if (grid[i][mid] < 0) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }

            count += cols - s;
        }

        return count;
    }
};
