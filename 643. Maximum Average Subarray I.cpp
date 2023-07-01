class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int sum = 0;

        for (; i < k; i++) {
            sum += nums[i];
        }

        int j = 0;
        int n = nums.size();
        int maxSum = sum;

        while (i < n) {
            sum += nums[i] - nums[j];
            maxSum = max(maxSum, sum);
            i++;
            j++;
        }

        return static_cast<double>(maxSum) / k;
    }
};
