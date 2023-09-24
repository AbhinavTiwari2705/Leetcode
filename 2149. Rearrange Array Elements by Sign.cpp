class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int even=0;
        int odd=1;
        for(int num:nums){
            if(num>0){
                ans[even]=num;
                even+=2;
            }
            else{
                ans[odd]=num;
                odd+=2;
            }


        }
        return ans;
    }
};
