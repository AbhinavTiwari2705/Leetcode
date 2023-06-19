class Solution {
public:
    int mySqrt(int x) {
        int s=1,e=x;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(mid==x/mid){
                return mid;
            }
            else if(mid>x/mid){
                e=mid-1;

            }
            else{
                s=mid+1;
            }
        }
        return e;
    }
};
