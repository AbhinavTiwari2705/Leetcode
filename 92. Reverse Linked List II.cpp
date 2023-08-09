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
    ListNode* reverse(ListNode* head, ListNode* right) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nn = nullptr;
        while (current != right) {
            nn = current->next;
            current->next = prev;
            prev = current;
            current = nn;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || !head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 0; i < m; i++) {
            prev = prev->next;
        }

        ListNode* left = prev;
        ListNode* right = prev->next;
        for (int i = m; i <= n; ++i) {
            right = right->next;
        }

        ListNode* tleft = left->next;
        ListNode* tright = right->next;

        // Disconnect the subsequence to be reversed
        left->next = nullptr;
        right->next = nullptr;

        reverse(tleft, tright);  // Reverse the subsequence

        // Reconnect the reversed subsequence
        left->next = right;  // Connect left to the new start of reversed subsequence
        tleft->next = tright; // Connect the end of reversed subsequence to tright

        return dummy->next;
    }
};
