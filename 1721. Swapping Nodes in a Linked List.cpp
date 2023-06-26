class Solution {
private:
    int length(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            head = head->next;
            count++;
        }
        return count;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;
        ListNode* temp2 = head;
        int r = length(head) - k;

        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        for (int i = 0; i < r; i++) {
            temp2 = temp2->next;
        }

        int tempVal = temp->val;
        temp->val = temp2->val;
        temp2->val = tempVal;

        return head;
    }
};
