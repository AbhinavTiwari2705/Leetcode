class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        
        for (int num : nums) {
            if (frequencyMap.count(num) > 0) {
                frequencyMap[num]++;
            }
            else {
                frequencyMap[num] = 1;
            }
        }
        
        for (const auto& pair : frequencyMap) {
            if (pair.second > nums.size() / 2) {
                return pair.first;
            }
        }
        
        return -1; // No majority element found
    }
};
