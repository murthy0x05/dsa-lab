class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int k = 0; k < n; k++) {
            int i = k, j = 0;
            priority_queue<int> pq;
            while (i < n && j < n) {
                pq.push(grid[i][j]);
                i++; j++;
            }
            i = k, j = 0;
            while (!pq.empty()) {
                grid[i][j] = pq.top();
                i++; j++;
                pq.pop();
            }
        }

        for (int k = 1; k < n; k++) {
            int i = 0, j = k;
            priority_queue<int, vector<int>, greater<int>> pq;
            while (i < n && j < n) {
                pq.push(grid[i][j]);
                i++; j++;
            }
            i = 0, j = k;
            while (!pq.empty()) {
                grid[i][j] = pq.top();
                i++; j++;
                pq.pop();
            }
        }

        return grid;

        // 00 01 02 03
        // 10 11 12 13
        // 20 21 22 23
        // 30 31 32 33
    }
};