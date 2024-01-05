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
    bool flag; 
    
    void dfs(TreeNode* root, long long lower, long long upper) {  
        if (root == nullptr) return;
        
        if (root->val <= lower || root->val >= upper) { 
            flag = false;
            return;
        }
        
        dfs(root->left, lower, root->val); 
        dfs(root->right, root->val, upper); 
    }
    
    bool isValidBST(TreeNode* root) {
        flag = true; 
        dfs(root, LLONG_MIN, LLONG_MAX); 
        return flag;
    }
};
