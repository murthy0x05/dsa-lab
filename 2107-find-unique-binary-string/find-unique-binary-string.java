class Solution {
    public String findDifferentBinaryString(String[] nums) {
        final int N = nums.length;

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append('0' + 1 - nums[i].charAt(i));
        }

        return sb.toString();
    }
}