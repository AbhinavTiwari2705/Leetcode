class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return Build(nums, 0, nums.size() - 1);
    }

    TreeNode* Build(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;

        int maxIndex = start;
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);

        root->left = Build(nums, start, maxIndex - 1);
        root->right = Build(nums, maxIndex + 1, end);

        return root;
    }
};
