class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int ans = 0, mex = 0;
        while (i < j)
        {
            int men = min(height[i], height[j]);

            
            ans = men * abs((i - j));
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
            mex = max(mex, ans);
        }
        return mex;
    }
};
