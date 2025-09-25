class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev(triangle[0]);

        for (int i = 1, n = triangle.size(); i < n; i++) {
            vector<int> curr(triangle[i]);

            for (int j = 0, len = triangle[i].size(); j < len; j++) {
                if (j < prev.size() && (j - 1 >= 0 && j - 1 < prev.size())) {
                    curr[j] += min(prev[j], prev[j - 1]);
                } else if (j < prev.size()) {
                    curr[j] += prev[j];
                } else if (j - 1 >= 0 && j - 1 < prev.size()) {
                    curr[j] += prev[j - 1];
                }
            }

            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};