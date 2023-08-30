class Solution {
private:
    bool isVowels(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;

        while(i<j){
            if(isVowels(s[i])&&isVowels(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;

            }
            if(!isVowels(s[i])) i++;
            if(!isVowels(s[j])) j--;
        }
        return s;
        
        
    }
};
