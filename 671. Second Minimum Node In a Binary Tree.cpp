class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int firstMin = -1;
        int secondMin = -1;
        dfs(root, firstMin, secondMin);
        return secondMin;
    }

private:
    void dfs(TreeNode* node, int& firstMin, int& secondMin) {
        if (!node) {
            return;
        }

        if (firstMin == -1) {
            firstMin = node->val;
        } else if (node->val < firstMin) {
            secondMin = firstMin;
            firstMin = node->val;
        } else if (node->val > firstMin && (secondMin == -1 || node->val < secondMin)) {
            secondMin = node->val;
        }

        dfs(node->left, firstMin, secondMin);
        dfs(node->right, firstMin, secondMin);
    }
};
