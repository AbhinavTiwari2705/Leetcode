class Solution {
public:
    int minimumChairs(string s) {
        int mexi=INT_MIN;
        int ans=0;
        for(auto i:s){
            if(i=='E'){
                ans++;
            }
            else{
                ans--;
            }
            mexi=max(ans,mexi);
        }
        return mexi;
    }
};
