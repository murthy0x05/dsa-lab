class Solution {
    fun hasSameDigits(s: String): Boolean {
        val n = s.length

        val digits: IntArray = IntArray(n) { i -> s[i] - '0' }
        for (i in 0 until n - 2) {
            for (j in 0 until n - i - 1) {
                digits[j] = (digits[j] + digits[j + 1]) % 10
            }
        }

        return digits[0] == digits[1]
    }
}