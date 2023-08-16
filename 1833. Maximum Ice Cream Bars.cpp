class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count=0;
        sort(costs.begin(),costs.end());
        for(int i:costs){
            if(i<=coins){
                coins-=i;
                count++;
            }
            
        }
        return count;
        
    }
};
