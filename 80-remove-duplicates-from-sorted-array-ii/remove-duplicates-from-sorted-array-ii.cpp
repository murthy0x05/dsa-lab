class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }

        int k = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[i - 1] || nums[i] != nums[i - 2]) {
                nums[k++] = nums[i - 2];
            }
        }
        nums[k++] = nums[n - 2];
        nums[k++] = nums[n - 1];

        return k;
    }
};