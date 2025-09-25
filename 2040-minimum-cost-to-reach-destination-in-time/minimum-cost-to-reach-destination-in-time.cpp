class Solution {
    struct node {
        int v, time;
    };
    struct state {
        int u, cost, time;
        bool operator < (const state& other) const {
            if (cost != other.cost) {
                return cost > other.cost;
            } else {
                return time > other.time;
            }
        }
    };
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        vector<vector<node>> adjlist(n);
        vector<vector<int>> distance(n, vector<int>(maxTime + 1, INT_MAX));
        for (vector<int>& edge: edges) {
            adjlist[edge[0]].push_back({edge[1], edge[2]});
            adjlist[edge[1]].push_back({edge[0], edge[2]});
        }

        priority_queue<state> pq;
        distance[0][0] = passingFees[0];
        pq.push({0, distance[0][0], 0});

        while (!pq.empty()) {
            state curr = pq.top(); pq.pop();
            if (curr.u == n - 1) {
                return curr.cost;
            }
            if (distance[curr.u][curr.time] < curr.cost) {
                continue;
            }
            for (const node& adj: adjlist[curr.u]) {
                if (curr.time + adj.time <= maxTime &&
                    distance[curr.u][curr.time] + passingFees[adj.v] < distance[adj.v][curr.time + adj.time]) {
                    distance[adj.v][curr.time + adj.time] = distance[curr.u][curr.time] + passingFees[adj.v];
                    pq.push({adj.v, distance[adj.v][curr.time + adj.time], curr.time + adj.time});
                }
            }
        }

        return -1;
    }
};