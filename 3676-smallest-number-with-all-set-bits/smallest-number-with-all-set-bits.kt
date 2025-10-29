class Solution {
    fun smallestNumber(n: Int): Int {
        var number: Int = 0
        var p: Long = 1L
        var x = n
        while (x > 0) {
            number += p.toInt()
            x /= 2
            p *= 2
        }

        return number
    }
}