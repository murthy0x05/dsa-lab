class Solution {
    typedef long long ll;
    typedef pair<int, ll> pill;
    struct Comparator {
        bool operator() (auto& a, auto& b) {
            if (a.second != b.second)
                return a.second > b.second;
            else
                return a.first > b.first;
        }
    };
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<int> bookings(n, 0);
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] < b[1];
            }
        });

        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pill, vector<pill>, Comparator> occupied;
        for (int i = 0; i < n; i++)
            available.push(i);

        for (int i = 0; i < m; i++) {
            while (!occupied.empty() && occupied.top().second <= meetings[i][0]) {
                available.push(occupied.top().first);
                occupied.pop();
            }
            if (available.empty()) {
                pair<int, ll> room = occupied.top();
                occupied.pop();
                occupied.push(make_pair(room.first, room.second + (meetings[i][1] - meetings[i][0])));
                bookings[room.first] += 1;
            } else {
                int room = available.top();
                available.pop();
                occupied.push(make_pair(room, meetings[i][1]));
                bookings[room] += 1;
            }
        }

        for (int i: bookings) {
            cout << i << " ";
        }
        cout << endl;

        int most_booked = 0;
        for (int i = 1; i < n; i++) {
            if (bookings[i] > bookings[most_booked]) {
                most_booked = i;
            }
        }

        return most_booked;
    }
};