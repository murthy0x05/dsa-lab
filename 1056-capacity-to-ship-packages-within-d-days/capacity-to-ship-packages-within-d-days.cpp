class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        function<bool(int&)> feasible = [&](const int& capacity) {
            int D = 0;
            for (int i = 0, curr = 0; i < n; i++) {
                if (curr + weights[i] > capacity) {
                    D++;
                    curr = 0;
                }
                curr += weights[i];
            }

            return (D+1) <= days;
        };
        int low = *max_element(weights.begin(), weights.end()), high = low * n;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (feasible(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};