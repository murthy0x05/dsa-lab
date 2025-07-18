class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        auto cmp = [&score](int& a, int& b) {
            return score[a] < score[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            pq.push(i);
        }

        vector<string> result(n);
        result[pq.top()] = "Gold Medal"; pq.pop();
        if (n == 1) return result;
        result[pq.top()] = "Silver Medal"; pq.pop();
        if (n == 2) return result;
        result[pq.top()] = "Bronze Medal"; pq.pop();

        int rank = 4;
        while (!pq.empty()) {
            result[pq.top()] = to_string(rank++);
            pq.pop();
        }

        return result;
    }
};