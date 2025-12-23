class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });

        int result = events[0][2];
        int max_event = events[0][2];
        map<int, int> maxAchieved;
        maxAchieved[events[0][1]] = events[0][2];
        for (int i = 1; i < n; i++) {
            auto it = maxAchieved.upper_bound(events[i][0] - 1);
            int x = (it == maxAchieved.begin()) ? 0 : prev(it) -> second;
            result = max(result, x + events[i][2]);
            max_event = max(max_event, events[i][2]);
            maxAchieved[events[i][1]] = max_event;
        }

        return result;
    }
};