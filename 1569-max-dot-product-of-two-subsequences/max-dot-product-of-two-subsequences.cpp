class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return maxDotProduct(nums2, nums1);
        }

        int n1 = nums1.size(),
            n2 = nums2.size();

        vector<vector<vector<int>>> mem(n1, vector<vector<int>>(n2, vector<int>(2, 1e9)));
        function<int(int, int, bool)> f = [&](int i, int j, bool picked) {
            if (i >= n1 || j >= n2) {
                if (picked) return 0;
                else return (int)(-1e6-1);
            }
            if (mem[i][j][picked] != 1e9) {
                return mem[i][j][picked];
            }

            return mem[i][j][picked] = max({
                f(i + 1, j + 1, true) + (nums1[i] * nums2[j]),
                f(i + 1, j, picked),
                f(i, j + 1, picked)
            });
        };
        
        return f(0, 0, false);
    }
};