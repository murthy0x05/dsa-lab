import kotlin.math.max
import kotlin.math.min

class Solution {
    val MAX_N = 100_001
    fun maxFrequency(nums: IntArray, k: Int, numOperations: Int): Int {
        val n: Int = nums.size

        val ps: IntArray = IntArray(MAX_N) { 0 }
        for (i in 0 until n) {
            ps[nums[i]]++
        }
        for (i in 1..1e5.toInt()) {
            ps[i] += ps[i - 1]
        }

        var result: Int = 0
        for (i in 1..100_000) {
            val s: Int = max(0, i - k - 1)
            val e: Int = min(100_000, i + k)
            val f: Int = ps[i] - ps[i - 1]
            result = max(result, min(numOperations, ps[e] - ps[s] - f) + f)
        }

        return result 
    }
}