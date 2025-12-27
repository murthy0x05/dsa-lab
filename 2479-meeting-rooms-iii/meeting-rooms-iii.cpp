class Solution {
    using ll = long long;
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] < b[1];
            }
        });

        priority_queue<int, vector<int>, greater<>> unused;
        vector<ll> lru(n, -1);
        auto cmp = [&lru] (const int& a, const int& b) {
            if (lru[a] != lru[b]) {
                return lru[a] > lru[b];
            } else {
                return a > b;
            }
        };
        priority_queue<int, vector<int>, decltype(cmp)> used(cmp);
        vector<int> booked(n, 0);
        
        booked[0]++;
        lru[0] = meetings[0][1];
        used.push(0);
        
        for (int i = 1; i < n; i++) unused.push(i);
        for (int i = 1, len = meetings.size(); i < len; i++) {
            while (!used.empty() && lru[used.top()] <= meetings[i][0]) {
                unused.push(used.top()); used.pop();
            }
            
            if (!unused.empty()) {
                booked[unused.top()]++;
                lru[unused.top()] = meetings[i][1];
                used.push(unused.top());
                unused.pop();
            } else {
                int room = used.top(); used.pop();
                booked[room]++;
                lru[room] += (meetings[i][1] - meetings[i][0]);
                used.push(room);
            }
        }

        return max_element(booked.begin(), booked.end()) - booked.begin();
    }
};