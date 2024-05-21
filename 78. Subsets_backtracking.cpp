class Solution {
private:
    void helper(vector<int>& nums,vector<int> & temp,vector<vector<int>>&ans,int ind){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            temp.push_back(nums[i]);
            helper(nums,temp,ans,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>> ans;
        helper(nums,temp,ans,0);
        return ans;
    }
};
