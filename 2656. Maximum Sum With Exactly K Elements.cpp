class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        int mex=INT_MIN;
        for(auto i:nums){
            mex=max(mex,i);
        }
        int sum=0;
        // int num=nums[nums.size()-1];
        for(int i=0;i<k;i++){
            sum+=mex;
            mex++;


        }
        return sum;
        
    }
};
