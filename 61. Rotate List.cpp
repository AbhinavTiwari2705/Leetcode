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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        ListNode* ptr1 = head;
        int length = getLength(ptr1);
        k = k % length; // Adjust k if it's larger than the length

        if (k == 0) {
            return head;
        }

        ListNode* ptr = head;
        int count = 0;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            count++;
        }
        ptr->next = head;

        for (int i = 0; i < count - k; i++) {
            ptr1 = ptr1->next;
        }
        ListNode* newHead = ptr1->next;
        ptr1->next = nullptr;

        return newHead;
    }

private:
    int getLength(ListNode* head) {
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }
};
