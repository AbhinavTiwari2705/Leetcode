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
    int count=0;
    void dfs(TreeNode* node,int maxi){
        if(node==NULL) return;
        if(node->val>=maxi){
            count+=1;
            maxi=node->val;
        }
        dfs(node->left,maxi);
        dfs(node->right,maxi);
        

    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};
