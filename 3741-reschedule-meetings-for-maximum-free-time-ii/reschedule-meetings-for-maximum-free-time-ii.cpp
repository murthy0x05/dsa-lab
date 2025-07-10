class Solution {
    using pii = pair<int, int>;
    struct Comparator {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        priority_queue<pii, vector<pii>, Comparator> pq;
        pq.emplace(0, startTime[0]);
        pq.emplace(1, startTime[1] - endTime[0]);
        pq.emplace(n, eventTime - endTime[n - 1]);
        for (int i = 2; i < n; i++) {
            pq.emplace(i, startTime[i] - endTime[i - 1]);
            pq.pop();
        }

        vector<pair<int, int>> max_gaps;
        while (!pq.empty()) {
            max_gaps.push_back(pq.top());
            pq.pop();
        }

        int max_gap = 0;
        for (int i = 0; i < n; i++) {
            int meeting_slot = endTime[i] - startTime[i];
            int gap = (i - 1) >= 0 ? (startTime[i] - endTime[i - 1]) : startTime[i];
            gap += i + 1 < n ? (startTime[i + 1] - endTime[i]) : (eventTime - endTime[i]);
            if ((max_gaps[0].first < i || max_gaps[0].first > i + 1) && max_gaps[0].second >= meeting_slot) {
                gap += meeting_slot;
                max_gap = max(max_gap, gap);
            } else if ((max_gaps[1].first < i || max_gaps[1].first > i + 1) && max_gaps[1].second >= meeting_slot) {
                gap += meeting_slot;
                max_gap = max(max_gap, gap);
            } else if ((max_gaps[2].first < i || max_gaps[2].first > i + 1) && max_gaps[2].second >= meeting_slot) {
                gap += meeting_slot;
                max_gap = max(max_gap, gap);
            } else {
                max_gap = max(max_gap, gap);
            }
            // cout << i << " " << meeting_slot << " " << max_gap << endl;
        }

        // for (auto& [index, gap]: max_gaps) {
        //     cout << index << " " << gap << endl;
        // }

        return max_gap;

    }
};