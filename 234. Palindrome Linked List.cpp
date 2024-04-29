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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newhead = reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next = NULL;
        return newhead;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* newhead = reverse(slow->next);
        ListNode* temp = head;
        ListNode* temp2 = newhead;
        
        while (temp2 != NULL) {
            if (temp->val != temp2->val) {
                reverse(newhead);
                return  false;

            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        reverse(newhead); 
        return true;
    }
};
