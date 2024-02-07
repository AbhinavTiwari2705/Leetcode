/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans; 
        DFS(root, ans, 0);
        return ans;
    }
    
    void DFS(TreeNode* root, vector<int>& ans, int depth) {
        if (!root) return;
        
        if (depth == ans.size()) 
            ans.push_back(root->val);
        
        
        DFS(root->right, ans, depth + 1);
        DFS(root->left, ans, depth + 1);
    }
};
