class Solution {
private:
    bool isSafe(int i, int j, char c, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c) return false;
            if (board[k][j] == c) return false;
            if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isSafe(i, j, c, board)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
