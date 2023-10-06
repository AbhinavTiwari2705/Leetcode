class Solution {
public:
    int minPartitions(string n) {
        int mex=0;
        for(auto i:n){
            int ans=i-'0';
            mex=max(mex,ans);
        }
        return mex;
    }
};
