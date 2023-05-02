// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int s = 1;
        int l = n;
        int ans;
        while (l >= s)
        {
            int mid = s + (l - s) / 2;
            if (isBadVersion(mid))
            {
                ans = mid;
                l = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};