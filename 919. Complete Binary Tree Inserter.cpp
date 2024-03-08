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
class CBTInserter {
private:
    TreeNode* root = nullptr;
public:
    CBTInserter(TreeNode* root) :root(root) {}
    
    int insert(int v) {
        queue<TreeNode*> q;
        q.emplace(root);
        TreeNode* curr = nullptr;
        while (q.size()) {
            curr = q.front(), q.pop();
            if (curr->left == NULL) { 
                curr->left = new TreeNode(v); 
                curr->right = NULL;
                break; 
            }
            if (curr->right == NULL) { curr->right = new TreeNode(v); break; }
            if (curr->left) q.emplace(curr->left);
            if (curr->right) q.emplace(curr->right);
        }
        return curr->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};
/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
