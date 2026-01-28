class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(), position.end());
        function<bool(int&)> feasible = [&] (const int& force) {
            int placed = 1;
            for (int i = 1, prev = position.front(); i < n; i++) {
                if (position[i] - prev >= force) {
                    placed++;
                    prev = position[i];
                }
            }

            return placed >= m;
        };
        int low = 1, high = position.back() - position.front();
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (feasible(mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};