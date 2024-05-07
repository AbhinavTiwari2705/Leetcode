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
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextNode = nullptr;
        
        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        
        return prev;
    }
public:
ListNode* doubleIt(ListNode* head) {
    head = reverse(head);
    ListNode* current = head;
    ListNode* prev = nullptr;
    int carry = 0;

    while (current != nullptr || carry != 0) {
        int sum = (current ? current->val : 0) * 2 + carry;
        carry = sum / 10;
        if (current) {
            current->val = sum % 10;
            prev = current;
            current = current->next;
        } else {
            prev->next = new ListNode(sum);
            break;
        }
    }

    return reverse(head);
}

};
