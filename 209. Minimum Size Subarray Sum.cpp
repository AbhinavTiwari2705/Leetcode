class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
        int mex=INT_MAX;
        int left=0;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            while(sum>=target){
                mex=min(mex,i-left+1);
                sum-=nums[left++];
            }

        }
        return (mex!=INT_MAX)?mex:0;
    }
};
