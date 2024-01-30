class Solution {
public:
    int minimumSum(int num) {
        int v[4];
        v[0] = num%10; 
        num/=10;
        v[1] = num%10; 
        num/=10;
        v[2] = num%10; 
        num/=10;
        v[3] = num%10; 
        num/=10;
        sort(v, v+4);

        int res = 0;
        int t1 = v[0] *10 + v[2];
        int t2 = v[1] *10 + v[3];
        res = t1+t2;
        return res;
    }
};
