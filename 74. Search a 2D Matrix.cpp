class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
        
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n= arr.size();
        int m = arr[0].size();

        int low =0;
        int high=n*m-1;

        

        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col= mid%m;

            if(arr[row][col]==target) return true;

            if(arr[row][col]>target) high=mid-1;
            else low=mid+1;
        }
        return 0;
    }
};
