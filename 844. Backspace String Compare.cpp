class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> qt;

        for (char c : s) {
            if (c == '#' && !st.empty()) {
                st.pop();
            } else if (c != '#') {
                st.push(c);
            }
        }

        for (char c : t) {
            if (c == '#' && !qt.empty()) {
                qt.pop();
            } else if (c != '#') {
                qt.push(c);
            }
        }

        if (st.size() != qt.size()) {
            return false;
        }

        while (!st.empty()) {
            if (st.top() != qt.top()) {
                return false;
            }
            st.pop();
            qt.pop();
        }

        return true;
    }
};
