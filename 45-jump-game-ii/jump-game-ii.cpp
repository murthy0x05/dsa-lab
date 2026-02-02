class Solution {
    using pii = pair<int, int>;
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> dp(n); dp[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, 0 + nums[0]));

        for (int i = 1; i < n; i++) {
            while (pq.top().second < i) {
                pq.pop();
            }

            dp[i] = pq.top().first;
            pq.push(make_pair(dp[i] + 1, i + nums[i]));
        }


        return dp.back() + (n != 1);
    }
};