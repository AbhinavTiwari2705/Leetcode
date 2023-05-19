class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    set<int> rows,columns;
        int m = matrix.size();
        int n = matrix[0].size();
    // unordered_set<int> columns;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
            }
        }


    }

        for (int row : rows) {
            for (int j = 0; j < n; j++) {
                matrix[row][j] = 0;
        }
    }

        for (int col : columns) {
            for (int i = 0; i < m; i++) {
                matrix[i][col] = 0;
        }
    }
    }
};
