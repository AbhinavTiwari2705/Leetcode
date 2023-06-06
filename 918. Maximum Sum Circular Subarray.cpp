class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxLinear = kadane(nums); // Maximum subarray sum in linear array
        int totalSum = 0;
        int maxCircular;
        
        // Calculate total sum and find the maximum element in the array
        int maxElement = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
            maxElement = max(maxElement, nums[i]);
        }
        
        if (maxElement < 0) {
            return maxElement; // All elements are negative, return the maximum element
        }
        
        // Invert the sign of each element
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = -nums[i];
        }
        
        maxCircular = totalSum + kadane(nums); // Maximum subarray sum in circular array   || here the kadane is found for the lowest sum by reversing sign of the digits
        
        // Return the maximum of maxLinear and maxCircular
        return max(maxLinear, maxCircular);
    }
    
private:
    int kadane(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};
