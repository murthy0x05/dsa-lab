class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int curr = 0,
            zc = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                nums[curr] = nums[i];
                curr++;
            } else {
                zc += 1;
            }
        }
        for (; curr < n; curr++) {
            nums[curr] = 0;
        }
    }
};