class Solution {
public:
    void sortColors(vector<int>& arr) {
        int h=arr.size()-1;
   int m=0;
   int l=0;

   while(m<=h){
      if(arr[m]==0){
         swap(arr[m],arr[l]);
         m++;
         l++;

      }
      else if(arr[m]==1){
         m++;
      }
      else{
         swap(arr[m],arr[h]);
         h--;
      }
   }

    }
};
