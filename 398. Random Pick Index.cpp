class Solution {
    vector<int>helper;
public:
    Solution(vector<int>& nums) {
        helper = nums;
    }
    
    int pick(int target) {
        int n = helper.size();
        while(true){
            int randIndex = rand()%n;
            if(helper[randIndex] == target){
                return randIndex;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
