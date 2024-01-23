class Solution {
public:
     int matrixSum(vector<vector<int>>& nums) {
         
        int ans = 0;
        int row = nums.size();
        int col = nums[0].size();
         for(int i = 0 ; i < row ; i++)
         {
            sort(nums[i].begin(),nums[i].end());
         }
        for(int i = 0 ; i < col ; i++)
        {
            int max = 0;
            for(int j = 0 ; j < row ; j++)
            {
                if(max < nums[j][i]) max = nums[j][i];
            }
            ans += max;
        }
        return ans;

    }
};
