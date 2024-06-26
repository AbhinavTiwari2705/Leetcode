class Solution {
private:
    TreeNode* constructTree(vector<int>& postorder, int postStart, int postEnd, 
                            vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp) {
        if (postStart > postEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int elem = mp[root->val];
        int nElem = elem - inStart;

        root->left = constructTree(postorder, postStart, postStart + nElem - 1, 
                                    inorder, inStart, elem - 1, mp);
        root->right = constructTree(postorder, postStart + nElem, postEnd - 1, 
                                    inorder, elem + 1, inEnd, mp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postStart = 0, postEnd = postorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;

        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
    }
};
