class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {

     int n=interval.size();
     sort(interval.begin(),interval.end());
     vector<vector<int>> ans;
     for(int i=0;i<n;i++)
     {
         if(i==0 || ans.back()[1]<interval[i][0])
         {
             ans.push_back(interval[i]);
         }
         else{
             ans.back()[1]=max(ans.back()[1],interval[i][1]);
         }
     }
     return ans;

    }
};
