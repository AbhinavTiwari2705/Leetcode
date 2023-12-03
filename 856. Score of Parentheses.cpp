class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0,depth=0;
        char prev='(';

        for(auto i:s){
            if(i=='(') depth++;
            else{
                depth--;
                if(prev=='(') {
                    ans+=pow(2,depth);
                }
                
            }
            prev=i;
        }
        return ans;
        
    }
};
