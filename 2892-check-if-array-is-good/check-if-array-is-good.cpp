class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int largest = nums[0];
        int largest_cnt = 0;
        bool ans = true;

        int nums_sum = (n - 1) * n / 2 + (n - 1);
        int actual_sum = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > largest){
                largest = nums[i];
            }
        }

        for(int num : nums){
            actual_sum += num;
        }

        int missing = nums_sum - actual_sum;

        if(missing != 0){
            ans = false;
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == largest){
                largest_cnt++;
            }
        }

        if(largest_cnt != 2){
            ans = false;
        }

        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i] == nums[i - 1] && nums[i] != largest){
                ans = false;
            }
        }

        if(n != largest + 1){
            ans = false;
        }

        return ans;
    }
};