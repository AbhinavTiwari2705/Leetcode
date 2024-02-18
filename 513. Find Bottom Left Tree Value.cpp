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
    void helper(TreeNode* root,int depth,int &height,int& ans) {
        
        if(root==NULL) return;

        if(depth>height){
            height=depth;
            ans=root->val;
        }
        helper(root->left,depth+1,height,ans);
        helper(root->right,depth+1,height,ans);



    }

public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return -1;
        int depth=1;
        int height=0;
        int ans=root->val;
         helper(root,depth,height,ans);
         return ans;
    }
};



