class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] < b[1];
            }
        });

        vector<vector<int>> result;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < N; i++) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]); 
            } else {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start, end});

        return result;
    }
};