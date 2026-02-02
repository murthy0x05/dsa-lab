class Solution {
    using pii = pair<int, int>;
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return 0;
        }
        
        vector<int> dp(n); dp[0] = 1;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(1, 0 + nums[0]));

        for (int i = 1; i < n; i++) {
            while (pq.top().second < i) {
                pq.pop();
            }

            dp[i] = pq.top().first;
            pq.push(make_pair(dp[i] + 1, i + nums[i]));
        }


        return dp.back();
    }
};