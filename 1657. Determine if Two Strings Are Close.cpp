
class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        std::unordered_map<char, int> mep1;
        std::unordered_map<char, int> mep2;

        for (int i = 0; i < word1.size(); i++) {
            mep1[word1[i]]++;
        }

        for (int i = 0; i < word2.size(); i++) {
            mep2[word2[i]]++;
        }

        std::vector<int> vec1, vec2;

        for (auto i : mep1) {
            vec1.push_back(i.second);
        }

        for (auto i : mep2) {
            vec2.push_back(i.second);
        }

        std::sort(vec1.begin(), vec1.end());
        std::sort(vec2.begin(), vec2.end());

        std::set<char> set1, set2;

        for (auto i : mep1) {
            set1.insert(i.first);
        }

        for (auto i : mep2) {
            set2.insert(i.first);
        }

        return vec1 == vec2 && set1 == set2;
    }
};
