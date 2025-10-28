class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        vector<int> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + nums[i];
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (ps[n] - ps[i] == ps[i] - ps[0]) {
                    result += 2;
                } else if (abs(ps[n] - ps[i] - ps[i]) == 1) {
                    result += 1;
                }
            }
        }

        return result;
    }
};