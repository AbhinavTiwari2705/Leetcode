class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* target) {
        if (o == nullptr) {
            return nullptr;
        }
        
        if (o->val == target->val && o->left == target->left && o->right == target->right) {
            return c;
        }
        
        TreeNode* leftResult = getTargetCopy(o->left, c->left, target);
        if (leftResult != nullptr) {
            return leftResult;
        }
        
        return getTargetCopy(o->right, c->right, target);
    }
};
