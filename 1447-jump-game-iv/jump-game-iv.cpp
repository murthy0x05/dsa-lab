class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int N = arr.size();
        if (N == 1) return 0;

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < N; i++) {
            adj[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(N, false);

        int step = 0;
        visited[N - 1] = true;
        q.push(N - 1);
        while (!q.empty()) {
            for (int ls = q.size(); ls; ls--) {
                int curr = q.front(); q.pop();
                
                if (curr == 0) return step;

                for (const int& nbr: adj[arr[curr]]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                if (curr + 1 < N && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                adj[arr[curr]].clear(); 
            }
            step++;
        }

        return -1;
    }
};