class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), size = 0;
        int answer = 0;
        int left_closest = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                if (nums[i] < left_closest && nums[i] < nums[i + 1] ||
                    nums[i] > left_closest && nums[i] > nums[i + 1]) {
                    answer++;
                }
                left_closest = nums[i];
            }
        }
    
        return answer;
    }
};