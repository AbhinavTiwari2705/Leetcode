class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int x=0;

        for(auto i: target){
            while(x<i-1){
                ans.push_back("Push");
                ans.push_back("Pop");
                x++;
            }
            ans.push_back("Push");
            x++;
        }
        return ans;
        
    }
};
