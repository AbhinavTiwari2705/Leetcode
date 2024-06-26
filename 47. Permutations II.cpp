class Solution {
private:
    vector<vector<int>> permutations;
    
    void permute(vector<int>& nums, int start)
    {
        if (start == nums.size() - 1) { permutations.push_back(nums); }
            
        unordered_set<int> seen;  
        for (int i = start; i < nums.size(); ++i)
        {
            if (seen.find(nums[i]) == seen.end())
            {
                swap(nums[start], nums[i]);
                permute(nums, start+1);
                swap(nums[start], nums[i]);  
                seen.insert(nums[i]);
            }
        }     
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        if (nums.size() < 2) { return {nums}; }
        permute(nums, 0);
        return permutations;
    }
};
