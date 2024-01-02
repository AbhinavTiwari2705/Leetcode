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
int diff=INT_MAX;
TreeNode* prev=NULL;
    void DFS(TreeNode* root){
        if(root->left) DFS(root->left);
        if(prev) diff=min(diff,abs(prev->val - root->val));
        prev=root;
        if(root->right) DFS(root->right);
        
    }
    int getMinimumDifference(TreeNode* root) {
        DFS(root);
        return diff;
    }
};
