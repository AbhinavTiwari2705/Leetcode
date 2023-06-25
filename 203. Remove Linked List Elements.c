struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) {
        return NULL;
    }
    
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    
    if (head == NULL) {
        return NULL;
    }
    
    struct ListNode* node1 = head;
    struct ListNode* node2 = head->next;
    
    while (node2 != NULL) {
        if (node2->val == val) {
            node1->next = node2->next;
            free(node2);
            node2 = node1->next;
        } else {
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    
    return head;
}
