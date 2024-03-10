class Solution {
public:
    // Function to print array elements space-separated
    void printArray(int arr[], int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i];
            if (i < n - 1) {
                std::cout << " ";
            }
        }
    }
};
