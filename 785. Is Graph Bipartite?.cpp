class Solution {
    bool bfs(vector<vector<int>>& graph, int col[], int start) {
        queue<int> q;
        q.push(start);
        col[start] = 0; 

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (col[neighbor] == -1) {
                    col[neighbor] = !col[node]; 
                    q.push(neighbor);
                } else if (col[neighbor] == col[node]) {
                    return false; 
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int col[n];
        fill(col, col + n, -1); 

        
        for (int i = 0; i < n; ++i) {
            if (col[i] == -1) { 
                if (!bfs(graph, col, i)) { 
                    return false; 
                }
            }
        }

        return true; 
    }
};
