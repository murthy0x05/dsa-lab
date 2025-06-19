class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int& a, int& b) {
            return a < b;
        });
        nums.push_back(1000000);

        int smallest = nums[0], result = 0, i = 0;
        while (i < n) {
            while (nums[i] - smallest <= k) {
                i++;
            }
            result += 1;
            smallest = nums[i];
        }


        return result;
    }
};