class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // Sort intervals based on their end times
        sort(intervals.begin(), intervals.end(), comp);

        int count = 0;
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev_end) {
                // Current interval overlaps with the previous one
                ++count;
            } else {
                // Non-overlapping, update prev_end
                prev_end = intervals[i][1];
            }
        }

        return count;
    }
};
