class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        vector<int> ans;
        queue<int> q;

        // Build the adjacency list and indegree array
        for (auto edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        // Push all courses with no prerequisites into the queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the courses in topological order
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (int neighbor : adj[front]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check if we were able to take all courses
        if (ans.size() == numCourses) {
            return ans;
        } else {
            return {};
        }
    }
};
