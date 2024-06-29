class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        queue<int> q;
        vector<set<int>> st(n);
        vector<int> indeg(n, 0);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }

        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int f = q.front();
            q.pop();

            for (auto i : adj[f]) {
                st[i].insert(f);

                for (auto it2 : st[f]) {
                    st[i].insert(it2);
                }
                indeg[i]--;

                if (indeg[i] == 0) {
                    q.push(i);
                }
            }
        }

=        for (int i = 0; i < n; ++i) {
            ans[i] = vector<int>(st[i].begin(), st[i].end());
        }

        return ans;
    }
};
