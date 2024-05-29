class Solution {
public:
    bool checkValidString(const std::string& s) {
        stack<int> leftID;
        stack<int> starID;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(') {
                leftID.push(i);
            } else if (ch == '*') {
                starID.push(i);
            } else {
                if (leftID.empty() && starID.empty()) {
                    return false;
                }
                if (!leftID.empty()) {
                    leftID.pop();
                } else {
                    starID.pop();
                }
            }
        }

        while (!leftID.empty() && !starID.empty()) {
            if (leftID.top() > starID.top()) {
                return false;
            }
            leftID.pop();
            starID.pop();
        }

        return leftID.empty();
    }
};
