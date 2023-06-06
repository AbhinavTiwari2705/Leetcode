class Solution {
public:

    int kadene(vector<int>& nums){
        int sum=0;int mex=INT_MIN;
        int s=nums.size();

        for(int i=0;i<s;i++){
            sum+=nums[i];
            mex=max(mex,sum);
            if(sum<0){
                sum=0;
            }
        }
        return mex;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int p=kadene(nums); int s=nums.size();

        for(int i=0;i<s;i++){
            nums[i]*=-1;
        }
        int n=kadene(nums);


        return max(p,n);

        
    }
};
