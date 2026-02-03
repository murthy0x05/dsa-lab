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

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            result += curr == k;
            for (int j = i + 1; j < n; j++) {
                curr = gcd(curr, nums[j]);
                if (curr == k) {
                    result++;
                } else if (curr < k) {
                    break;
                }
            }
        }

    

        // int result = 0;
        // for (int i = 0, curr = 0, len = 0; i < n; i++) {
        //     if (gcd(nums[i], curr) >= k) {
        //         len++;
        //         if (gcd(nums[i], curr) == k) { 
        //             result++;
        //         }
        //         curr = gcd(nums[i], curr);
        //     } else {
        //         curr = 0;
        //         len = 0;
        //     }
        // }

        return result;
    }
};