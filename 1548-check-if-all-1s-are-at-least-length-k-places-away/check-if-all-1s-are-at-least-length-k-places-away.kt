class Solution {
    fun kLengthApart(nums: IntArray, k: Int): Boolean {
        val n: Int = nums.size

        var prev: Int = -100000
        for (i in 0 .. n-1) {
            if (nums[i] == 1) {
                if (i - prev - 1 < k) {
                    return false
                }
                prev = i
            }
        }

        return true;
    }
}