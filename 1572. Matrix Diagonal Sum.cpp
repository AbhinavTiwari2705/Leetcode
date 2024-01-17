// Ap -01 


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n= mat.size()-1;
        int ans=0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if (i == j || i + j == n) {
                    ans += mat[i][j];
                }
            }

        }return ans;
    }
};


// Ap-02

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size() - 1;
        int ans = 0;
        
        for (int i = 0, j = 0; i < n + 1; i++, j++) {
            ans += mat[i][j];
            
            if (i != n - i) {  
                ans += mat[n - i][j];
            }
        }
        
        return ans;
    }
};
