class Solution {
private:
    unordered_map<int, int> helper(vector<int> v) {
        unordered_map<int, int> mep;
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0; i < v.size(); i++) {
            mep[v[i]] = i + 1;
        }
        return mep;
    }

public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> mep;
        vector<string> v;
        mep = helper(score);
        for (auto i : score) {
            if (mep[i] == 1) v.push_back("Gold Medal");
            else if (mep[i] == 2) v.push_back("Silver Medal");
            else if (mep[i] == 3) v.push_back("Bronze Medal");
            else {
                v.push_back(to_string(mep[i]));
            }
        }
        return v;
    }
};
