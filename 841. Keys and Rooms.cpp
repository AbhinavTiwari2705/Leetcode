class Solution {
private:
    void bfs(int start, vector<vector<int>>& rooms, vector<int>& visited) {
        queue<int> q;
        visited[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto i : rooms[node]) {
                if (!visited[i]) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        bfs(0, rooms, visited);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                return false;
            }
        }
        return true;
    }
};
