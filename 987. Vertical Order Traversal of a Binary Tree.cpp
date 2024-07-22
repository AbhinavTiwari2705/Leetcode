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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to hold nodes indexed by their horizontal distance (x) and level (y)
        map<int, map<int, multiset<int>>> nodes;
        // Queue to hold nodes along with their horizontal distance (x) and level (y)
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Initialize the queue with the root node at position (0, 0)
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(node->val);

            // Push left and right children into the queue with updated positions
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        // Vector to hold the final vertical order traversal
        vector<vector<int>> ans;

        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
