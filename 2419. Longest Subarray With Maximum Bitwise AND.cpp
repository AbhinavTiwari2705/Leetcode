class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, maxi = nums[0], ans = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                cnt = 1;
                ans = 1;
            } 
            else if(nums[i] == maxi) {
                cnt++;
                ans = max(ans, cnt);
            } 
            else {
                cnt = 0;
            }
        }
        return ans;
    }
};
