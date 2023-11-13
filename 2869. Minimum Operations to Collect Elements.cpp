class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int count = 0;
        unordered_set<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            count++;
            if(nums[i]<=k)st.insert(nums[i]);
            
            if (st.size() == k) {
                return count;
            }
            
        }
        return -1;  
    }
};
