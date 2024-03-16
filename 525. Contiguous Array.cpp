class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mep;
        int sum=0;
        int longestStr=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==0?-1:1;
            if(sum==0){
                if(longestStr<i+1){
                    longestStr=i+1;
                }
            }
            else if(mep.find(sum)!=mep.end()){
                if(longestStr<i-mep[sum]){
                    longestStr=i-mep[sum];
                }

            }
            else{
                mep[sum]=i;
            }
        }
        return longestStr;
    }
};
