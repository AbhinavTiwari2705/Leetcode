class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0); 
        int m = rolls.size();
        int total = (mean * (n + m)) - sum;

        
        if (total < n || total > 6 * n) return {}; 

        vector<int> ans(n, 1);  
        total -= n; 

        for (int i = 0; i < n && total > 0; ++i) {
            int add = min(5, total);
            ans[i] += add;
            total -= add;
        }

        return ans;
    }
};
