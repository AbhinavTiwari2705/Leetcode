class Solution {
public:
    
    void exploreSubsets(vector<int> &nums, int index, int k, unordered_map<int, int> &frequencyMap, int &count) {
        
        if (index == nums.size()) {
            count++;
            return;
        }
        if (!frequencyMap[nums[index] - k] && !frequencyMap[nums[index] + k]) {
            frequencyMap[nums[index]]++;
            exploreSubsets(nums, index + 1, k, frequencyMap, count);
            frequencyMap[nums[index]]--;
        }

        
        exploreSubsets(nums, index + 1, k, frequencyMap, count);
    }
    
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> frequencyMap;
        exploreSubsets(nums, 0, k, frequencyMap, count);
        return count - 1; 
    }
};
