class Solution {
public:
    int maxProduct(vector<int>& nums) {

        long long sum{1},mex{nums[0]};
        if(nums.size()==1){
            return nums[0];
        }


        for(int i=0;i<nums.size();i++){
            
            sum*=nums[i];
            mex=max(mex,sum);
            if(sum==0){
                sum=1;
            }


        }

        sum=1;

        

        for(int i=nums.size()-1;i>0;i--){
            
            sum*=nums[i];
            mex=max(mex,sum);
            if(sum==0){
                sum=1;
            }


        }
        return mex;
         
        
    }
};
