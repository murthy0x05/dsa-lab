class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const int INF = 1e9 + 10;

        int p1 = 0, p2 = INF, p3 = INF;
        for (int i = 1, curr; i <= n; i++) {
            curr = min({p1 + 1, p2 + 4, p3 + 9}) + costs[i - 1];
            p3 = p2; p2 = p1; p1 = curr;
        }

        return p1;
    }
};