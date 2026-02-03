class Solution {
    using pii = pair<int, int>;
public:
    int minTaps(int n, vector<int>& ranges) {
        priority_queue<pii, vector<pii>, function<bool(pii&, pii&)>> pq(
            [&] (const pii& a, const pii& b) {
                if (a.first != b.first) {
                    return a.first > b.first;
                } else {
                    return a.second < b.second;
                }
            }
        );

        for (int i = 0, len = ranges.size(); i < len; i++) {
            if (ranges[i] != 0) {
                pq.push(make_pair(max(0, i - ranges[i]), min(n, i + ranges[i])));
            }
        }

        int prev = 0;
        int result = 0;
        while (!pq.empty() && prev < n) {
            if (pq.top().first > (prev)) {
                return -1;
            }

            int Max = prev;
            while (!pq.empty() && pq.top().first <= (prev)) {
                Max = max(Max, pq.top().second);
                pq.pop();
            }

            result++;
            prev = Max;
        }

        return prev >= n ? result : -1;
    }
};