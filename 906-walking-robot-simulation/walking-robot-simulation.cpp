class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const int N = commands.size();

        unordered_map<int, unordered_set<int>> obs;
        for (const vector<int>& obstacle: obstacles) {
            obs[obstacle[0]].insert(obstacle[1]);
        }

        int x = 0, y = 0;
        int dx = 0, dy = 1;
        int result = 0;
        for (int i = 0; i < N; i++) {
            if (commands[i] > 0) {
                for (int j = 0; j < commands[i]; j++) {
                    if (obs.count(x + dx) && obs[x + dx].count(y + dy)) {
                        break;
                    } else {
                        x += dx;
                        y += dy;
                    }
                }
            } else if (commands[i] == -2) {
                if (dx == 0 && dy == 1) {
                    dx = -1;
                    dy = 0;
                } else if (dx == -1 && dy == 0) {
                    dx = 0;
                    dy = -1;
                } else if (dx == 0 && dy == -1) {
                    dx = 1;
                    dy = 0;
                } else {
                    dx = 0;
                    dy = 1;
                }
            } else {
                if (dx == 0 && dy == 1) {
                    dx = 1;
                    dy = 0;
                } else if (dx == 1 && dy == 0) {
                    dx = 0;
                    dy = -1;
                } else if (dx == 0 && dy == -1) {
                    dx = -1;
                    dy = 0;
                } else {
                    dx = 0;
                    dy = 1;
                }
            }

            result = max(result, x * x + y * y);
        }

        return result;
    }
};