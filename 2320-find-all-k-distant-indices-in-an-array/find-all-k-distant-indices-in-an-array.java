class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> result = new ArrayList<>();
        int n = nums.length, size = 0, lastIndex = -1;
        for (int i = 0; i < n; i++) {
            if (key == nums[i]) {
                int start = Math.max(0, Math.max(i-k, lastIndex + 1));
                int end = Math.min(n-1, i + k);
                for (int j = start; j <= end; j++) {
                    result.add(j);
                    lastIndex = j;
                }
            }
        }

        return result;
    }
}