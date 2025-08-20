class Solution {
    #define pib pair<int, bool>
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();

        vector<pib> points(2 * n);
        for (int i = 0; i < n; i++) {
            points[i * 2] = make_pair(timeSeries[i], false);
            points[i * 2 + 1] = make_pair(timeSeries[i] + duration, true);
        }

        sort(points.begin(), points.end(), [](const pib& a, const pib& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
        });

        int result = 0;
        for (int i = 0, len = 2 * n, counter = 0; i < len; i++) {
            if (counter) {
                result += points[i].first - points[i - 1].first;
            }

            (points[i].second) ? counter++ : counter--;
        }

        return result;
    }
};