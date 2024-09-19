class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Create the adjacency list and indegree array
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        vector<unordered_set<int>> prereqSet(numCourses);
        
        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            indeg[p[1]]++;
        }
        
        // Step 2: Topological sort using a queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            // Process each neighbor of the current course
            for (int next : adj[course]) {
                // Add all prerequisites of the current course to the next course
                prereqSet[next].insert(course); // The current course is a prerequisite
                // Add all prerequisites of the current course to the next course's prerequisites
                prereqSet[next].insert(prereqSet[course].begin(), prereqSet[course].end());
                
                // Decrease the indegree of the neighbor
                indeg[next]--;
                if (indeg[next] == 0) {
                    q.push(next); // Add to the queue if indegree becomes zero
                }
            }
        }

        // Step 3: Process the queries
        vector<bool> result;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            // Check if u is a prerequisite of v
            result.push_back(prereqSet[v].count(u) > 0);
        }

        return result;
    }
};
