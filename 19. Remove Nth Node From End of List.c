struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* temp=head;
    int count=0;

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    temp=head;
    int k=count-n;
    if(k==0){
        head=head->next;
        return head;
    }
    for(int i=0;i<k-1;i++){
        temp=temp->next;

    }
    if(temp==NULL || temp->next==NULL){
        return NULL;
    }
    struct ListNode* node= temp->next;

    temp->next=node->next;

    return head;

}
