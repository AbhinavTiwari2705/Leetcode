/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
        void insertInBetween(Node* head) {
        if (head == NULL) return;
        Node* temp = head;
        
        while (temp) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
    }
    
    void copyRandom(Node* head) {
        if (head == NULL) return;
        Node* temp = head;
        
        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
            
        }
    }
    
    Node* deepCopy(Node* head) {
        Node* dummy = new Node(-1);
        Node* res = dummy;
        Node* temp = head;
        
        while (temp) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        
        insertInBetween(head);
        copyRandom(head);
        return deepCopy(head);
    }
};
