class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        vector<int> ans;
        for (int num : nums) {
            counts[num]++;
        }
        for (const auto& pair : counts) {
            if (pair.second > nums.size() / 3) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};
