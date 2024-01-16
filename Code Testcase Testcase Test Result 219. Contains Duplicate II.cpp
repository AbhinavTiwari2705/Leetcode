class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int,int> mep;
         
        for(int i=0;i<nums.size();i++){
            if(mep.find(nums[i])!=mep.end()){
                if(abs(mep[nums[i]]-i)<= k) return true;
            }
            mep[nums[i]]=i;
        }
        return false;
    }
};
