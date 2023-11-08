class Solution {
public:
    int maxDepth(string s) {
        int count=0,mex=0;
        stack <char> st;
        for(auto i : s){
            if(i=='('){
                st.push(i);
                count++;
                mex=max(count,mex);
            }
            else if(i==')'){
                st.pop();
                count--;
            }

        }
        return mex;

        
    }
};
