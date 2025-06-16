class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> numsMap(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            numsMap[i][0] = nums[i];
            numsMap[i][1] = i;
        }
        sort(numsMap.begin(), numsMap.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] < b[1];
            }
        });

        int left = 0, right = n-1;
        while (left < right) {
            int mid = numsMap[left][0] + numsMap[right][0];
            if (mid == target) {
                return {numsMap[left][1], numsMap[right][1]};
            } else if (mid < target) {
                left += 1;
            } else {
                right -= 1;
            }
        }

        return {};
    }
};