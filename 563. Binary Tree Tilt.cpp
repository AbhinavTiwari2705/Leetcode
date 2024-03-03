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
    

    int DFS(TreeNode* node,int& tilt) {
        if (!node) return 0;
        
        int leftSum = DFS(node->left,tilt);
        int rightSum = DFS(node->right,tilt);
        
        tilt += abs(leftSum - rightSum);
        
        return leftSum + rightSum + node->val;
    }

    int findTilt(TreeNode* root) {
        int tilt=0;
        DFS(root,tilt);
        return tilt;
    }
};
