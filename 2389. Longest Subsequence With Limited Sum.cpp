#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
       
        sort(nums.begin(), nums.end());

      
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<int> result;
        for (const auto& query : queries) {
       
            int max_length = upper_bound(prefix.begin(), prefix.end(), query) - prefix.begin();
            result.push_back(max_length);
        }

        return result;
    }
};
