class Solution {
private:
    void calcXOR(vector<int>& nums, int idx, int curXOR, int& totalSum) {
        if (idx == nums.size()) {
            totalSum += curXOR;
            return;
        }
        
        // Include the current element in the XOR calculation
        calcXOR(nums, idx + 1, curXOR ^ nums[idx], totalSum);
        
        // Exclude the current element from the XOR calculation
        calcXOR(nums, idx + 1, curXOR, totalSum);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int totalSum = 0;
        calcXOR(nums, 0, 0, totalSum);
        return totalSum;
    }
};
