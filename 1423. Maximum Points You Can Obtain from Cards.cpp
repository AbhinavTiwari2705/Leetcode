class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum =0, mx = 0;
		
        for(int i=0; i<k; i++){
            mx += cardPoints[i];
        }
		
        sum = mx;
        
        for(int i =0; i<k; i++){
            sum = sum + cardPoints[n-i-1] - cardPoints[k-i-1];
            mx = max(mx, sum);
        } 
        return mx;
    }
};
