class Solution {
public:
    int findDelayedArrivalTime(int a, int d) {
        int sum= a+d;
        if(sum>=24) return sum%24;
        return sum;
    }
};
