class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int e = s.size() - 1;

        while(st<=e) {
            if (!isalnum(s[st])) st++;
            else if (!isalnum(s[e])) e--;

            else if (toupper(s[st]) != toupper(s[e])) return false;

            else{
                st++;
                e--;

            }

        }

        return true;
    }
};
