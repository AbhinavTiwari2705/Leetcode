class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return -1;

        queue<TreeNode*> q;
        q.push(root);
        int level_max = INT_MIN;
        int maxi_level = 0;
        int curr_level = 0;

        while (!q.empty()) {
            int size = q.size();
            int level_sum = 0;
            curr_level++;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                level_sum += front->val;
                
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }

            if (level_sum > level_max) {
                level_max = level_sum;
                maxi_level = curr_level;
            }
        }
        return maxi_level;
    }
};
