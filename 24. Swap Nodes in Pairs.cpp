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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* node1 = head;
    struct ListNode* node2 = head->next;
    
    while (node2 != NULL) {
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
        
        node1 = node2->next;
        if (node1 == NULL) {
            break; // No more pairs to swap
        }
        node2 = node1->next;
    }
    
    return head;
        
    }
};
