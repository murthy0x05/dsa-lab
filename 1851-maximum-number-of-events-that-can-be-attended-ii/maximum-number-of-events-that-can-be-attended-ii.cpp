class Solution {
    inline int upper_bound(auto& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
    inline int solve(auto& events, auto& mem, int pos, int k) {
        if (k == 0 || pos >= events.size()) {
            return 0;
        }
        if (mem[pos][k] != -1) {
            return mem[pos][k];
        }

        int skip_event = solve(events, mem, pos + 1, k);
        int next = upper_bound(events, events[pos][1]);
        int attend_event = events[pos][2] + solve(events, mem, next, k - 1);
        
        return mem[pos][k] = max(skip_event, attend_event);

    }
public:
    inline int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> mem(n, vector<int>(k + 1, -1));
        sort(events.begin(), events.end());

        int result = solve(events, mem, 0, k);

        return result;

    }
};