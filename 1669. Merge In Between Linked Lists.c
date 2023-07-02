/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* ptr1=list1;
    struct ListNode* ptr2=list1;
    struct ListNode* ptr3=list2;

    for(int i=0;i<a-1;i++){
        ptr1=ptr1->next;
    }
    for(int i=0;i<b;i++){
        ptr2=ptr2->next;
    }
    ptr2=ptr2->next;
    ptr1->next=ptr3;

    while(ptr3->next!=NULL){
        ptr3=ptr3->next;


    }
    ptr3->next=ptr2;
    return list1;

}
