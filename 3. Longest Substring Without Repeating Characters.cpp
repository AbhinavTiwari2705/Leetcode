class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mep;
        int i = 0, j = 0, mex = 0;
        int n = s.size();

        while (j < n) {
            mep[s[j]]++;
            
            while (mep[s[j]] > 1) {
                mep[s[i]]--;
                i++;
            }
            
            mex = max(mex, j - i + 1);
            j++;
        }

        return mex;
    }
};
