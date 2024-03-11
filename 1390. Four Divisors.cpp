class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            int divisorSum = 0;
            int count = 0;
            for (int i = 1; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    divisorSum += i;
                    count++;
                    if (i != num / i) { 
                        divisorSum += num / i;
                        count++;
                    }
                }
                if (count > 4) break; 
            }
            if (count == 4) {
                result += divisorSum;
            }
        }
        return result;
    }
};
