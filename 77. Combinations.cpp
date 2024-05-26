class Solution {
private:
    void helper(int n, int k, int start, vector<int>& ds, vector<vector<int>>& ans) {
        if (ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        for (int i = start; i <= n; ++i) {
            ds.push_back(i);
            helper(n, k, i + 1, ds, ans);
            ds.pop_back(); 
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        helper(n, k, 1, ds, ans);
        return ans;
    }
};
