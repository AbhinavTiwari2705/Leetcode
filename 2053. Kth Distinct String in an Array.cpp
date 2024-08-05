class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mep;

        for (auto& str : arr) {
            mep[str]++;
        }

        vector<string> unique;

        for (auto& entry : arr) {
            if (mep[entry] == 1) {
                unique.push_back(entry);
            }
        }

    
        if (k > unique.size()) return "";
  
        return unique[k - 1];
    }
};
