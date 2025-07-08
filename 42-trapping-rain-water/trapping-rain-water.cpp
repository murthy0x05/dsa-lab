class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 1, right = n - 2;
        int lmax = height[left - 1];
        int rmax = height[right + 1];
        int result = 0;
        while (left <= right) {
            if (lmax < rmax) {
                result += max(0, lmax - height[left]);
                lmax = max(lmax, height[left]);
                left++;
            } else {
                result += max(0, rmax - height[right]);
                rmax = max(rmax, height[right]);
                right--;
            }
        }

        return result;
    }
};