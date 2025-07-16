class Solution {
public:
    inline int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjlist(n);
        for (auto& edge: times)
            adjlist[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> distance(n, INT_MAX);
        distance[k - 1] = 0;
        pq.push({0, k - 1});

        while (!pq.empty()) {
            pair<int, int> curr = pq.top(); pq.pop();
            int from = curr.second;
            if (curr.first > distance[from])
                continue;
            else {
                for (auto& neighbour: adjlist[from]) {
                    int to = neighbour.first;
                    int weight = neighbour.second;
                    if (distance[from] + weight < distance[to]) {
                        distance[to] = distance[from] + weight;
                        pq.push({distance[to], to});
                    }
                }
            }
        }

        int max_ele = *max_element(distance.begin(), distance.end());
        return max_ele == INT_MAX ? -1 : max_ele;
    }
};