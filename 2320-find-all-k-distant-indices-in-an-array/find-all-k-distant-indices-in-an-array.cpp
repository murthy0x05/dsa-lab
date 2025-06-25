class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        int lastIndex = -1;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int start = std::max(0, std::max(i - k, lastIndex + 1));
                int end = std::min(n-1, i + k);
                for (int j = start; j <= end; j++) {
                    result.push_back(j);
                    lastIndex = j;
                }
            }
        }

        return result;
    }
};