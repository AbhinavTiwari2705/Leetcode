class Solution {
public:
bool ans[58];
    int numJewelsInStones(string j, string s) {
        
        int count{0};

        for(int i=0;i<j.size();i++){
            ans[j[i]-65]=true;
        }
        for(int i=0;i<s.size();i++){
            if(ans[s[i]-65]){
                count++;
            }
        }
        return count;
        
        
    }
};
