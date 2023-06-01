class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> l;
        vector<int> r;
        r.push_back(0);
        l.push_back(0);
        int sl{0};
        int rl{0};
        if (nums.size()==1){
            nums[0]=0;
            return nums;
        }
        int j= nums.size()-1;

        for(int i=0;i<nums.size()-1;i++){
            sl+=nums[i];
            rl+=nums[j];
            r.push_back(sl);
            l.push_back(rl);
            j--;

        }
        reverse(l.begin(), l.end());

        for(int i=0;i<nums.size();i++){
            nums[i]=abs(l[i]-r[i]);

        }     
        return nums;   
        
    }
};
