class Solution {
public:
    string finalString(string s) {
        int count=0;
        string ans;
        for(auto i : s){
            if(i=='i'){
                reverse(ans.begin(),ans.end());
            }
            else{
                ans+=i;
                count++;
            }


        }
        return ans;
        
    }
};
