class Solution {
public:

    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),zerocnt=0,ans=INT_MIN;
        while(j<n){
            if(nums[j]==0){
                zerocnt++;
                
            }
            while(zerocnt>k){
                if(nums[i]==0){
                    zerocnt--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
