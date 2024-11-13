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

vector<vector<int>> BFS(TreeNode* root){
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    int cnt=0;
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
        TreeNode* n=q.front();
        q.pop();
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
            level.push_back(n->val);
            
            
        }
        if(cnt%2!=0){
            reverse(level.begin(),level.end());
            ans.push_back(level);
        }
        else{
            ans.push_back(level);
        }
        cnt++ ;


    }
    return ans;
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
           if (root == nullptr) {
        return {}; 
    }
        return BFS(root);
    }
};
