class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        int n = nums.length;

        List<Boolean> result = new ArrayList<>();
        for (int i = 0, val = 0; i < n; i++) {
            val = ((val * 2) + nums[i]) % 5;
            result.add(val == 0);
        }

        return result;
    }
}