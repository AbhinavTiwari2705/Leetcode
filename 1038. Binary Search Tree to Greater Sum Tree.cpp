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
private: 
    void helper(TreeNode* root,int& total){
        if(root==NULL) return;
        helper(root->right,total);
        total+=root->val;
        root->val=total;
        helper(root->left,total);

        
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return 0;
        int total=0;
        helper(root,total);
        return root;
    }
};
