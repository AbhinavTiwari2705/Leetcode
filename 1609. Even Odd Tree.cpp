
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) // Handle the case when the root is nullptr
            return false;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX; // Initialize prev value for the level

            int size = q.size(); // Store the size of the current level

            for (int i = 0; i < size; ++i) {
                TreeNode* front = q.front();
                q.pop();

                // Check if the current value violates the expected pattern
                if ((level % 2 == 0 && (front->val % 2 == 0 || front->val <= prev)) ||
                    (level % 2 == 1 && (front->val % 2 == 1 || front->val >= prev)))
                    return false;

                prev = front->val; // Update prev value for the next iteration

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }

            ++level; 
        }

        return true;
    }
};
