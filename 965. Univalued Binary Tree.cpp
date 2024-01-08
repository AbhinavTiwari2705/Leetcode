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
    bool flag=true;
public:
    bool isUnivalTree(TreeNode* root) {
        dfs(root,root->val);
        return flag;
        
    }
    void dfs(TreeNode* root,int prev){
        if(root==NULL) return;
        if(root->val!=prev) flag=false;
        dfs(root->left,prev);
        
        dfs(root->right,prev);
    }
};
