class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int start = 0, end = 0;
        int prev_end = 0;

        int max_free_time = 0, free_time = startTime[0];
        while (end < n) {
            while (end < n && end - start < k) {
                end++;
                if (end < n)
                    free_time += startTime[end] - endTime[end - 1];
            }
            if (end == n)
                free_time += eventTime - endTime[end - 1];
            max_free_time = max(max_free_time, free_time);
            free_time -= startTime[start] - prev_end;
            prev_end = endTime[start];
            start++;
        }

        return max_free_time;
    }
};