
class Solution {
private:
    void putSmallest(stack<char>& sm, char c) {
        if (sm.empty() || sm.top() > c) {
            sm.push(c);
            return;
        }
        char ns = sm.top();
        sm.pop();
        putSmallest(sm, c);
        sm.push(ns);
    }

    void popSmallest(stack<char>& smallest, stack<char>& st) {
        if ((!smallest.empty() && !st.empty()) && (smallest.top() == st.top())) {
            smallest.pop();
            st.pop();
            return;
        }

        char c = st.top();
        st.pop();
        popSmallest(smallest, st);
        st.push(c);
    }

public:
    string clearStars(string s) {
        stack<char> st;
        stack<char> smallest;

        for (int i=0;i<s.size();i++) {
            if (s[i] != '*') {
                st.push(s[i]);
                putSmallest(smallest, s[i]);
            } else {
                popSmallest(smallest, st);
            }
        }

        if (st.empty()) return "";

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

