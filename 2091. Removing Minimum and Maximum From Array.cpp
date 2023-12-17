class Solution {
public:
    int minimumDeletions(vector<int>& A) {
int r = max_element(begin(A), end(A)) - begin(A), l = min_element(begin(A), end(A)) - begin(A), length = A.size();
        // int length=nums.size();

        if(r>l){
            swap(r,l);
        }
        return min({r+1+length-l,l+1,length-r});
        
    }
};
