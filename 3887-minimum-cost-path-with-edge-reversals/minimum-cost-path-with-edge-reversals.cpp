class Solution {
    struct box {
        int id, wt;
        box(int i, int w) : id(i), wt(w) {}
        bool operator < (const box& other) const {
            return wt > other.wt;
        }
    };
public:
    int minCost(int n, vector<vector<int>>& edges) {
        int V = n, E = edges.size();
        vector<vector<box>> adjlist(V);

        for (vector<int>& edge: edges) {
            adjlist[edge[0]].push_back(box(edge[1], edge[2]));
            adjlist[edge[1]].push_back(box(edge[0], 2 * edge[2]));
        }

        vector<int> d(V, 2e8);
        priority_queue<box> pq;
        pq.push(box(0, 0));
        d[0] = 0;

        while (!pq.empty()) {
            box curr = pq.top(); pq.pop();
            if (curr.wt > d[curr.id]) {
                continue;
            }
            for (box& nbr: adjlist[curr.id]) {
                if (d[curr.id] + nbr.wt < d[nbr.id]) {
                    d[nbr.id] = d[curr.id] + nbr.wt;
                    pq.push(box(nbr.id, d[nbr.id]));
                }
            }
        }

        return d.back() == 2e8 ? -1 : d.back();
    }
};