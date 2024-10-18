class Solution {
public:
    int helper(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (amount < 0 || ind == coins.size()) return INT_MAX;

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int take = helper(ind, coins, amount - coins[ind], dp);
        if (take != INT_MAX) take += 1;

        int skip = helper(ind + 1, coins, amount, dp);

        return dp[ind][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int result = helper(0, coins, amount, dp);
        return (result == INT_MAX) ? -1 : result;
    }
};
