class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; i++)
            sortedNums[i] = {nums[i], i};

        sort(sortedNums.begin(), sortedNums.end());

        vector<int> position(n);
        for (int i = 0; i < n; i++)
            position[sortedNums[i].second] = i;

        int LOG = log2(n) + 1;

        vector<vector<int>> up(n, vector<int>(LOG));

        int right = 0;
        for (int left = 0; left < n; left++) {
            right = max(right, left);

            while (right + 1 < n &&
                   sortedNums[right + 1].first - sortedNums[left].first <= maxDiff)
                right++;

            up[left][0] = right;
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> answer;

        for (const auto& query : queries) {
            int left = position[query[0]];
            int right = position[query[1]];

            if (left > right)
                swap(left, right);

            if (left == right) {
                answer.push_back(0);
                continue;
            }

            int jumps = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[left][j] < right) {
                    left = up[left][j];
                    jumps += (1 << j);
                }
            }

            if (up[left][0] >= right)
                answer.push_back(jumps + 1);
            else
                answer.push_back(-1);
        }

        return answer;
    }
};