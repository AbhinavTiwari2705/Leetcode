class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val, root->val);
    }
    
    int dfs(TreeNode* node, int ancestorMax, int ancestorMin) {
        if (!node) return ancestorMax - ancestorMin;
        ancestorMax = max(ancestorMax, node->val);
        ancestorMin = min(ancestorMin, node->val);
        int left_diff = dfs(node->left, ancestorMax, ancestorMin);
        int right_diff = dfs(node->right, ancestorMax, ancestorMin);
        return max(left_diff, right_diff);
    }
};
