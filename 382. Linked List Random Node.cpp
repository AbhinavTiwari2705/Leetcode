class Solution {
public:
    int len = 0;
    ListNode* ptr;

    Solution(ListNode* head) {
        auto* temp = head;
        ptr = head;
        
        while (temp) {
            len++;
            temp = temp->next;
        }
    }
    
    int getRandom() {
        if (len == 0)
            return -1;

        int randi = rand() % len;

        ListNode* temp = ptr;
        for (int i = 0; i < randi; i++) {
            temp = temp->next;
        }
        int ans = temp->val;
        return ans;
    }
};
