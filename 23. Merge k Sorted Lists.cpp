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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue with greater<int> to create a min-heap
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        // Push the initial nodes of each list into the priority queue
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        // Dummy node to help with merging the lists
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Process the priority queue until it's empty
        while(!pq.empty()) {
            // Get the smallest node from the priority queue
            auto it = pq.top();
            pq.pop();

            // Push the next node of the current node into the priority queue
            if(it.second->next) {
                pq.push({it.second->next->val, it.second->next});
            }

            // Add the smallest node to the result list
            temp->next = it.second;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};
