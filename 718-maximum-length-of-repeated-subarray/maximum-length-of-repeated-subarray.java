class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        final int N1 = nums1.length,
                  N2 = nums2.length;
        if (N1 > N2) {
            return findLength(nums2, nums1);
        }

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < 101; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < N1; i++) {
            adj.get(nums1[i]).add(i);
        }

        int longest = 0;
        for (int i = 0; i < N2; i++) {
            for (int id: adj.get(nums2[i])) {
                int c1id = id;
                int c2id = i;
                while (c1id < N1 && c2id < N2 && nums1[c1id] == nums2[c2id]) {
                    c1id++;
                    c2id++;
                }

                longest = Math.max(longest, c1id - id);
            }
        }

        return longest;
    }
}