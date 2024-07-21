class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) return {};
        if(n==1) return {0};
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indeg[edges[i][0]]++;
            indeg[edges[i][1]]++;
        }
        //bfs
        queue<int> q;
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(indeg[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            ans.clear();
            int s=q.size();
            for(int i=0;i<s;i++){
                int curr=q.front();
                q.pop();
                ans.push_back(curr);
                for(auto i:adj[curr]){
                    indeg[i]--;
                    if(indeg[i]==1){
                        q.push(i);
                    }
                }
            }
        }
        return ans;

    }
};
