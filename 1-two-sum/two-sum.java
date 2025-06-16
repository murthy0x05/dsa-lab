class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        HashMap<Integer, Integer> seen = new HashMap<>();

        int result[] = null;
        for (int i = 0; i < n; i++) {
            if (seen.containsKey(target - nums[i])) {
                result = new int[] {seen.get(target - nums[i]), i};
                break;
            } else {
                seen.put(nums[i], i);
            }
        }

        return result;
    }
}