class Solution {
public:
    void DFS(const TreeNode* root,vector<int>& v) {
        if (root == nullptr) return;

        if (!(root->left || root->right)) {
            v.push_back(root->val);
            return ;
        }
        
        DFS(root->left,v);
        DFS(root->right,v);

        return;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;

        DFS(root1,v1);
        DFS(root2,v2);

        // sort(v1.begin(), v1.end());
        // sort(v2.begin(), v2.end());

        return v1 == v2;
    }
};
