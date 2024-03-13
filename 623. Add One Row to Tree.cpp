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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node= new TreeNode(val);
            node->left=root;
            return node;
        }

        queue<TreeNode* > q;
        q.push(root);
        int count=0;

        while(!q.empty()){
            int n=q.size();

            count++;
            while(n--){
                TreeNode* curr=q.front();
                q.pop();

                if(count!=depth-1){
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                else{
                    TreeNode* node1 = new TreeNode(val);
                    node1->left=curr->left;
                    curr->left=node1;

                    
                    TreeNode* node2 = new TreeNode(val);
                    node2->right=curr->right;
                    curr->right=node2;
                }
            }
        }
        return root;
    }
};
