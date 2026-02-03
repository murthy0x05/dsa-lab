class Solution {
    // int gcd(const int& a, const int& b) {
    //     if (b != 0) {
    //         return gcd(a % b, a);
    //     }
    //     return a;
    // }
public:
    int subarrayGCD(vector<int>& nums, int k) {
        const int n = nums.size();

        int result = 0;
        for (int i = 0, curr; i < n; i++) {
            curr = nums[i];
            for (int j = i; j < n; j++) {
                curr = gcd(curr, nums[j]);
                if (curr == k) {
                    result++;
                } else if (curr < k) {
                    break;
                }
            }
        }

        return result;
    }
};