class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> mep;
        for (int i = 0; i < nums.size(); i++)
            
            
        {
            
            
            if (mep.find(target - nums[i]) != mep.end())
            {
                ans.push_back(mep[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mep[nums[i]] = i;
           
        }
        return ans;
    }
};
