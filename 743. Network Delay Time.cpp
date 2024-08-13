class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> distance(n + 1, 1e9);

        // Build adjacency list
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto i : adj[node]) {
                int adjNode = i.first;
                int adjTime = i.second;

                if (time + adjTime < distance[adjNode]) {
                    distance[adjNode] = time + adjTime;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        int maxTime = *max_element(distance.begin() + 1, distance.end());
        return (maxTime == 1e9) ? -1 : maxTime;
    }
};
