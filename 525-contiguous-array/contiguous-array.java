class Solution {
    public final int findMaxLength(int[] nums) {
        int n = nums.length;
        ArrayList<Integer> prefixSum = new ArrayList<>();
        for (int i = 0; i < n+1; i++) {
            prefixSum.add(0);
        }
        HashMap<Integer, Integer> seen = new HashMap<>();
        seen.put(0, -1);

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int curr = prefixSum.get(i) + (nums[i] == 0 ? -1 : 1);
            prefixSum.set(i+1, curr);
            int occ = seen.getOrDefault(curr, -2);
            if (occ == -2) {
                seen.put(curr, i);
            } else {
                maxLen = Math.max(maxLen, i - occ);
            }
        }

        return maxLen;
    }
}