class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mep;
        int mex = -1;

        for(int i = 0; i < nums.size(); i++) {
            mep[nums[i]]++;
        }
            for(int i = 0; i < nums.size(); i++) {
                if(mep.find(-nums[i]) != mep.end()) {
                    mex = max(mex, nums[i]);
                }
            }
        return mex;
    }
};
