class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length, result[] = new int[n];
        int prefixProduct = 1;
        int suffixProduct = 1;

        for (int i = 0; i < n; i++) {
            result[i] = prefixProduct;
            prefixProduct *= nums[i];
        }
        for (int i = n-1; i >= 0; i--) {
            result[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        return result;

    }
}