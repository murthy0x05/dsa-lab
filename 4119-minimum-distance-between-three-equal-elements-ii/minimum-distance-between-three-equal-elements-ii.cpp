class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int N = nums.size();

        vector<vector<int>> occ(N + 1);
        for (int i = 0; i < N; i++) {
            occ[nums[i]].push_back(i);
        }

        int distance = INT_MAX;
        for (int i = 1; i <= N; i++) {
            for (int j = 2; j < occ[i].size(); j++) {
                distance = min<int>(distance, 2LL * (occ[i][j] - occ[i][j - 2]));
            }
        }

        return distance == INT_MAX ? -1 : distance;
    }
};