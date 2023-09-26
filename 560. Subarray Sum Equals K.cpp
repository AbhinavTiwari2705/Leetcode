class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mep;
        mep[0]=1;
        int count=0,presum=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int remove=presum-k;
            count+=mep[remove];
            mep[presum]++;
        }
        return count;
    }
};
