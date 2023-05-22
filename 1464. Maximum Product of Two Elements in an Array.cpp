class Solution {
public:
    int maxProduct(vector<int>& a) {
        int k{-1},l{0},n=a.size();
        for (int i=1;i<n;i++){
            if(a[i]>a[l]){
                k=l;
                l=i;
            }
            else if(a[i]<a[l]){
                if(k==-1||a[k]<a[i]){
                    k=i;
                }
            }
            else{
                k=i;
            }
        }
        return (a[l]-1)*(a[k]-1);
    }
};
