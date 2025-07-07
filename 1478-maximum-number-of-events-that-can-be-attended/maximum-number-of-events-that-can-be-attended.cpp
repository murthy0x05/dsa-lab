class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int rows = events.size(), cols = events[0].size();
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] < b[1];
            }
        });

        int attended = 0, time = 0, pos = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        while (pos < rows || !min_heap.empty()) {
            if (min_heap.empty())
                time = max(time, events[pos][0]);
            while (pos < rows && events[pos][0] == time) {
                min_heap.push(events[pos][1]);
                pos++;
            }
            while (!min_heap.empty() && min_heap.top() < time) {
                min_heap.pop();
            }
            if (!min_heap.empty()) {
                attended += 1;
                time += 1;
                min_heap.pop();
            }
        }
        
        return attended;
    }
};