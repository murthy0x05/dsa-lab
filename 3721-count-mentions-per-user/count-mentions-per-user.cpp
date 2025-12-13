class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](vector<string>& a, vector<string>& b) {
            int a1 = stoi(a[1]),
                b1 = stoi(b[1]);
            if (a1 != b1) {
                return a1 < b1;
            } else {
                return a[0][0] > b[0][0];
            }
        });

        vector<int> online(n, -1);
        vector<int> result(n, 0);
        for (int i = 0, len = events.size(); i < len; i++) {
            if (events[i][0][0] == 'M') {
                if (events[i][2][0] == 'H') {
                    for (int j = 0; j < n; j++) {
                        if (online[j] <= stoi(events[i][1])) {
                            result[j]++;
                        }
                    }
                } else if (events[i][2][0] == 'A') {
                    for (int j = 0; j < n; j++) {
                        result[j]++;
                    }
                } else {
                    stringstream ss(events[i][2]);
                    for (string id; ss >> id; ) {
                        result[stoi(id.substr(2))]++;
                    }
                }
            } else {
                online[stoi(events[i][2])] = stoi(events[i][1]) + 60;
            }
        }

        return result;
    }
};