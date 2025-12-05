class Solution {
    using ll = long long;
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        ll right = accumulate(nums.begin(), nums.end(), nums[0] * -1LL);
        ll left = nums[0];

        int count = 0;
        for (int i = 1; i < n; i++) {
            if (!((left - right) & 1)) {
                count++;
                cout << left - right << endl;
            }
            left += nums[i];
            right -= nums[i];
        }

        return count;
    }
};