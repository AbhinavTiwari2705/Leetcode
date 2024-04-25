class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        long long total = 1<<n;

        vector<vector<int>> ans;

        for(long long k=0;k<total;k++){
            vector<int> subset;
            for(int i=0;i<n;i++){
                if( k & (1<<i)){  
                    subset.push_back(nums[i]);
                }

            }
            ans.push_back(subset);
        }
        return ans;
    }
};
