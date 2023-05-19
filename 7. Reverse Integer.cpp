class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;
        
        while (x) {
            reversed = reversed * 10 + x % 10;
            x = x / 10;
        }
        
        if (reversed > INT_MAX || reversed < INT_MIN) {
            return 0;
        }
        
        return reversed;
    }
};
