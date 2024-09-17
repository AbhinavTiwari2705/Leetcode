class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mep;
        vector<string> ans;
        stringstream ss(s1 + " " + s2);
        string word;
        
        while (ss >> word) {
            mep[word]++;
        }
        
        for (auto &it : mep) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};
