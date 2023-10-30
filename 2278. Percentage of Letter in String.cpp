class Solution {
public:
    double percentageLetter(string s, char l) {
        int count = 0;
        for (auto i : s) {
            if (i == l) {
                count++;
            }
        }
        return (count*100) / s.size() ;
    }
};
