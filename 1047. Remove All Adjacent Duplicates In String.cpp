#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::stack<char> st;
        std::string ans;
        int count = 0;

        for (auto i : s) {
            if (!st.empty() && i == st.top()) {
                st.pop();
            } else {
                st.push(i);
                count++;
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        std::reverse(ans.begin(), ans.end());

        return ans;
    }
};
