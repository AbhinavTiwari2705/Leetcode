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
    ListNode* getkthNode(ListNode* temp, int k) {
        while (k > 1 && temp != nullptr) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || head == nullptr) return head;

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp) {
            ListNode* kthNode = getkthNode(temp, k);
            if (kthNode == nullptr) {
                if (prev) prev->next = temp;
                break;
            }
            ListNode* nextKthNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* reversedHead = reverse(temp);

            if (prev == nullptr) {
                head = reversedHead;
            } else {
                prev->next = reversedHead;
            }

            prev = temp;
            temp = nextKthNode;
        }
        return head;
    }
};
