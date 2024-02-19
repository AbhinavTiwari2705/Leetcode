class Solution {
private:
    int sum(TreeNode* root) {
        if (!root) return 0;
        int left = sum(root->left);
        int right = sum(root->right);
        return left + right + root->val;
    }

    int nodeCount(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }

    int avg(TreeNode* root) {
        int sumVal = sum(root);
        int countVal = nodeCount(root);
        return sumVal / countVal;
    }

    void DFS(TreeNode* root, int& count) {
        if (root == NULL) return;
        int average = avg(root);
        if (average == root->val) {
            count++;
        }
        DFS(root->left, count);
        DFS(root->right, count);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        DFS(root, count);
        return count;
    }
};
