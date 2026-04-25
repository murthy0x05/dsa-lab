class Solution {
public:
    struct Seq {
        int sx, sy, ex, ey, len;
    };

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<pair<int,int>> p = orderPoints(side, points);

        int lo = 0, hi = side;
        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (canPick(p, k, mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }

private:
    bool canPick(const vector<pair<int,int>>& p, int k, int d) {
        deque<Seq> dq;
        dq.push_back({p[0].first, p[0].second, p[0].first, p[0].second, 1});

        int best = 1;

        for (int i = 1; i < (int)p.size(); i++) {
            int x = p[i].first;
            int y = p[i].second;

            int sx = x, sy = y, len = 1;

            while (!dq.empty() &&
                   abs(x - dq.front().ex) + abs(y - dq.front().ey) >= d) {

                if (abs(x - dq.front().sx) + abs(y - dq.front().sy) >= d &&
                    dq.front().len + 1 >= len) {
                    sx = dq.front().sx;
                    sy = dq.front().sy;
                    len = dq.front().len + 1;
                    best = max(best, len);
                }
                dq.pop_front();
            }

            dq.push_back({sx, sy, x, y, len});
        }

        return best >= k;
    }

    vector<pair<int,int>> orderPoints(int side, vector<vector<int>>& points) {
        vector<pair<int,int>> left, top, right, bottom;

        for (auto &pt : points) {
            int x = pt[0], y = pt[1];

            if (x == 0) left.push_back({x, y});
            else if (y == side) top.push_back({x, y});
            else if (x == side) right.push_back({x, y});
            else bottom.push_back({x, y});
        }

        sort(left.begin(), left.end(),
             [](auto &a, auto &b) { return a.second < b.second; });

        sort(top.begin(), top.end(),
             [](auto &a, auto &b) { return a.first < b.first; });

        sort(right.begin(), right.end(),
             [](auto &a, auto &b) { return a.second > b.second; });

        sort(bottom.begin(), bottom.end(),
             [](auto &a, auto &b) { return a.first > b.first; });

        vector<pair<int,int>> res;
        for (auto &x : left) res.push_back(x);
        for (auto &x : top) res.push_back(x);
        for (auto &x : right) res.push_back(x);
        for (auto &x : bottom) res.push_back(x);

        return res;
    }
};