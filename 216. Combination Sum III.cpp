class Solution {
private:
    void helper(int k, int target, int indx,vector<int>& ds,vector<vector<int>>& ans,vector<int>& arr){
        if(indx==arr.size()){
            if(ds.size()==k&& target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[indx]<=target){
            ds.push_back(arr[indx]);
            helper(k,target-arr[indx],indx+1,ds,ans,arr);
            ds.pop_back();
            
        }
        helper(k,target,indx+1,ds,ans,arr);
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> a;

        for(int i=1;i<10;i++){
            a.push_back(i);
        }
        helper(k, n,0,ds,ans,a);
        return ans;
        
    }
};
