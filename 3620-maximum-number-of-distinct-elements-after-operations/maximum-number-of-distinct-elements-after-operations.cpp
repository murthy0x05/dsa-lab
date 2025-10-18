class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        nums[0] -= k; int dists = 1, greatest = nums[0];
        for (int i = 1; i < n; i++) {
            int maxi = max(nums[i] - k, greatest + 1);
            if (maxi <= nums[i] + k) {
                nums[i] = greatest = maxi;
                dists++;
            }
        }
        
        return dists;
    }
};

// -1, 0, 1, 2, 3, 4
// -1, 0, 1, 2, 