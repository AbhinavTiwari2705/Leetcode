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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = mapParents(root, parentMap, start);
        return bfsToInfectTree(startNode, parentMap);
    }
    
private:
   
    TreeNode* mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = nullptr;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->val == start) {
                res = node;
            }
            
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
        
        return res;
    }
    
   
    int bfsToInfectTree(TreeNode* startNode, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(startNode);
        unordered_map<TreeNode*, bool> visited;
        visited[startNode] = true;
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool infected = false;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left && !visited[node->left]) {
                    infected = true;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                
                if (node->right && !visited[node->right]) {
                    infected = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                
                if (parentMap[node] && !visited[parentMap[node]]) {
                    infected = true;
                    visited[parentMap[node]] = true;
                    q.push(parentMap[node]);
                }
            }
            
            if (infected) {
                time++;
            }
        }
        
        return time;
    }
};
