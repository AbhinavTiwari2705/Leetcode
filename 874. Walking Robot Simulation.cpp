class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        
        unordered_set<string> obsSet;
        for (auto& obs : obstacles) {
            obsSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < cmd; ++i) {
                    int newX = x + directions[dir].first;
                    int newY = y + directions[dir].second;

                    if (obsSet.find(to_string(newX) + "," + to_string(newY)) != obsSet.end()) {
                        break;
                    }

                    x = newX;
                    y = newY;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};
