class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& a) {
    
        for (int i = 0; i < a.size(); i++) {
            reverse(a[i].begin(), a[i].end());
        }


        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                a[i][j] = (a[i][j] == 0) ? 1 : 0;
            }
        }

        return a;
    }
};
