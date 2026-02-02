class Solution {
    using pii = pair<int, int>;
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, 0 + nums[0]));

        for (int i = 1; i < n; i++) {
            while (pq.top().second < i) {
                pq.pop();
            }

            pq.push(make_pair(pq.top().first + 1, i + nums[i]));
        }

        return pq.top().first + (n != 1);
    }
};