class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            if(i>9){
                while(i>0){
                    sum+=i%10;
                    i=i/10;
                }
            }
            else{
                sum+=i;
            }
        }
        for(int i:nums){
            sum-=i;
        }
        return abs(sum);
    }
};
