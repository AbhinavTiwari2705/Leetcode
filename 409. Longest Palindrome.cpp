// class Solution {
// public:
//     int longestPalindrome(string s) {
//         unordered_map<char,int> mep;
//         int count=1;
//         for(auto i:s){
//             mep[i]++;
//         }
//         for(auto i:mep){
//             if(i.second>1&&i.second%2==0){
//                 count+=i.second;
//             }
//             else if(i.second>1&&i.second%2!=0){
//                 count+=i.second;
//                 count=count-1;
//             }

//         }
//         if(count>s.size()) return s.size();
//         return count;
//     }
// };

class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char, int> ump;
        for(char ch : s) {
            ump[ch]++;
            if (ump[ch] % 2 == 1)
                oddCount++;
            else    
                oddCount--;
        }
        if (oddCount > 1)
            return s.length() - oddCount + 1;
        return s.length();
    }
};
