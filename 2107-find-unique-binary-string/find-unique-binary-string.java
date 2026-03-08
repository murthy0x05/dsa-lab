class Solution {
    public String findDifferentBinaryString(String[] nums) {
        final int N = nums.length;

        Set<Integer> seen = new HashSet<>();
        for (int i = 0; i < N; i++) {
            seen.add(Integer.parseInt(nums[i], 2));
        }

        for (int i = 0, len = 1 << N; i < len; i++) {
            if (!seen.contains(i)) {
                String result = Integer.toBinaryString(i);
                return String.format("%" + N +  "s", result).replace(' ', '0');
            }
        }

        return "";
    }
}