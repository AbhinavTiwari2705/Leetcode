#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        // Find the first element that is greater than the next one from the left
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                mini = min(mini, nums[i + 1]);
            }
        }

        // Find the first element that is less than the previous one from the right
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                maxi = max(maxi, nums[i - 1]);
            }
        }

        int i, j;

        // Find the first index from the left where the element is greater than mini
        for (i = 0; i < n && nums[i] <= mini; i++);

        // Find the first index from the right where the element is less than maxi
        for (j = n - 1; j >= 0 && nums[j] >= maxi; j--);

        return max(0, j - i + 1);
    }
};
