class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        int N1 = nums1.length,
            N2 = nums2.length;
        if (N1 > N2) {
            return findLength(nums2, nums1);
        }
        
        int maxLength = 0;
        int[] prev = new int[N2 + 1];
        for (int i = 0; i < N1; i++) {
            int[] curr = new int[N2 + 1];
            for (int j = 0; j < N2; j++) {
                if (nums1[i] == nums2[j]) {
                    curr[j + 1] = prev[j] + 1;
                    maxLength = Math.max(maxLength, curr[j + 1]);
                } else {
                    curr[j + 1] = 0;
                }
            }
            prev = curr;
        }

        return maxLength;
    }
}