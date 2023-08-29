class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = k;  
        int i = 0;
        string str;
        while (count > 0 && i < s.size()) { 
            if (s[i] == ' ') {
                count--;
            }
            str += s[i];
            i++;
        }
        
        if(!str.empty() && str.back() == ' ') {
            str.pop_back();
        }
        return str;
    }
};
