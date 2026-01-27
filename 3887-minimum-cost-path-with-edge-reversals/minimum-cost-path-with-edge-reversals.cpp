class Solution {
    using pii = pair<int, int>;
    const int INF = 2e8;
public:
    inline int minCost(int n, vector<vector<int>>& edges) {
        int V = n, E = edges.size();
        vector<vector<pii>> adjlist(V);

        for (vector<int>& edge: edges) {
            adjlist[edge[0]].push_back(make_pair(edge[1], edge[2]));
            adjlist[edge[1]].push_back(make_pair(edge[0], 2 * edge[2]));
        }

        vector<int> d(V, INF);
        auto cmp = [](const pii& a, const pii& b) {
            if (a.second != b.second) {
                return a.second > b.second; 
            } else {
                return a.first > b.first;
            }
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        pq.push(make_pair(0, 0));
        d[0] = 0;
    
        while (!pq.empty()) {
            pii curr = pq.top(); pq.pop();
            if (curr.second > d[curr.first]) {
                continue;
            }
            for (pii& nbr: adjlist[curr.first]) {
                if (d[curr.first] + nbr.second < d[nbr.first]) {
                    d[nbr.first] = d[curr.first] + nbr.second;
                    pq.push(make_pair(nbr.first, d[nbr.first]));
                }
            }
        }

        return d.back() == 2e8 ? -1 : d.back();
    }
};