class Solution {
private:
    
    void bfs(int n, vector<vector<int>> &adj, vector<int> &vis) {
        queue<int> q;
        q.push(n);
        vis[n] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto i : adj[node]) {
                if (!vis[i]) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &con) {
        
        if (con.size() < n - 1) return -1;

        vector<vector<int>> adj(n);
        for (auto v : con) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<int> vis(n, 0);
        int count = 0;

        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(i, adj, vis);
                count++;
            }
        }

       
        return count - 1;
    }
};
