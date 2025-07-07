// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n1 = nums.size();
//         set<int> temp;
//         for (int num: nums)
//             temp.insert(num);
//         int n2 = 0;
//         vector<int> sorted(temp.size());
//         for (int var: temp) {
//             sorted[n2] = var;
//             n2 += 1;
//         }

//         vector<vector<int>> dp(n2+1, vector<int>(n1+1, 0));
//         for (int i = 0; i < n2; i++) {
//             for (int j = 0; j < n1; j++) {
//                 if (nums[j] == sorted[i]) {
//                     dp[i+1][j+1] = dp[i][j] + 1;
//                 } else {
//                     dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
//                 }
//             }
//         }

//         return dp[n2][n1];
//     }
// };

class Solution {
    int lower_bound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> result; result.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > result.back()) {
                result.push_back(nums[i]);
            } else {
                int index = lower_bound(result, nums[i]);
                result[index] = nums[i];
            }
        }

        return result.size();
    }
};