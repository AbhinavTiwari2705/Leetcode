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
int sum=0;
    int maxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);

        return 1+max(left,right);
    }
    void ans(TreeNode* root,int& sum,int h,int th){
        if(!root) return ;

        if(h==th){
            sum+=root->val;
            return ;
        }
        ans(root->left,sum,h+1,th);
        ans(root->right,sum,h+1,th);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int height=maxDepth(root);
        ans(root,sum,1,height);
        return sum;


        
    }
};
