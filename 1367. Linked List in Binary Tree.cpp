/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
bool check(ListNode* head, TreeNode* root){
        if(!root) return false;
        if(DFS(head,root))return true;
        return check(head,root->left)||check(head,root->right);
    }
    bool DFS(ListNode* head, TreeNode* root){
        if(!head) return true;
        if(!root) return false;
        
        if(root->val!=head->val) return false;

        return DFS(head->next,root->left)||DFS(head->next,root->right);

    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        return check(head,root);
    }
};
