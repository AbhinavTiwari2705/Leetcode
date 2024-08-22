class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        string ans;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1});
            } else {
                
                auto prev = st.top();
                st.pop();
                st.push({s[i], prev.second + 1});
            }

           
            if (!st.empty() && st.top().second == k) {
                st.pop();
            }
        }

        
        while (!st.empty()) {
            auto curr = st.top();
            st.pop();
            while (curr.second--) {
                ans += curr.first;
            }
        }


        reverse(ans.begin(), ans.end());

        return ans; 
    }
};
