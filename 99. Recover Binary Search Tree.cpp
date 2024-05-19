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
    void inorder(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& middle, TreeNode*& last) {
        if (root == nullptr) return;
        inorder(root->left, prev, first, middle, last);
        
        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        
        prev = root;
        inorder(root->right, prev, first, middle, last);
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* middle = nullptr;
        TreeNode* last = nullptr;
        
        inorder(root, prev, first, middle, last);
        
        if (first != nullptr && last != nullptr) {
            std::swap(first->val, last->val);
        } else if (first != nullptr && middle != nullptr) {
            std::swap(first->val, middle->val);
        }
    }
};
