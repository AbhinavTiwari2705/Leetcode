class Solution {
public:
    int arrangeCoins(int n) {
        return static_cast<int>((sqrt(8 * static_cast<double>(n) + 1) - 1) / 2);
    }
};
