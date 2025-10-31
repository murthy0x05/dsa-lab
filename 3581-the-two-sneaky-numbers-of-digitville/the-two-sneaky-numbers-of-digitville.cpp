class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!seen.insert(nums[i]).second) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};