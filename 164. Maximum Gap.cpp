class Solution {
public:
    int maximumGap(vector<int>& n) {
        sort(n.begin(),n.end());
        int mex=0;
        if(n.size()==1){
            return 0;
        }

        for(int i=1;i<n.size();i++){
            int ans=n[i]-n[i-1];
            mex=max(mex,ans);
        }

        return mex;
        
    }
};
