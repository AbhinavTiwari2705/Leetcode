class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_value = start ^ goal;
        
        int count = 0;
        while (xor_value > 0) {
            count += xor_value & 1;  
            xor_value >>= 1;        
        }
        
        return count;
    }
};
