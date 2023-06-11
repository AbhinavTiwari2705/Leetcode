class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int miss=1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==miss){
                miss++;
            }
        }
        return miss;
        
    }
};
