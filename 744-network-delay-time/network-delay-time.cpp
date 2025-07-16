class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjlist(n);
        for (auto& edge: times)
            adjlist[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> distance(n, INT_MAX);
        distance[k - 1] = 0;
        pq.push({k - 1, 0});

        while (!pq.empty()) {
            pair<int, int> curr = pq.top(); pq.pop();
            int from = curr.first;
            for (auto& neighbour: adjlist[from]) {
                int to = neighbour.first;
                int weight = neighbour.second;
                if (distance[from] + weight < distance[to]) {
                    distance[to] = distance[from] + weight;
                    pq.push({to, distance[to]});
                }
            }
        }

        int max_ele = *max_element(distance.begin(), distance.end());
        return max_ele > 600000 ? -1 : max_ele;
    }
};