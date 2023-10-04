class Solution {
    public int maxSubArray(int[] a) {
        int curr_sum=0;
        int max_sum=a[0];
        
        for(int i=0;i<a.length;i++){
            curr_sum+=a[i];
            
            if(curr_sum>max_sum){
                max_sum=curr_sum;
            }
            if(curr_sum<0){
                curr_sum=0;
            }
          
            
        }
        
        
        
      
         
        // Your code here
        return max_sum;
    }
}
