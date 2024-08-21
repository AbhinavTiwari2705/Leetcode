class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int, double>>> adj(n);
        

        vector<double> dis(n, 0.0); 


        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adj[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        dis[start_node] = 1.0;
        
        while(!pq.empty()){
            double currProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();


            if(currProb < dis[node]) continue;

            for(auto& neighbor : adj[node]){
                int adjNode = neighbor.first;
                double edgeProb = neighbor.second;
                
                
                if(dis[adjNode] < currProb * edgeProb){
                    dis[adjNode] = currProb * edgeProb;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        
   
        return dis[end_node];
    }
};
