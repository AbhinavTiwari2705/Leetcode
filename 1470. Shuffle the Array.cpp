class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int curr=0;
        int half=nums.size()/2;
        vector<int> v(nums.size());

        for(int i=0;i<half;i++){
            v[curr]=nums[i];
            curr+=2;

        }
        curr=1;
        for(int i=half;i<nums.size();i++){
            v[curr]=nums[i];
            curr+=2;

        }
        return v;
    }
};
