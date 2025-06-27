class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        int i = 0, maxReachable = 0;
        while (i < n) {
            cout << i << " : " << maxReachable << endl;
            maxReachable = max(maxReachable, i + nums[i]);
            if (i < maxReachable) {
                i += 1;
            } else {
                break;
            }
        }

        if (i >= n-1) {
            return true;
        }

        return false;
    }
};