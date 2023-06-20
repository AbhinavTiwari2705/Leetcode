/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

    
public:
int getListLength(struct ListNode *head) {
    int length = 0;
    struct ListNode *current = head;
    
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    return length;
}
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getListLength(headA);
    int lengthB = getListLength(headB);
    
    struct ListNode *tempA = headA;
    struct ListNode *tempB = headB;
    
    int diff = abs(lengthA - lengthB);
    
    // Move the pointer of the longer list to align the starting point
    if (lengthA > lengthB) {
        while (diff > 0) {
            tempA = tempA->next;
            diff--;
        }
    } else {
        while (diff > 0) {
            tempB = tempB->next;
            diff--;
        }
    }
    
    // Move both pointers in parallel until they meet
    while (tempA != tempB) {
        tempA = tempA->next;
        tempB = tempB->next;
    }
    
    return tempA;
    }
};




