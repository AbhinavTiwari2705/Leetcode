class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mep;
        int count = 0;

        for (auto i : allowed) {
            mep[i]++;
        }

        for (auto i : words) {
            bool isConsistent = true;
            for (auto j : i) {
                if (mep.find(j) == mep.end()) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) count++;
        }
        return count;
    }
};
