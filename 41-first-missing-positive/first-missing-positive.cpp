class Solution {
    int n;
    void place(vector<int>& nums, int i) {
        if (nums[i] == i + 1) {
            return ;
        } else {
            if (nums[i] < 1 || nums[i] > n) {
                nums[i] = i + 1;
            } else {
                int val = nums[i];
                nums[i] = i + 1;
                place(nums, val - 1);
            }
        }
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        this -> n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > n) nums[i] = -1;
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == i+1) {
                continue;
            } else {
                if (nums[i] >= 1) {
                    place(nums, nums[i] - 1);
                    if (nums[i] != i + 1) {
                        nums[i] = -1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};