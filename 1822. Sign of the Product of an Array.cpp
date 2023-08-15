class Solution {
public:
    int arraySign(vector<int>& nums) 
    {

        int count_n = 0;

        for(auto it: nums)
        {
            if(it==0) return 0;

            if(it<0) count_n++;
        }

        return count_n%2?-1:1;
    }
};
