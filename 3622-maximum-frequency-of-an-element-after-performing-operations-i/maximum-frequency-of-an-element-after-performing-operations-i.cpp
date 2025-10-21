class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        
        vector<int> ps(1e5 + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[nums[i]] += 1;
        }
        for (int i = 1; i < 1e5 + 1; i++) {
            ps[i] += ps[i - 1];
        }

        int result = 0;
        for (int i = 1; i < 1e5 + 1; i++) {
            int start = max<int>(0, i - k - 1),
                end = min<int>(1e5, i + k);
            result = max(result,
                         min(numOperations, ps[end] - ps[start] - (ps[i] - ps[i - 1])) + (ps[i] - ps[i - 1]));
            if (i == 15) {
                cout << min(numOperations, ps[end] - ps[start] - ps[i]) << endl;
            }
        }

        return result;       
    }
};