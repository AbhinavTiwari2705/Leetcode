class Solution {
public:
    int balancedStringSplit(string s) {
        int scount=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')scount++;
            if(s[i]=='L')scount--;
            if(scount==0)ans++;
        }
        return ans;
    }
};
