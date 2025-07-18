class Solution {
    #define ll long long
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int, vector<int>, less<int>> maxheap;
        vector<ll> left_mins;
        ll left_sum = 0;
        for (int i = 0; i < (n / 3); i++) {
            maxheap.push(nums[i]);
            left_sum += nums[i];
        }
        left_mins.push_back(left_sum);
        for (int i = n / 3; i < 2 * (n / 3); i++) {
            maxheap.push(nums[i]);
            left_sum += nums[i];
            left_sum -= maxheap.top();
            maxheap.pop();
            left_mins.push_back(left_sum);
        }

        priority_queue<int, vector<int>, greater<int>> minheap;
        ll right_sum = 0;
        for (int i = n - 1; i >= 2 * (n / 3); i--) {
            minheap.push(nums[i]);
            right_sum += nums[i];
        }

        ll min_diff = LLONG_MAX;
        for (int i = 2 * (n / 3) - 1; i >= (n / 3); i--) {
            min_diff = min(min_diff, left_mins[i - (n / 3 - 1)] - right_sum);
            minheap.push(nums[i]);
            right_sum += nums[i];
            right_sum -= minheap.top();
            minheap.pop();
        }
        min_diff = min(min_diff, left_mins[0] - right_sum);

        return min_diff;
        







    }
};