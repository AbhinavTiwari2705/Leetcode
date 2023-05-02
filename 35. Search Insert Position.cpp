class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int s = 0;
        int l = nums.size() - 1;

        while (s <= l)
        {
            int mid = s + (l - s) / 2;
            if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else if (nums[mid] > target)
            {
                l = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return s;
    }
};
