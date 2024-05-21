
class Solution {
private:
    void helper(std::vector<int>& nums, std::set<std::vector<int>>& seto, std::vector<int>& temp, int ind) {
        seto.insert(temp);
        for (int i = ind; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(nums, seto, temp, i + 1);
            temp.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::set<std::vector<int>> seto;
        std::vector<std::vector<int>> ans;
        std::vector<int> temp;
        
        std::sort(nums.begin(), nums.end());
        
        helper(nums, seto, temp, 0);
        
        for (const auto& subset : seto) {
            ans.push_back(subset);
        }
        
        return ans;
    }
};
