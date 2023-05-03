class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        // if(nums.size()==1){
        //     return nums[0];
        // }

        // naive approch
        sort(nums.begin(), nums.end());
        set<int> s;

        for (auto num : nums)
        {
            s.insert(num);
        }
        auto it = s.begin();
        if (s.size() < 3)
        {
            auto max_it = max_element(s.begin(), s.end());
            return *max_it;
        }
        auto n = (s.size() - 3);
        advance(it, n);

        return *it;
    }
};