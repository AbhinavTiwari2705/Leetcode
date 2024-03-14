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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // If the pointers meet, there is a cycle in the linked list.
                // Reset the slow pointer to the head of the linked list, and
                // move both pointers one step at a time until they meet again.
                // The node where they meet is the starting point of the cycle.
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};



//Time Complexity = O(n)
//Space Complexity = O(1)



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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* current = head;
        
        while (current != nullptr) {
            if (visited.find(current) != visited.end()) {
                return current;
            }
            visited.insert(current);
            current = current->next;
        }
        
        // If no cycle is found, return nullptr
        return nullptr;
    }
};

Time Complexity=O(n)
Space Complexity=O(n)
