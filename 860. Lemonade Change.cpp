class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;

        for(auto i:bills){
            if(i==5) five++;
            else if(i==10){
                if(five!=0){
                    ten++;
                    five--;
                }
                else{
                    return false;
                }

            }
            else{
                if(five&&ten){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five=five-3;
                }
                else{
                    return false;
                }

            }
        }
        return true;
    }
};
