class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int count{0},mex{0};
        for(int i=0;i<s.size();i++){
            count=0;
            for(int j=0;j<s[i].size();j++){
                if(s[i][j]==' '){
                    count++;
                }
            }
            count++;
            mex=max(mex,count);
        }

        return mex;
        
    }
};

