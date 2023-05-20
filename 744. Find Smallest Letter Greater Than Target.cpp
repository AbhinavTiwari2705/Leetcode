class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int r=letters.size()-1,l=0;
        if (letters.back() <= target) return letters.front();
        

        while(l<r){
            int mid=l+(r-l)/2;
            if(letters[mid]>target){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return letters[l];
    }
};
