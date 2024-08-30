//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void solve(int col, vector<int>& pos, vector<vector<int>>& ans, vector<int>& leftrow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(pos);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                pos.push_back(row + 1);
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                
                solve(col + 1, pos, ans, leftrow, upperDiagonal, lowerDiagonal, n);
                
                // Backtracking
                pos.pop_back();
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> pos;  // To store the position of queens
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, pos, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};
   
    


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
