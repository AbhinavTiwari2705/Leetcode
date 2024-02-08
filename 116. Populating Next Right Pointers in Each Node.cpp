/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void BFS(Node* root){
        if (!root) return;
        
        queue<Node*> q;
        q.push(root);

        while (!q.empty()){
            int size = q.size();
            vector<Node*> v;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                v.push_back(node);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            for (int i = 0; i < v.size() - 1; i++) {
                v[i]->next = v[i + 1];
            }
            v.back()->next = nullptr;
        }
        


    }
public:
    Node* connect(Node* root) {
        BFS(root);
        return root;
        
    }
};
