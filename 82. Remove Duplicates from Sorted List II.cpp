struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));  // Create a dummy node
    dummy->val = -1;  // Initialize with a value that won't be present in the list
    dummy->next = head;
    
    struct ListNode* prev = dummy;
    struct ListNode* current = head;

    while (current != NULL) {
        bool isDuplicate = false;
        
        while (current->next != NULL && current->val == current->next->val) {
            current = current->next;
            isDuplicate = true;
        }
        
        if (isDuplicate) {
            prev->next = current->next;
        } else {
            prev = prev->next;
        }
        
        current = current->next;
    }
    
    struct ListNode* newHead = dummy->next;
    free(dummy);  // Free the dummy node
    return newHead;
}
