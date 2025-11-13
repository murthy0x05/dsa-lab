class Solution {
    fun maxOperations(s: String): Int {
        val n: Int = s.length

        var ops: Int = 0
        var po: Int = s[0] - '0'
        for (i in 1 until n) {
            if (s[i] == '1') {
                if (s[i] != s[i - 1]) {
                    ops += po
                }
                po++
            }
        }

        return if (s[n - 1] == '1') ops else ops + po
    }
}