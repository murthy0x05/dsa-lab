class Solution {
    fun isOneBitCharacter(bits: IntArray): Boolean {
        val n: Int = bits.size

        var i: Int = 0
        while (i < n) {
            if (1 == bits[i]) {
                i++
            } else if (i == n - 1) {
                return true
            }
            i++
        }

        return false
    }
}