class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0, high = n1;
        int half = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = half - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 > 0) l1 = nums1[mid1 - 1];
            if (mid2 > 0) l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                if (!(n & 1)) {
                    return ((double)max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2) * 1.0;
                }
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else if (l2 > r1) {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }
};

/*
    i. We will try to draw a imaginary symmetry line thinking that x & y numbers will be taken from nums1 & nums2 respectively.
    ii. For conditions in Binary Search, we will try to compare the maxElement from the low (l1) and minimum element from the high (r2).
    iii. Similarly, we will try to compare the maxElement from the low (l2) and minimum element from the high (r1).
    iv. ie. we will compare cross values.
    eg. suppose, 
        nums1 = [1, 3, 4, 7, 10, 12];
        nums2 = [2, 3, 6, 15];
        now, there will be one valid sequence like
            ------------------------------
           | 1, 3, 4(l1) | (r1)7, 10, 12  |
           |    2, 3(l2) | (r2)6, 15      |
            ------------------------------

*/